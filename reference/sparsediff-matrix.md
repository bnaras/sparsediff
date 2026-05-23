# Parameter- and constant-matrix atoms

Operations that combine an expression with fixed data — a registered
parameter node or a constant matrix — so the data can flow through the
differentiated graph (and, for parameters, be updated between
evaluations).

## Arguments

- param:

  a parameter expression handle (see
  [`sd_parameter`](https://bnaras.github.io/sparsediff/reference/sparsediff-leaves.md)).

- child:

  an expression handle (the variable argument).

- Qp, Qi, Qx:

  the column-pointer, row-index and value arrays of a
  compressed-sparse-column matrix \\Q\\ (as in a `Matrix::dgCMatrix`:
  `@p`, `@i`, `@x`) for `sd_quad_form`'s \\x^\top Q x\\.

- Ap, Ai, Ax:

  the compressed-sparse-column arrays of a constant matrix \\A\\ for the
  sparse matrix products.

- ncol:

  number of columns of the sparse constant matrix \\A\\.

- m, n:

  row and column dimensions of the dense constant matrix.

- data:

  the dense constant-matrix entries (length `m * n`, column-major).

## Value

An expression handle.

## Details

- `sd_scalar_mult`, `sd_vector_mult`:

  multiply a child by a scalar / vector parameter.

- `sd_convolve`:

  convolution of a parameter kernel with a child.

- `sd_quad_form`:

  the quadratic form \\x^\top Q x\\ with sparse constant \\Q\\.

- `sd_left_matmul`, `sd_right_matmul`:

  left / right product with a sparse constant matrix \\A\\.

- `sd_left_matmul_dense`, `sd_right_matmul_dense`:

  left / right product with a dense constant matrix.

## See also

[`sd_parameter`](https://bnaras.github.io/sparsediff/reference/sparsediff-leaves.md),
[`sd_register_params`](https://bnaras.github.io/sparsediff/reference/sparsediff-problem.md)
