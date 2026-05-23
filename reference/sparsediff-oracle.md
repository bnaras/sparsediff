# Sparse derivative oracle

Initialise and evaluate the value, gradient, sparse constraint Jacobian
and sparse lower-triangular Lagrangian Hessian of a problem built with
[`sd_problem`](https://bnaras.github.io/sparsediff/reference/sparsediff-problem.md).

## Arguments

- prob:

  a problem handle from
  [`sd_problem`](https://bnaras.github.io/sparsediff/reference/sparsediff-problem.md).

- u:

  a numeric vector: the primal point at which to evaluate, laid out in
  the engine's column-major flat ordering (the same ordering used by the
  `var_id` offsets passed to
  [`sd_variable`](https://bnaras.github.io/sparsediff/reference/sparsediff-leaves.md)).

- obj_w:

  a scalar weight \\\sigma\\ multiplying the objective Hessian.

- w:

  a numeric vector of constraint multipliers (length equal to the total
  constraint size) weighting the constraint Hessians.

## Value

- `sd_init_derivatives`, `sd_init_jacobian`, `sd_init_jacobian_coo`,
  `sd_init_hessian_coo`:

  called for their side effect; return `NULL` invisibly.

- `sd_objective_forward`:

  the scalar objective value at `u`.

- `sd_constraint_forward`:

  the constraint vector at `u`.

- `sd_gradient`:

  the objective gradient, length `n_vars`.

- `sd_jacobian_sparsity`, `sd_hessian_sparsity`:

  a list with integer `rows`/`cols` (0-based COO indices) and
  `nrow`/`ncol`.

- `sd_jacobian_values`:

  the constraint-Jacobian nonzeros, matching the Jacobian sparsity
  order.

- `sd_hessian_values`:

  the nonzeros of \\\sigma\nabla^2 f + \sum_i w_i \nabla^2 g_i\\, lower
  triangle, matching the Hessian sparsity order.

## Details

Evaluation is ordered: a forward pass first (`sd_objective_forward` /
`sd_constraint_forward`) populates the node values at `u`, after which
`sd_gradient`, `sd_jacobian_values` and `sd_hessian_values` read them.
Sparsity patterns are structural — fixed once the corresponding
`sd_init_*` routine has run — so they are queried once and reused, while
the values are recomputed at each new point. Row and column indices are
0-based (the engine convention; a higher-level modelling layer such as
CVXR translates them to 1-based as needed).

## See also

[`sd_problem`](https://bnaras.github.io/sparsediff/reference/sparsediff-problem.md)
