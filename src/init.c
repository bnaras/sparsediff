/* sparsediff: native-routine registration and a minimal smoke entry point.
 *
 * C_engine_version() returns the bundled SparseDiffEngine version (the
 * DIFF_ENGINE_VERSION macro set in Makevars / by the upstream CMake). It exists
 * to verify the build links the engine and loads as an R shared object before
 * the full set of expression/problem wrappers is added.
 */
#include <R.h>
#include <Rinternals.h>
#include <R_ext/Rdynload.h>

#include "sparsediff_cblas.h"

#ifndef DIFF_ENGINE_VERSION
#define DIFF_ENGINE_VERSION "unknown"
#endif

SEXP C_engine_version(void) {
    return Rf_mkString(DIFF_ENGINE_VERSION);
}

/* Self-test of the CBLAS->Fortran-BLAS shim: row-major C(2x2) = A(2x3) B(3x2),
 * A = [[1,2,3],[4,5,6]], B = [[7,8],[9,10],[11,12]] => [[58,64],[139,154]].
 * Returns the 4 entries in row-major order so R can verify the translation. */
SEXP C_selftest_dgemm(void) {
    const double A[6] = {1, 2, 3, 4, 5, 6};
    const double B[6] = {7, 8, 9, 10, 11, 12};
    SEXP out = PROTECT(Rf_allocVector(REALSXP, 4));
    double *C = REAL(out);
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans,
                2, 2, 3, 1.0, A, 3, B, 2, 0.0, C, 2);
    UNPROTECT(1);
    return out;
}

static const R_CallMethodDef CallEntries[] = {
    {"C_engine_version", (DL_FUNC) &C_engine_version, 0},
    {"C_selftest_dgemm", (DL_FUNC) &C_selftest_dgemm, 0},
    {NULL, NULL, 0}
};

void R_init_sparsediff(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
