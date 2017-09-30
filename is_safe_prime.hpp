#ifndef IS_SAFE_PRIME_HPP
#define IS_SAFE_PRIME_HPP

#include "fibonacci_test.hpp"
#include "thousand_primes_test.hpp"

template<class Prime>
inline bool is_safe_prime( Prime const& prime ) {
    Prime must_also_be_prime = prime;
    must_also_be_prime -= 1;
    must_also_be_prime /= 2;
    return thousand_primes_test( must_also_be_prime ) && fibonacci_test( must_also_be_prime ) ;
}

#endif // IS_SAFE_PRIME_HPP
