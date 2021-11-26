#include <bits/stdc++.h>
using namespace std;

bool checkSpell(const unordered_set<string> dictionary, const string word)
{
    return dictionary.count(word) != 0;
}

vector<string> spellCheck(const string str, const unordered_set<string> dictionary)
{
    vector<string> wrong_words;
    stringstream ss(str);
    string word;
    while (ss >> word)
    {
        if (!checkSpell(dictionary, word))
        {
            wrong_words.push_back(word);
        }
    }
    return wrong_words;
}

int main()
{
    string str = "zoo";
    // cin>>str;
    // getline(cin>>ws, str);
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
    unordered_set<string> dict(myvector.begin(), myvector.end());
    cout<<dict.count(str)<<endl;
    cout<<dict.count("zoo")<<endl;
    cout<<typeid("zoo").name()<<endl;
    cout<<typeid(str).name()<<endl;
    vector<string> ans = spellCheck(str, dict);
    unordered_set<string>::iterator it1 = dict.begin();
    for (int i =0;i<10;i++)
    {   
        // cout<<typeid(*it1).name()<<endl;
        cout << *it1 << endl;
        cout << dict.count(*it1) << endl;
        ++it1;
    }
    // vector<string>::iterator it;
    // for (it = ans.begin(); it != ans.end(); ++it)
    // {
    //     cout << *it << endl;
    // }
}