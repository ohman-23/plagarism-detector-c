#ifndef CHEATERS_ESSAY_H
#define CHEATERS_ESSAY_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Essay.h"

using namespace std;

class Essay {
    private:
        // private member data
        string filename;
        int sentenceSize;
        int limit;
        vector<string> essayStrings;

        // filterString(string)
        // given some string s of varying size, returns a filtered string that removes all chars except
        // a-z and apostrophes
        string filterString(string s);

    public:
        // Essay(string, int, int)
        // constructor for Essay object, within constructor, processString is called
        Essay(string f, int s, int l);

        // getEssay()
        // returns processed vector of all m-length (specified on the command line) substrings in an essay object
        vector<string> getEssay() {
           return essayStrings;
        }

        // processString()
        // opens designated text file and using a rolling window, preprocesses a text file to collect
        // all filtered m-length substrings (as specified by user)
        void processString();
};

#endif //CHEATERS_ESSAY_H
