#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include "HashTable.h"
#include "Essay.h"

HashTable::HashTable() {
    this->items = 0;
    this->loadFactor = 0;
    this->size = INIT_SIZE;
    this->ind = 0;
    this->table.resize(this->size);
}

int HashTable::hash(string s) {
    int hash = 5531;
    int i = 1;
    for(int c : s) {
        hash = hash + c*i;
        i++;
    }
    return hash%this->size;
}


void HashTable::insert(string s, PrimeGenerator& pg) {
    int key = this->hash(s);
    this->table.at(key).push_back(s);

    //update load factor and or possibly resize
    this->items++;
    this->loadFactor = this->calcLoadFactor();
    if(this->loadFactor >= LOAD_FACTOR_LIMIT) {
        this->rebalance(pg);
    }
}

bool HashTable::contains(string s) {
    int key = this->hash(s);
    for(auto str : this->table.at(key)) {
        if(str == s) {
            return true;
        }
    }
    return false;
}

void HashTable::rebalance(PrimeGenerator &pg) {
    //update ind and size
    pair<int, int> info;
    info = pg.nextPrime(this->ind, this->nextSize());
    this->ind = info.first;
    this->size = info.second;
    // set items to zero so loadbalance recalculated

    //reinsert items
    vector<vector<string>> copy = this->table;
    this->clear();
    this->table.resize(this->size);
    for(auto vec : copy) {
        if(!vec.empty()) {
            for(auto str : vec) {
                this->insert(str, pg);
            }
        }
    }
}

void HashTable::clear() {
    this->items = 0;
    this->table.clear();
}

void HashTable::fullCLear() {
    this->items = 0;
    this->loadFactor = 0;
    this->size = INIT_SIZE;
    this->ind = 0;
    this->table.resize(this->size);
}

int HashTable::compareEssay(Essay &essay) {
    int collisions = 0;
    for(string s: essay.getEssay()){
        if(this->contains(s)) {
            collisions++;
        }
    }
    return collisions;
}

// private functions
int HashTable::nextSize() {
    int resize = 4;
    return this->size*resize;
}
double HashTable::calcLoadFactor() {
    double newLoad = double(this->items)/double(this->size);
    return newLoad;
}
