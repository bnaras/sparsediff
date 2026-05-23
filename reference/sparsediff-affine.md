# Affine and shape atoms

Affine combinations and shape manipulations of expressions. These have
constant (zero) second derivatives but participate in the Jacobian.

## Arguments

- left, right, child, c:

  expression handles.

- d1, d2:

  target row and column dimensions (for `sd_promote`, `sd_reshape`,
  `sd_broadcast`, `sd_index`).

- indices:

  0-based column-major flat indices selected by `sd_index`.

- args:

  a list of expression handles to stack (`sd_hstack`, `sd_vstack`).

- n_vars:

  total number of variables in the problem.

- axis:

  reduction axis for `sd_sum`: `-1` (all entries), `0` (down rows) or
  `1` (across columns).

## Value

An expression handle.

## Details

- `sd_add`:

  elementwise sum of two expressions.

- `sd_sum`:

  sum reduction along `axis`.

- `sd_trace`:

  matrix trace.

- `sd_transpose`:

  matrix transpose.

- `sd_diag_vec`:

  diagonal matrix from a vector.

- `sd_diag_mat`:

  diagonal vector from a matrix.

- `sd_upper_tri`:

  the strict upper-triangular entries.

- `sd_promote`:

  promote a scalar to shape `d1 x d2`.

- `sd_reshape`:

  reshape to `d1 x d2` (column-major).

- `sd_broadcast`:

  broadcast to `d1 x d2`.

- `sd_index`:

  select entries by 0-based flat `indices`.

- `sd_hstack`, `sd_vstack`:

  horizontal / vertical stacking.

## See also

[`sparsediff-elementwise`](https://bnaras.github.io/sparsediff/reference/sparsediff-elementwise.md),
[`sparsediff-matrix`](https://bnaras.github.io/sparsediff/reference/sparsediff-matrix.md)
