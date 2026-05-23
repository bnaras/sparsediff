# Leaf expressions: variables and parameters

Create the leaves of an expression graph. A variable is a slice of the
differentiation vector; a parameter is fixed data that can be updated
between evaluations (see
[`sd_register_params`](https://bnaras.github.io/sparsediff/reference/sparsediff-problem.md)).

## Arguments

- d1, d2:

  row and column dimensions of the leaf.

- var_id:

  0-based flat (column-major) offset of this variable's first entry
  within the primal vector `u`.

- param_id:

  0-based parameter offset, analogous to `var_id`.

- n_vars:

  total number of variables in the problem.

- values:

  numeric data for the parameter (length `d1 * d2`, column-major).

## Value

An expression handle.

## See also

[`sparsediff-elementwise`](https://bnaras.github.io/sparsediff/reference/sparsediff-elementwise.md),
[`sd_problem`](https://bnaras.github.io/sparsediff/reference/sparsediff-problem.md)
