#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>
#include <vector>
using namespace std;

bool
spellCheck (const unordered_set <string> &dictionary, const string & word)
{
  return dictionary.count (word) != 0;
}

vector<string> spellCheck(const string &str,const unordered_set<string> &dictionary){
    vector<string> wrong_words;
    stringstream ss(str);
    string word;
    while(ss>>word){
        if(!checkSpell(dictionary,word)){
            wrong_words.push_back(word);
        }
    }
    return wrong_words;
}

int main ()
{
//   string str="act actd acting";
    ifstream in;
    in.open("Dictionary.txt");
    string line;
    vector<string> myvector;
    if(in.is_open()){
        while(!in.eof()){
            getline(in,line);
            myvector.push_back(line);
        }
        in.close();
    }
    unordered_set<string> dict(myvector.begin(),myvector.end());
    vector<string> ans = spellCheck(str,dict);
    vector<string>::iterator it;
    for(it=ans.begin();it!=ans.end();++it){
        cout<<*it<<endl;
    }
  
}
