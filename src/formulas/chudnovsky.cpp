#include "formulas/chudnovsky.hpp"
#include <mpfr.h>

void chudnovsky(mpfr_t pi, long long int n) {
    mpfr_prec_t prec = mpfr_get_prec(pi);

    mpfr_t sum, term, numer, denom, temp;
    mpfr_t f6k, f3k, fk, constant;

    mpfr_inits2(prec,
        sum, term, numer, denom, temp,
        f6k, f3k, fk, constant,
        (mpfr_ptr)0
    );

    mpfr_set_zero(sum, 1);

    for (long long int k = 0; k < n; k++) {
        mpfr_fac_ui(f6k, 6 * k, MPFR_RNDN);
        mpfr_fac_ui(f3k, 3 * k, MPFR_RNDN);
        mpfr_fac_ui(fk, k, MPFR_RNDN);

        mpfr_set(numer, f6k, MPFR_RNDN);
        mpfr_mul_ui(numer, numer, 13591409ULL + 545140134ULL * k, MPFR_RNDN);

        mpfr_pow_ui(denom, fk, 3, MPFR_RNDN);
        mpfr_mul(denom, denom, f3k, MPFR_RNDN);

        mpfr_set_ui(temp, 640320, MPFR_RNDN);
        mpfr_pow_ui(temp, temp, 3 * k, MPFR_RNDN);

        mpfr_mul(denom, denom, temp, MPFR_RNDN);

        mpfr_div(term, numer, denom, MPFR_RNDN);

        if (k & 1) mpfr_neg(term, term, MPFR_RNDN);

        mpfr_add(sum, sum, term, MPFR_RNDN);
    }

    mpfr_sqrt_ui(constant, 10005, MPFR_RNDN);
    mpfr_mul_ui(constant, constant, 426880, MPFR_RNDN);

    mpfr_div(pi, constant, sum, MPFR_RNDN);

    mpfr_clears(
        sum, term, numer, denom, temp,
        f6k, f3k, fk, constant,
        (mpfr_ptr)0
    );
}