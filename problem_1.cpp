#include <cstdlib>
#include <iostream>
#include "gmpxx.h"
#include "pollard_p_minus_one_factorization.hpp"
#include "thousand_primes_test.hpp"
#include "fibonacci_test.hpp"

// 1) Factor the number n using the p – 1 factoring method, where
// n = 190 248 273 382 547 686 244 479 775 579 416 295 505 415 044 511.
// Here n=pq, where p and q are prime and p-1 is 37-smooth.

int main()
{

    // Solution
    // p = 3998863619724381409
    // q = 47575584334546623464185354879

    static const mpz_class n = 190248273382547686244479775579416295505415044511_mpz;
    static const mpz_class p = pollard_p_minus_one_factorization( n, 50 );
    static const mpz_class q = n / p;

    std::cout << "p = " << p << std::endl;
    std::cout << "q = " << q << std::endl;

    std::cout << "p is prime? " << std::boolalpha << ( thousand_primes_test( p ) && fibonacci_test( p ) ) << std::endl;
    std::cout << "q is prime? " << std::boolalpha << ( thousand_primes_test( q ) && fibonacci_test( q ) ) << std::endl;

    return EXIT_SUCCESS;
}
