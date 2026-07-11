#include "formulas/ramanujan.hpp"
#include <mpfr.h>

void ramanujan(mpfr_t pi, long long int n) {
    mpfr_prec_t prec = mpfr_get_prec(pi);

    mpfr_t sum, term, numer, denom, factor, temp;
    mpfr_t fk, f4k;

    mpfr_inits2(prec,
        sum, term, numer, denom, factor, temp,
        fk, f4k,
        (mpfr_ptr)0
    );

    mpfr_set_zero(sum, 1);

    for (long long int k = 0; k < n; k++) {
        mpfr_fac_ui(f4k, 4 * k, MPFR_RNDN);

        mpfr_fac_ui(fk, k, MPFR_RNDN);

        mpfr_set(numer, f4k, MPFR_RNDN);
        mpfr_mul_ui(numer, numer, 1103 + 26390 * k, MPFR_RNDN);

        mpfr_pow_ui(denom, fk, 4, MPFR_RNDN);

        mpfr_set_ui(temp, 396, MPFR_RNDN);
        mpfr_pow_ui(temp, temp, 4 * k, MPFR_RNDN);

        mpfr_mul(denom, denom, temp, MPFR_RNDN);

        mpfr_div(term, numer, denom, MPFR_RNDN);

        mpfr_add(sum, sum, term, MPFR_RNDN);
    }

    mpfr_sqrt_ui(factor, 2, MPFR_RNDN);
    mpfr_mul_ui(factor, factor, 2, MPFR_RNDN);
    mpfr_div_ui(factor, factor, 9801, MPFR_RNDN);

    mpfr_mul(temp, factor, sum, MPFR_RNDN);
    mpfr_ui_div(pi, 1, temp, MPFR_RNDN);

    mpfr_clears(
        sum, term, numer, denom, factor, temp,
        fk, f4k,
        (mpfr_ptr)0
    );
}