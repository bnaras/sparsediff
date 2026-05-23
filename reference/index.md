# Package index

## Package

- [`sparsediff`](https://bnaras.github.io/sparsediff/reference/sparsediff-package.md)
  [`sparsediff-package`](https://bnaras.github.io/sparsediff/reference/sparsediff-package.md)
  : sparsediff: R interface to the SparseDiffEngine differentiation
  backend
- [`engine_version()`](https://bnaras.github.io/sparsediff/reference/engine_version.md)
  : Bundled SparseDiffEngine version

## Building expressions

Construct the leaves and atoms of a nonlinear differentiation graph.
Each constructor returns an expression handle.

- [`sparsediff-leaves`](https://bnaras.github.io/sparsediff/reference/sparsediff-leaves.md)
  [`sd_variable`](https://bnaras.github.io/sparsediff/reference/sparsediff-leaves.md)
  [`sd_parameter`](https://bnaras.github.io/sparsediff/reference/sparsediff-leaves.md)
  : Leaf expressions: variables and parameters
- [`sparsediff-elementwise`](https://bnaras.github.io/sparsediff/reference/sparsediff-elementwise.md)
  [`sd_exp`](https://bnaras.github.io/sparsediff/reference/sparsediff-elementwise.md)
  [`sd_log`](https://bnaras.github.io/sparsediff/reference/sparsediff-elementwise.md)
  [`sd_sin`](https://bnaras.github.io/sparsediff/reference/sparsediff-elementwise.md)
  [`sd_cos`](https://bnaras.github.io/sparsediff/reference/sparsediff-elementwise.md)
  [`sd_tan`](https://bnaras.github.io/sparsediff/reference/sparsediff-elementwise.md)
  [`sd_sinh`](https://bnaras.github.io/sparsediff/reference/sparsediff-elementwise.md)
  [`sd_tanh`](https://bnaras.github.io/sparsediff/reference/sparsediff-elementwise.md)
  [`sd_asinh`](https://bnaras.github.io/sparsediff/reference/sparsediff-elementwise.md)
  [`sd_atanh`](https://bnaras.github.io/sparsediff/reference/sparsediff-elementwise.md)
  [`sd_logistic`](https://bnaras.github.io/sparsediff/reference/sparsediff-elementwise.md)
  [`sd_xexp`](https://bnaras.github.io/sparsediff/reference/sparsediff-elementwise.md)
  [`sd_normal_cdf`](https://bnaras.github.io/sparsediff/reference/sparsediff-elementwise.md)
  [`sd_entr`](https://bnaras.github.io/sparsediff/reference/sparsediff-elementwise.md)
  [`sd_power`](https://bnaras.github.io/sparsediff/reference/sparsediff-elementwise.md)
  [`sd_neg`](https://bnaras.github.io/sparsediff/reference/sparsediff-elementwise.md)
  : Elementwise atoms
- [`sparsediff-affine`](https://bnaras.github.io/sparsediff/reference/sparsediff-affine.md)
  [`sd_add`](https://bnaras.github.io/sparsediff/reference/sparsediff-affine.md)
  [`sd_sum`](https://bnaras.github.io/sparsediff/reference/sparsediff-affine.md)
  [`sd_trace`](https://bnaras.github.io/sparsediff/reference/sparsediff-affine.md)
  [`sd_transpose`](https://bnaras.github.io/sparsediff/reference/sparsediff-affine.md)
  [`sd_diag_vec`](https://bnaras.github.io/sparsediff/reference/sparsediff-affine.md)
  [`sd_diag_mat`](https://bnaras.github.io/sparsediff/reference/sparsediff-affine.md)
  [`sd_upper_tri`](https://bnaras.github.io/sparsediff/reference/sparsediff-affine.md)
  [`sd_promote`](https://bnaras.github.io/sparsediff/reference/sparsediff-affine.md)
  [`sd_reshape`](https://bnaras.github.io/sparsediff/reference/sparsediff-affine.md)
  [`sd_broadcast`](https://bnaras.github.io/sparsediff/reference/sparsediff-affine.md)
  [`sd_index`](https://bnaras.github.io/sparsediff/reference/sparsediff-affine.md)
  [`sd_hstack`](https://bnaras.github.io/sparsediff/reference/sparsediff-affine.md)
  [`sd_vstack`](https://bnaras.github.io/sparsediff/reference/sparsediff-affine.md)
  : Affine and shape atoms
- [`sparsediff-bivariate`](https://bnaras.github.io/sparsediff/reference/sparsediff-bivariate.md)
  [`sd_elementwise_mult`](https://bnaras.github.io/sparsediff/reference/sparsediff-bivariate.md)
  [`sd_matmul`](https://bnaras.github.io/sparsediff/reference/sparsediff-bivariate.md)
  [`sd_quad_over_lin`](https://bnaras.github.io/sparsediff/reference/sparsediff-bivariate.md)
  [`sd_rel_entr`](https://bnaras.github.io/sparsediff/reference/sparsediff-bivariate.md)
  [`sd_rel_entr_first_scalar`](https://bnaras.github.io/sparsediff/reference/sparsediff-bivariate.md)
  [`sd_rel_entr_second_scalar`](https://bnaras.github.io/sparsediff/reference/sparsediff-bivariate.md)
  : Bivariate atoms
- [`sparsediff-reduction`](https://bnaras.github.io/sparsediff/reference/sparsediff-reduction.md)
  [`sd_prod`](https://bnaras.github.io/sparsediff/reference/sparsediff-reduction.md)
  [`sd_prod_axis_zero`](https://bnaras.github.io/sparsediff/reference/sparsediff-reduction.md)
  [`sd_prod_axis_one`](https://bnaras.github.io/sparsediff/reference/sparsediff-reduction.md)
  : Product-reduction atoms
- [`sparsediff-matrix`](https://bnaras.github.io/sparsediff/reference/sparsediff-matrix.md)
  [`sd_scalar_mult`](https://bnaras.github.io/sparsediff/reference/sparsediff-matrix.md)
  [`sd_vector_mult`](https://bnaras.github.io/sparsediff/reference/sparsediff-matrix.md)
  [`sd_convolve`](https://bnaras.github.io/sparsediff/reference/sparsediff-matrix.md)
  [`sd_quad_form`](https://bnaras.github.io/sparsediff/reference/sparsediff-matrix.md)
  [`sd_left_matmul`](https://bnaras.github.io/sparsediff/reference/sparsediff-matrix.md)
  [`sd_right_matmul`](https://bnaras.github.io/sparsediff/reference/sparsediff-matrix.md)
  [`sd_left_matmul_dense`](https://bnaras.github.io/sparsediff/reference/sparsediff-matrix.md)
  [`sd_right_matmul_dense`](https://bnaras.github.io/sparsediff/reference/sparsediff-matrix.md)
  : Parameter- and constant-matrix atoms

## Problems and sparse derivatives

Assemble expressions into a problem and evaluate its value, gradient,
sparse Jacobian and lower-triangular Lagrangian Hessian.

- [`sparsediff-problem`](https://bnaras.github.io/sparsediff/reference/sparsediff-problem.md)
  [`sd_problem`](https://bnaras.github.io/sparsediff/reference/sparsediff-problem.md)
  [`sd_register_params`](https://bnaras.github.io/sparsediff/reference/sparsediff-problem.md)
  [`sd_update_params`](https://bnaras.github.io/sparsediff/reference/sparsediff-problem.md)
  : Assemble a differentiable problem
- [`sparsediff-oracle`](https://bnaras.github.io/sparsediff/reference/sparsediff-oracle.md)
  [`sd_init_derivatives`](https://bnaras.github.io/sparsediff/reference/sparsediff-oracle.md)
  [`sd_init_jacobian`](https://bnaras.github.io/sparsediff/reference/sparsediff-oracle.md)
  [`sd_init_jacobian_coo`](https://bnaras.github.io/sparsediff/reference/sparsediff-oracle.md)
  [`sd_init_hessian_coo`](https://bnaras.github.io/sparsediff/reference/sparsediff-oracle.md)
  [`sd_objective_forward`](https://bnaras.github.io/sparsediff/reference/sparsediff-oracle.md)
  [`sd_constraint_forward`](https://bnaras.github.io/sparsediff/reference/sparsediff-oracle.md)
  [`sd_gradient`](https://bnaras.github.io/sparsediff/reference/sparsediff-oracle.md)
  [`sd_jacobian_sparsity`](https://bnaras.github.io/sparsediff/reference/sparsediff-oracle.md)
  [`sd_jacobian_values`](https://bnaras.github.io/sparsediff/reference/sparsediff-oracle.md)
  [`sd_hessian_sparsity`](https://bnaras.github.io/sparsediff/reference/sparsediff-oracle.md)
  [`sd_hessian_values`](https://bnaras.github.io/sparsediff/reference/sparsediff-oracle.md)
  : Sparse derivative oracle
