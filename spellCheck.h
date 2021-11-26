#ifndef SPELLCHECK_H
#define SPELLCHECK_H

using namespace std;

// unordered_set<string> myDict;

void loadDict();

bool checkSpell (const string word);

vector<string> spellCheck(const string str);

#endif 