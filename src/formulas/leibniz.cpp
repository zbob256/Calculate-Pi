#include "formulas/leibniz.hpp"
#include <mpfr.h>

void leibniz(mpfr_t pi, long long int n) {
    mpfr_prec_t prec = mpfr_get_prec(pi);

    mpfr_t sum, term;
    mpfr_init2(sum, prec);
    mpfr_init2(term, prec);

    mpfr_set_zero(sum, 1);

    for (int k = 0; k < n; k++) {
        mpfr_set_ui(term, 2 * k + 1, MPFR_RNDN);
        mpfr_ui_div(term, 1, term, MPFR_RNDN);

        if (k & 1) mpfr_neg(term, term, MPFR_RNDN);

        mpfr_add(sum, sum, term, MPFR_RNDN);
    }

    mpfr_mul_ui(pi, sum, 4, MPFR_RNDN);

    mpfr_clear(sum);
    mpfr_clear(term);
}