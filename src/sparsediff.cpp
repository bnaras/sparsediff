// sparsediff: cpp11 bindings to the SparseDiffEngine C library.
//
// The engine is pure C, so its headers are included inside extern "C". Engine
// `expr` (expression-DAG node) and `problem` objects are opaque foreign handles,
// so they cross the R boundary as SEXP external pointers (cpp11 cannot see the
// engine types in the generated cpp11.cpp, so we use SEXP rather than
// cpp11::external_pointer for these). cpp11 still handles the scalar/vector
// arguments, return vectors, error unwinding, and routine registration.
//
// Memory model. Engine nodes start at refcount 0 (init_expr); each parent and
// new_problem() expr_retain()s the nodes it references; free_expr() decrements
// and, at <= 0, frees the node and recurses into its children. So each R
// external pointer holds exactly ONE reference: wrap_expr() retains on wrap and
// the registered finalizer (free_expr) releases on GC -- a balanced +1/-1 per
// handle. Because engine constructors retain their own children, freeing the
// last owner cleans up the whole DAG exactly once, in any order.

#include <cpp11.hpp>
#include <string>
#include <vector>

extern "C" {
#include "problem.h"                      // pulls in expr.h
#include "atoms/affine.h"                 // new_variable, new_add, new_neg, new_sum
#include "atoms/elementwise_full_dom.h"   // new_exp
}
#include "sparsediff_cblas.h"             // self-guarded extern "C"

#ifndef DIFF_ENGINE_VERSION
#define DIFF_ENGINE_VERSION "unknown"
#endif

using namespace cpp11;

// ---------------------------------------------------------------------------
//  external-pointer helpers for the opaque engine handles
// ---------------------------------------------------------------------------
static void expr_xp_finalizer(SEXP xp) {
  expr* p = static_cast<expr*>(R_ExternalPtrAddr(xp));
  if (p != nullptr) { free_expr(p); R_ClearExternalPtr(xp); }
}
static void problem_xp_finalizer(SEXP xp) {
  problem* p = static_cast<problem*>(R_ExternalPtrAddr(xp));
  if (p != nullptr) { free_problem(p); R_ClearExternalPtr(xp); }
}

static SEXP wrap_expr(expr* node) {
  if (node == nullptr) stop("sparsediff: engine returned a NULL expression");
  expr_retain(node);  // this R handle owns one reference
  SEXP xp = PROTECT(R_MakeExternalPtr(node, R_NilValue, R_NilValue));
  R_RegisterCFinalizerEx(xp, expr_xp_finalizer, TRUE);
  UNPROTECT(1);
  return xp;
}
static SEXP wrap_problem(problem* p) {
  if (p == nullptr) stop("sparsediff: engine returned a NULL problem");
  SEXP xp = PROTECT(R_MakeExternalPtr(p, R_NilValue, R_NilValue));
  R_RegisterCFinalizerEx(xp, problem_xp_finalizer, TRUE);
  UNPROTECT(1);
  return xp;
}
static expr* as_expr(SEXP xp) {
  expr* p = static_cast<expr*>(R_ExternalPtrAddr(xp));
  if (p == nullptr) stop("sparsediff: NULL or finalized expression pointer");
  return p;
}
static problem* as_problem(SEXP xp) {
  problem* p = static_cast<problem*>(R_ExternalPtrAddr(xp));
  if (p == nullptr) stop("sparsediff: NULL or finalized problem pointer");
  return p;
}

// ---------------------------------------------------------------------------
//  diagnostics
// ---------------------------------------------------------------------------
[[cpp11::register]]
std::string sd_engine_version() { return std::string(DIFF_ENGINE_VERSION); }

// Self-test of the CBLAS->Fortran-BLAS shim: row-major C(2x2)=A(2x3)B(3x2).
[[cpp11::register]]
doubles sd_selftest_dgemm() {
  const double A[6] = {1, 2, 3, 4, 5, 6};
  const double B[6] = {7, 8, 9, 10, 11, 12};
  double C[4] = {0, 0, 0, 0};
  cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
              2, 2, 3, 1.0, A, 3, B, 2, 0.0, C, 2);
  writable::doubles out(4);
  for (int i = 0; i < 4; i++) out[i] = C[i];
  return out;
}

// ---------------------------------------------------------------------------
//  expression-DAG constructors
//  (var_id is the 0-based offset of the variable's block in the flat input
//   vector u of length n_vars; axis is the engine convention: -1 = all,
//   0 = sum rows, 1 = sum columns.)
// ---------------------------------------------------------------------------
[[cpp11::register]]
SEXP sd_variable(int d1, int d2, int var_id, int n_vars) {
  return wrap_expr(new_variable(d1, d2, var_id, n_vars));
}

[[cpp11::register]]
SEXP sd_exp(SEXP child) { return wrap_expr(new_exp(as_expr(child))); }

[[cpp11::register]]
SEXP sd_neg(SEXP child) { return wrap_expr(new_neg(as_expr(child))); }

[[cpp11::register]]
SEXP sd_add(SEXP left, SEXP right) {
  return wrap_expr(new_add(as_expr(left), as_expr(right)));
}

[[cpp11::register]]
SEXP sd_sum(SEXP child, int axis) {
  return wrap_expr(new_sum(as_expr(child), axis));
}

// ---------------------------------------------------------------------------
//  problem construction & evaluation
// ---------------------------------------------------------------------------
[[cpp11::register]]
SEXP sd_problem(SEXP objective, list constraints, bool verbose) {
  int nc = static_cast<int>(constraints.size());
  std::vector<expr*> cons;
  cons.reserve(nc);
  for (int i = 0; i < nc; i++) {
    SEXP s = constraints[i];
    cons.push_back(as_expr(s));
  }
  return wrap_problem(
      new_problem(as_expr(objective), nc ? cons.data() : nullptr, nc, verbose));
}

[[cpp11::register]]
void sd_init_jacobian(SEXP prob) { problem_init_jacobian(as_problem(prob)); }

[[cpp11::register]]
void sd_init_derivatives(SEXP prob) { problem_init_derivatives(as_problem(prob)); }

[[cpp11::register]]
double sd_objective_forward(SEXP prob, doubles u) {
  std::vector<double> ubuf(u.begin(), u.end());
  return problem_objective_forward(as_problem(prob), ubuf.data());
}

[[cpp11::register]]
doubles sd_gradient(SEXP prob) {
  problem* p = as_problem(prob);
  problem_gradient(p);
  writable::doubles g(p->n_vars);
  for (int i = 0; i < p->n_vars; i++) g[i] = p->gradient_values[i];
  return g;
}
