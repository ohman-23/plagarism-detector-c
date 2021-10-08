/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, Ethan Ohman, this programming project is my own work
 * and I have not provided this code to any other student.

 * Name: Ethan Ohman
 * email address: ethanjohman@utexas.edu
 * UTEID: ejo527
 * Section 5 digit ID: 15995
 *
 */

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <utility>
#include "Essay.h"
#include "HashTable.h"
#include <algorithm>
#include "PrimeGenerator.h"

using namespace std;

// copySummary
// this struct holds information returned from text document comparisons (to be sorted later by descending number
// of collisions)
struct copySummary {
    string first;
    string second;
    int comp;
};

// sortFunc()
// this function is used in c++ stl sort algo to sort copySummary structures by number of collisions in a
// descending order
bool sortFunc(copySummary a, copySummary b) {
    if(a.comp > b.comp) {
        return true;
    }
    return false;
}

// getdir()
// returns a vector populated with all text file names in a specified directory, and the size of said vector
int getdir (string dir, vector<string> &files) {
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

int main(int argc, char *argv[]) {

  if (argc < 2) {
    cout << "ERROR: enter directory name as an argument" << endl;
    return (0);
  }
    PrimeGenerator pg;
    HashTable h;

    string dir = argv[1];
//    string dir = "sm_doc_set";
    int p = stoi(argv[2]);
//    int p = 6;
    int m = stoi(argv[3]);
//    int m = 200;

    int i, j, idx;
    vector<string> files = vector<string>();
    string str;
    unordered_map<int, string> index;
    vector<Essay> Essays;
    vector<copySummary> suspects;

    getdir(dir,files);
    idx = 0;
    for (unsigned int i = 2; i < files.size(); i++) {
        // ignore . and ..
        index[idx] = files[i];

        string filename;
        filename = dir + "/" + files[i];
        Essay temp(filename, p, m);

        Essays.push_back(temp);
        idx++;
    }
    int size = Essays.size();

    //algo
    for(i = 0; i < size; i++) {
        //populate hashtable
        for(auto s : Essays.at(i).getEssay()) {
            h.insert(s, pg);
        }
        for(j = i+1; j < size; j++) {
            int comp;
            comp = h.compareEssay(Essays.at(j));
            if(comp >= m) {
                copySummary c;
                c.first = index[i];
                c.second = index[j];
                c.comp = comp;
                suspects.push_back(c);
            }
        }
        h.fullCLear();
    }
    //sort results
    sort(suspects.begin(), suspects.end(), sortFunc);
    for(auto s : suspects) {
        cout << s.comp << " : " << s.first << " " << s.second  <<  endl;
    }
    return 0;
}
