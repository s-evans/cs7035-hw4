#include <cstdlib>
#include <iostream>
#include "gmpxx.h"
#include "fibonacci_test.hpp"
#include "thousand_primes_test.hpp"
#include <assert.h>

// 2) Find the smallest safe prime p >= 3 x 10^15 + 11. [Only test p of the form 12k + 11.]

int main()
{
    // Solution:
    // k = 250000000000009
    // p = 3000000000000119

    static const constexpr unsigned int offset = 11;
    static const constexpr unsigned int step = 12;
    static const mpz_class lower_bound = 3000000000000011_mpz;
    static const mpz_class init_k = ( lower_bound - offset ) / step;

    mpz_class possible_prime = step * init_k + offset;

    for ( mpz_class k = init_k ; true ; ++k, possible_prime += step ) {
        assert( possible_prime >= lower_bound );

        if ( thousand_primes_test( possible_prime ) && fibonacci_test( possible_prime ) ) {
            std::cout << "k = " << k << std::endl;
            std::cout << "p = " << possible_prime << std::endl;
            return EXIT_SUCCESS;
        }
    }

    return EXIT_FAILURE;
}
