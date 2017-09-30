#include <cstdlib>
#include <iostream>
#include "gmpxx.h"
#include "fermat_test.hpp"

// 1) Factor the number n using the p – 1 factoring method, where
// n = 190 248 273 382 547 686 244 479 775 579 416 295 505 415 044 511.
// Here n=pq, where p and q are prime and p-1 is 37-smooth.

int main()
{
    // TODO: implement and solve
    static const mpz_class n = 190248273382547686244479775579416295505415044511_mpz;

    return EXIT_SUCCESS;
}
