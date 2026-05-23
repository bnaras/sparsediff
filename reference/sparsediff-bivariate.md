# Bivariate atoms

Functions of two expression arguments.

## Arguments

- l, r, x, y:

  expression handles.

## Value

An expression handle.

## Details

- `sd_elementwise_mult`:

  elementwise (Hadamard) product.

- `sd_matmul`:

  matrix product \\x y\\.

- `sd_quad_over_lin`:

  the quadratic-over-linear \\\lVert x \rVert^2 / y\\.

- `sd_rel_entr`:

  elementwise relative entropy \\x \log(x / y)\\.

- `sd_rel_entr_first_scalar`, `sd_rel_entr_second_scalar`:

  relative entropy with a scalar first or second argument broadcast
  against the other.

## See also

[`sparsediff-elementwise`](https://bnaras.github.io/sparsediff/reference/sparsediff-elementwise.md),
[`sparsediff-reduction`](https://bnaras.github.io/sparsediff/reference/sparsediff-reduction.md)
