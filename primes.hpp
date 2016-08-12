#pragma once

#include <cstdint>
#include <vector>

const uint32_t L1D_CACHE_SIZE = 32768;
const uint32_t SIEVE_THREADS  = 4;

class threaded_bitpack;

class Primes
{
    public:
        // Member functions
        Primes();
        ~Primes();

        // Test 1 number for primality
        bool isPrime(uint64_t n) const;

        // Calculate pi(x), number of primes below x
        // Returns the exact number if available, otherwise
        // it returns an upper bound
        uint64_t pi(uint64_t x = 0);

        // Get a vector full of primes up to limit
        const std::vector<uint64_t>& getList(uint64_t limit = 0);

        // Creates an internal data structure with all primes up to limit
        // Speeds up isPrime() and is used internally for getList()
        void sieve(uint64_t limit, std::size_t threads = SIEVE_THREADS);

    private:
        threaded_bitpack* pSieve;
        std::vector<uint64_t> pList;
};

