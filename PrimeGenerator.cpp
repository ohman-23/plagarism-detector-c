#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include "PrimeGenerator.h"

PrimeGenerator::PrimeGenerator(int maxNum) {
    int p;
    int i;

    this->maxNum = maxNum;
    bool primeArr[this->maxNum];
    this->initBoolArr(primeArr);
    // seive of erathones
    p = 2;
    while(p*p <= this->maxNum) {
        if(primeArr[p]) {
            //means number is prime
            for(i = 2*p; i < this->maxNum; i = i+p) {
                primeArr[i] = false;
            }
        }
        p++;
    }
    for(i = 2; i < this->maxNum; i++) {
        if(primeArr[i]) {
            this->primes.push_back(i);
        }
    }
}
pair<int, int> PrimeGenerator::nextPrime(int ind, int limit) {
    int i;
    int size = this->primes.size();
    for(i = ind; i < size; i++) {
        if(this->primes.at(i) >= limit) {
            pair<int, int> info (i, this->primes.at(i));
            return info;
        }
    }
    cout << "YOU NEED TO GENERATE MORE PRIMES?" << endl;
    pair<int, int> fail (this->primes.at(size-1), size-1);
    return fail;
}

vector<int> PrimeGenerator::getPrimeArr() {
    return this->primes;
}

void PrimeGenerator::initBoolArr(bool p[]) {
    int i;
    for(i = 0; i < this->maxNum; i++) {
        p[i] = true;
    }
}
