#ifndef CHEATERS_HASHTABLE_H
#define CHEATERS_HASHTABLE_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "PrimeGenerator.h"
#include "Essay.h"
using namespace std;
#define LOAD_FACTOR_LIMIT 0.7
#define INIT_SIZE 100

// check if define can support doubles
// check if init size is proper

class HashTable{
    private:
        int items;
        int ind;
        int size;
        double loadFactor;
        vector<vector<string>> table;

        // nextSize()
        // returns a number indicating what the next size of the hash table should be when loadfactor is reached
        int nextSize();

        // calcLoadFactor()
        // calculates and returns the current capacity of the hashtable
        double calcLoadFactor();

    public:
        // HashTable()
        // constructor which creates an empty hash table, the size being determined by a specified initial size
        HashTable();

        // hash(string)
        // using polynomial hashing, returns a hash value given a string
        int hash(string s);

        // contains(string)
        // function which checks if a specific string exists within the current hash table
        bool contains(string s);

        // insert(string)
        // insert a string into the hash table, if a specific index is already occupied, use chaining to store string in
        // the hashtable
        void insert(string s, PrimeGenerator& pg);

        // rebalance(PrimeGenerator& pg)
        // when the capacity of the hashtable is greater than or equal to the loadFactor of the hash table,
        // rebalance, resizes the hashtable and re-inserts all strings into the hashtable
        void rebalance(PrimeGenerator& pg);

        // clear()
        // empties the hash table of all values
        void clear();

        // fullClear()
        // empties the hash table of all values and resizes the hash table to the initial default size
        // (use this when generating a new hash table of variate size)
        void fullCLear();

        // compareEssay(Essay&)
        // given an Essay object and a populated hash table, check every possible substring within Essay
        // and count hash table collisions. Return number of collisions to use as a plagiarism suspicion metric
        int compareEssay(Essay& essay);

};

#endif //CHEATERS_HASHTABLE_H
