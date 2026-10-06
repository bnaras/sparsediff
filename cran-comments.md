## Submission

This release updates the bundled SparseDiffEngine C library from 0.3.0 to 0.6.1.
The package version moves from 0.4.0 to 0.6.1 so that it matches the bundled
engine version from now on; there are no releases in between.

The update fixes a crash (bus error) and a silently wrong result after a
parameter update, both in the bundled engine, and a compile failure on Linux
systems with glibc 2.36 or older.

## Test environments

* local macOS (aarch64), R 4.6.1: `R CMD check --as-cran`
* Debian 12 (glibc 2.36, gcc 12), R 4.2.2: `R CMD check`; also an
  AddressSanitizer build of the package running the test suite
* rocker/r-devel-san (x86_64, gcc UBSAN), R-devel: `R CMD check --as-cran`
* win-builder: to be run before upload

## R CMD check results

0 errors | 0 warnings | 0 notes on local macOS.

The Debian 12 and r-devel-san containers reported only findings about the
containers themselves (no locale, pandoc, checkbashisms, knitr or rmarkdown
installed there). No sanitizer reports.

## Downstream dependencies

None on CRAN. 'CVXR' lists 'sparsediff' in Enhances.
