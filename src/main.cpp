#include <iostream>
#include <mpfr.h>
#include "formulas.hpp"

const long long int TERMS = 1000;
const int PRECISION = 5000;

int main() {
    mpfr_t pi;
    mpfr_init2(pi, PRECISION);

    // leibniz(pi, TERMS);
    // wallis(pi, TERMS);
    // euler(pi, TERMS);
    // ramanujan(pi, TERMS);
    chudnovsky(pi, TERMS);

    mpfr_printf("%.5000Rf\n", pi);

    return 0;
}