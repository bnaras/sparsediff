# Expression shape

The dimensions and the number of entries of an expression node (the
'sparsediffpy' `get_expr_dimensions` and `get_expr_size`).

## Usage

``` r
sd_get_expr_dimensions(node)
sd_get_expr_size(node)
```

## Arguments

- node:

  an expression handle.

## Value

`sd_get_expr_dimensions`: an integer vector `c(d1, d2)`, the node's rows
and columns. `sd_get_expr_size`: an integer scalar, the number of
entries `d1 * d2`.

## See also

[`sparsediff-leaves`](https://bnaras.github.io/sparsediff/reference/sparsediff-leaves.md)
