#include "formulas/wallis.hpp"
#include <mpfr.h>

void wallis(mpfr_t pi, long long int n) {
    mpfr_prec_t prec = mpfr_get_prec(pi);

    mpfr_t product, term, numerator, denominator;
    mpfr_init2(product, prec);
    mpfr_init2(term, prec);
    mpfr_init2(numerator, prec);
    mpfr_init2(denominator, prec);

    mpfr_set_ui(product, 1, MPFR_RNDN);

    for (long long int k = 1; k <= n; k++) {
        mpfr_set_si(numerator, k, MPFR_RNDN);
        mpfr_mul(numerator, numerator, numerator, MPFR_RNDN);
        mpfr_mul_ui(numerator, numerator, 4, MPFR_RNDN);

        mpfr_sub_ui(denominator, numerator, 1, MPFR_RNDN);

        mpfr_div(term, numerator, denominator, MPFR_RNDN);

        mpfr_mul(product, product, term, MPFR_RNDN);
    }

    mpfr_mul_ui(pi, product, 2, MPFR_RNDN);

    mpfr_clear(product);
    mpfr_clear(term);
    mpfr_clear(numerator);
    mpfr_clear(denominator);
}