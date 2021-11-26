#include <bits/stdc++.h>

#include "spellCheck.h"
unordered_set<string> myDict;

using namespace std;
void loadDict()
{
    ifstream in;
    in.open("dictionary.txt");
    string line;
    vector<string> myvector;
    if (in.is_open())
    {
        while (!in.eof())
        {
            getline(in, line);
            myvector.push_back(line);
        }
        in.close();
    }
    //unordered_set<string>
    // myDict(myvector.begin(), myvector.end());

    copy(myvector.begin(), myvector.end(), inserter(myDict, myDict.end()));
}
bool checkSpell(const string word)
{
    cout<<word<<endl;
    // cout<<myDict.count(word)<<endl;

    unordered_set<string>::iterator it = myDict.find(word);
    if ( it == myDict.end()) {
        cout<<"not found"<<endl;
    }
    return myDict.count(word) != 0;
}

vector<string> spellCheck(const string str)
{
    vector<string> wrong_words;
    stringstream s(str);
    string word;
    while (s >> word)
    {
        if (!checkSpell(word))
        {
            wrong_words.push_back(word);
        }
    }

    vector<string>::iterator it;
    for (it = wrong_words.begin(); it != wrong_words.end(); ++it)
    {
        // temp.replace(temp.find(" " + (*it) + " "), (*it).length() + 2, " " + red + (*it) + reset + " ");
        // temp.replace(temp.find(*it), (*it).length(),red+(*it)+reset);
        // cout << *it << endl;
    }

    return wrong_words;
}
