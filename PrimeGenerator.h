
#ifndef CHEATERS_PRIMEGENERATOR_H
#define CHEATERS_PRIMEGENERATOR_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#define MAX_NUM 40000
using namespace std;

class PrimeGenerator {
    private:
        vector<int> primes;
        int maxNum;

        // initBoolArr(boolean array)
        // populates a boolean array to be false at every index
        void initBoolArr(bool p[]);
    public:
        // PrimeGenerator()
        // constructor for PrimeGenerator class, user can optionally set the upper bound on the maximum prime number
        // that can possibly be generated
        PrimeGenerator(int maxNum=MAX_NUM);

        // getPrimeArr()
        // accessor to get the complete list of prime numbers up to a certain number (specified by the user in the constructor)
        vector<int> getPrimeArr();

        // nextPrime(int, int)
        // returns a pair containing [index of prime number in the array, prime number], where the prime number has to
        // be greater than a set limit value
        // if the limit exceeds the max prime value, the maximum prime generated is returned
        pair<int, int> nextPrime(int ind, int limit);
};

#endif //CHEATERS_PRIMEGENERATOR_H
