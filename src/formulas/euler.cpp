#include "formulas/euler.hpp"
#include <mpfr.h>

void euler(mpfr_t pi, long long int n) {
    mpfr_prec_t prec = mpfr_get_prec(pi);

    mpfr_t sum, term;
    mpfr_init2(sum, prec);
    mpfr_init2(term, prec);

    mpfr_set_zero(sum, 1);

    for (long long int k = 1; k <= n; k++) {
        mpfr_set_si(term, k, MPFR_RNDN);
        mpfr_mul(term, term, term, MPFR_RNDN);
        mpfr_ui_div(term, 1, term, MPFR_RNDN);

        mpfr_add(sum, sum, term, MPFR_RNDN);
    }

    mpfr_mul_ui(sum, sum, 6, MPFR_RNDN);
    mpfr_sqrt(pi, sum, MPFR_RNDN);

    mpfr_clear(sum);
    mpfr_clear(term);
}