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

int main ()
{
  ifstream in;
  in.open("dictionary.txt");
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
  
}
