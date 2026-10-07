# Elementwise atoms

Smooth elementwise functions of a single expression. Each returns an
expression of the same shape as its argument.

## Usage

``` r
sd_exp(child)
sd_log(c)
sd_sin(c)
sd_cos(c)
sd_tan(c)
sd_sinh(c)
sd_tanh(c)
sd_asinh(c)
sd_atanh(c)
sd_logistic(c)
sd_xexp(c)
sd_normal_cdf(c)
sd_entr(c)
sd_power(c, p)
sd_neg(child)
```

## Arguments

- child, c:

  an expression handle (the argument).

- p:

  exponent for `sd_power`.

## Value

An expression handle.

## Details

- `sd_exp`, `sd_log`:

  exponential and natural logarithm.

- `sd_sin`, `sd_cos`, `sd_tan`:

  trigonometric functions.

- `sd_sinh`, `sd_tanh`, `sd_asinh`, `sd_atanh`:

  hyperbolic and inverse-hyperbolic functions.

- `sd_logistic`:

  the logistic \\\log(1 + e^x)\\.

- `sd_xexp`:

  \\x e^x\\.

- `sd_normal_cdf`:

  the standard normal CDF.

- `sd_entr`:

  the elementwise entropy \\-x \log x\\.

- `sd_power`:

  the power \\x^p\\.

- `sd_neg`:

  negation \\-x\\.

## See also

[`sparsediff-affine`](https://bnaras.github.io/sparsediff/reference/sparsediff-affine.md),
[`sparsediff-bivariate`](https://bnaras.github.io/sparsediff/reference/sparsediff-bivariate.md)
