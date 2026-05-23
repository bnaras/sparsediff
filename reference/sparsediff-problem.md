# Assemble a differentiable problem

Combine an objective expression and a list of constraint expressions
(built with the `sd_*` atom constructors) into a single problem object
whose value and sparse derivatives can be evaluated repeatedly.

## Arguments

- objective:

  an expression handle for the scalar objective.

- constraints:

  a list of expression handles, stacked vertically to form the
  constraint vector \\g(x)\\ (may be empty).

- verbose:

  logical; if `TRUE`, print diagnostic information while the problem is
  assembled.

- prob:

  a problem handle returned by `sd_problem()`.

- params:

  a list of parameter expression handles (see
  [`sd_parameter`](https://bnaras.github.io/sparsediff/reference/sparsediff-leaves.md))
  to register for fast re-evaluation under changing data.

- theta:

  a numeric vector of new parameter values, concatenated in the order
  the parameters were registered.

## Value

`sd_problem()` returns an external-pointer problem handle. The handle
owns the underlying expression graph and frees it when garbage
collected. `sd_register_params()` and `sd_update_params()` are called
for their side effect and return `NULL` invisibly.

## Details

The typical lifecycle is: build expressions with the `sd_*`
constructors, assemble them with `sd_problem()`, initialise the
derivative structures once
([`sd_init_derivatives`](https://bnaras.github.io/sparsediff/reference/sparsediff-oracle.md)
and friends), then evaluate the objective/constraints and their sparse
derivatives at as many primal points as needed. When the problem has
parameters, register them once with `sd_register_params()` and push new
values with `sd_update_params()` to re-evaluate without rebuilding the
graph (the DPP-style fast path).

## See also

[`sd_init_derivatives`](https://bnaras.github.io/sparsediff/reference/sparsediff-oracle.md)
for the evaluation oracle,
[`sd_variable`](https://bnaras.github.io/sparsediff/reference/sparsediff-leaves.md)
and the atom constructors for building expressions.
