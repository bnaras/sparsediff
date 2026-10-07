# Product-reduction atoms

Multiplicative reductions of an expression.

## Usage

``` r
sd_prod(c)
sd_prod_axis_zero(c)
sd_prod_axis_one(c)
```

## Arguments

- c:

  an expression handle.

## Value

An expression handle.

## Details

- `sd_prod`:

  product of all entries.

- `sd_prod_axis_zero`:

  column-wise products (reduce down rows).

- `sd_prod_axis_one`:

  row-wise products (reduce across columns).

## See also

[`sparsediff-affine`](https://bnaras.github.io/sparsediff/reference/sparsediff-affine.md)
