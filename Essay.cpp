#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Essay.h"
#include <deque>

Essay::Essay(string f, int s, int l) {
    this->filename = f;
    this->sentenceSize = s;
    this->limit = l;
    this->processString();
    // at this point the Essay should be interfaceable
}

void Essay::processString() {

    deque<string> line;
    fstream file;
    string word;
    int count;
    count = 0;

    file.open(this->filename.c_str());
    while(file >> word) {
        if(count != this->sentenceSize-1) {
            // populate the dequeue
            line.push_back(word);
            count++;
        }
        else {
            line.push_back(word);
            string temp = "";
            for(auto s : line) {
                temp += s + " ";
            }
            temp = this->filterString(temp);
            this->essayStrings.push_back(temp);
            line.pop_front();
        }
    }
    // now sentence structure should be created
}

string Essay::filterString(string s) {
    string newString = "";
    for(char c: s) {
        char t = tolower(c);
        int diff = t-'a';
        if(t == '\'' || (diff >= 0 && diff < 26) || (diff >= -49 && diff <-39) ){
            newString += t;
        }
    }
    return newString;
}


