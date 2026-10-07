# Parameter- and constant-matrix atoms

Operations that combine an expression with fixed data — a registered
parameter node or a constant matrix — so the data can flow through the
differentiated graph (and, for parameters, be updated between
evaluations).

## Usage

``` r
sd_scalar_mult(param, child)
sd_vector_mult(param, child)
sd_convolve(param, child)
sd_quad_form(child, Qp, Qi, Qx)
sd_quad_form_dense(param, child, data)
sd_left_matmul(child, Ap, Ai, Ax, ncol)
sd_right_matmul(child, Ap, Ai, Ax, ncol)
sd_left_matmul_dense(param, child, m, n, data)
sd_right_matmul_dense(param, child, m, n, data)
sd_left_kron(param, child, p, q, r, s, active_blocks)
sd_right_kron(param, child, p, q, r, s, active_blocks)
```

## Arguments

- param:

  a parameter expression handle (see
  [`sd_parameter`](https://bnaras.github.io/sparsediff/reference/sparsediff-leaves.md)).

- child:

  an expression handle (the variable argument).

- Qp, Qi, Qx:

  the row-pointer, column-index and value arrays of a
  compressed-sparse-row (CSR) matrix \\Q\\ for `sd_quad_form`'s \\x^\top
  Q x\\. \\Q\\ must be symmetric, so its CSR arrays equal its
  compressed-sparse-column arrays and the `@p`, `@i`, `@x` slots of a
  `Matrix::dgCMatrix` holding \\Q\\ can be passed directly.

- Ap, Ai, Ax:

  the row-pointer, column-index and value arrays of a constant matrix
  \\A\\ in compressed-sparse-row (CSR) form, for the sparse matrix
  products. These are the `@p`, `@i`, `@x` slots of a
  `Matrix::dgCMatrix` holding \\A^\top\\, not \\A\\.

- ncol:

  number of columns of the sparse constant matrix \\A\\.

- m, n:

  row and column dimensions of the dense constant matrix.

- p, q, r, s:

  for the Kronecker products \\Z = A \otimes B\\: \\A\\ is \\p \times
  q\\ and \\B\\ is \\r \times s\\.

- active_blocks:

  for the Kronecker products, an integer vector of 0-based column-major
  indices of the nonzero entries of the variable-free operand (`param`);
  only the output rows they cover are built. For a parametric operand
  pass every index, `0:(length - 1)`.

- data:

  the dense constant-matrix entries in row-major order (length `m * n`
  for the matrix products, `n * n` for `sd_quad_form_dense`); for an R
  matrix `M`, pass `as.vector(t(M))`. Pass `numeric(0)` when the matrix
  comes from `param`.

## Value

An expression handle.

## Details

- `sd_scalar_mult`, `sd_vector_mult`:

  multiply a child by a scalar / vector parameter.

- `sd_convolve`:

  convolution of a parameter kernel with a child.

- `sd_quad_form`:

  the quadratic form \\x^\top Q x\\ with sparse constant \\Q\\.

- `sd_quad_form_dense`:

  the quadratic form \\x^\top Q x\\ with a dense symmetric \\n \times
  n\\ \\Q\\, where \\n\\ is the length of the vector `child`. Supply
  exactly one source: `param = NULL` and `data` for a constant \\Q\\
  (checked for symmetry), or a parameter handle of size \\n^2\\ with
  `data = numeric(0)` for a parametric \\Q\\ that follows
  [`sd_update_params`](https://bnaras.github.io/sparsediff/reference/sparsediff-problem.md).
  A parametric \\Q\\ is not checked: keeping it symmetric is the
  caller's responsibility.

- `sd_left_matmul`, `sd_right_matmul`:

  left / right product with a sparse constant matrix \\A\\.

- `sd_left_matmul_dense`, `sd_right_matmul_dense`:

  left / right product with a dense constant or parametric matrix.

- `sd_left_kron`, `sd_right_kron`:

  the Kronecker product \\A \otimes B\\ with the variable-free operand
  `param` on the left (\\A\\) or on the right (\\B\\) and the variable
  operand `child` on the other side. `param` may be a parameter or a
  constant made with `sd_parameter(..., param_id = -1, ...)`.

A parameter cannot be the source of the sparse products `sd_left_matmul`
/ `sd_right_matmul` (the engine does not support it; 'sparsediffpy'
accepts the argument but the engine then aborts); use the dense products
for a parametric matrix.

## See also

[`sd_parameter`](https://bnaras.github.io/sparsediff/reference/sparsediff-leaves.md),
[`sd_register_params`](https://bnaras.github.io/sparsediff/reference/sparsediff-problem.md)
