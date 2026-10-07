# sparsediff: R interface to the SparseDiffEngine differentiation backend

R bindings to the 'SparseDiffEngine' C library — the sparse Jacobian and
Hessian differentiation backend used by 'CVXPY' for its Disciplined
Nonlinear Programming (DNLP) extension. This package is the R analog of
the 'sparsediffpy' Python package and wraps the same C library (pinned
at the upstream v0.6.1 release).

## Correspondence with 'sparsediffpy'

Every 'sparsediffpy' 0.6.1 function has an `sd_*` counterpart that calls
the same engine routine with the same arguments in the same order. Names
map `make_<atom>` to `sd_<atom>` and `problem_<step>` to `sd_<step>`
(for example `make_exp` to `sd_exp`, `problem_init_jacobian` to
`sd_init_jacobian`), with these exceptions:

- `make_multiply`: `sd_elementwise_mult`; `make_param_scalar_mult` /
  `make_param_vector_mult`: `sd_scalar_mult` / `sd_vector_mult`.

- `make_left_matmul`, `make_right_matmul` and `make_quad_form`, which
  take a format string, are split by format: `"sparse"` is
  `sd_left_matmul`, `sd_right_matmul`, `sd_quad_form`; `"dense"` is
  `sd_left_matmul_dense`, `sd_right_matmul_dense`, `sd_quad_form_dense`.

- `make_rel_entr`: `sd_rel_entr`, which dispatches on operand size the
  same way; the two scalar cases are also available directly as
  `sd_rel_entr_first_scalar` and `sd_rel_entr_second_scalar`.

- `get_jacobian_sparsity_coo`, `problem_eval_jacobian_vals`:
  `sd_jacobian_sparsity`, `sd_jacobian_values`;
  `problem_init_hessian_coo_lower_triangular`,
  `get_problem_hessian_sparsity_coo`, `problem_eval_hessian_vals_coo`:
  `sd_init_hessian_coo`, `sd_hessian_sparsity`, `sd_hessian_values`;
  `get_jacobian`, `get_hessian`, `get_expr_dimensions`, `get_expr_size`:
  `sd_get_jacobian`, `sd_get_hessian`, `sd_get_expr_dimensions`,
  `sd_get_expr_size`.

- Arguments that are optional in 'sparsediffpy' are required here (R
  stubs have no defaults): `verbose` of `sd_problem`, `values` of
  `sd_parameter` (the engine requires it anyway), and `n_vars` of
  `sd_hstack` / `sd_vstack`, which 'sparsediffpy' takes from the first
  argument.

- The parameter argument of the sparse matrix products is not exposed:
  the engine aborts on it.

Indices are 0-based as in 'sparsediffpy'. CSR results are a list with
`data`, `indices`, `indptr` and `shape`, the pieces of its
`(data, indices, indptr, (m, n))` tuple.

## See also

Useful links:

- <https://bnaras.github.io/sparsediff/>

- <https://github.com/bnaras/sparsediff>

- Report bugs at <https://github.com/bnaras/sparsediff/issues>

## Author

**Maintainer**: Balasubramanian Narasimhan <naras@stanford.edu>

Authors:

- Balasubramanian Narasimhan <naras@stanford.edu>

- Daniel Cederberg (Author of the bundled SparseDiffEngine C library)
  \[copyright holder\]

- William Zijie Zhang (Author of the bundled SparseDiffEngine C library)
  \[copyright holder\]
