#include<bits/stdc++.h>

#include<iostream>

using namespace std;

class Dictionary
{
public:
    Dictionary();                    // empty list constructor
    ~Dictionary();

    unordered_set<string> dict;

    void addToDictionary(string s);

    bool checkSpell(const unordered_set<string> &dictionary, const string &word);
    unordered_set<string> spellCheck(const string str, const unordered_set<string> &dictionary);
    void checkString(string *temp,unordered_set<string> &dictionary);
};

Dictionary::Dictionary(){
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
    copy(myvector.begin(), myvector.end(), inserter(dict, dict.end()));
}

Dictionary::~Dictionary(){
    dict.clear();
}

void Dictionary::addToDictionary(string s)
{
    ofstream outfile;
    outfile.open("dictionary.txt", ios_base::app); // append instead of overwrite
    outfile << "\n"<<s;
    return;
}

bool Dictionary::checkSpell(const unordered_set<string> &dictionary, const string &word)
{
    return dictionary.count(word) != 0;
}

unordered_set<string> Dictionary::spellCheck(const string str, const unordered_set<string> &dictionary)
{
    unordered_set<string> wrong_words;
    stringstream ss(str);
    string word;
    while (ss >> word)
    {
        if (!checkSpell(dictionary, word))
        {
            // cout<<word<<endl;
            wrong_words.insert(word);
        }
    }
    return wrong_words;
}

void Dictionary::checkString(string *temp,unordered_set<string> &dictionary)
{        
    unordered_set<string> ans = spellCheck(*temp, dictionary);
    unordered_set<string>::iterator it;
    if(!ans.empty())
    {
        cout<<"The Following words are wrong:"<<endl;
        for (it = ans.begin(); it != ans.end(); ++it)
        {
            cout << *it << endl;
            string corrected="";
            do
            {
                cout<<"1.Replace(Enter the correct one)\n2.Add to Dictionary"<<endl;
                int in;
                cin>>in;
                if(in==1){
                    cin>>corrected;                    
                }
                else {
                    dictionary.insert(*it);
                    string choice = "";
                    do
                    {
                        cout << "Save it to dictionary.txt?(Y/N)" << endl;
                        cin >> choice;
                        if (choice == "Y" || "y")
                        {
                            addToDictionary(*it);
                            break;
                            }
                        else if(choice == "N"||"n")
                        {
                            break;
                        }
                    } while (choice != "Y" || "y" || "N" || "n");
                    break;
                }
            } while (!checkSpell(dict,corrected));

            (*temp).replace((*temp).find(*it), (*it).length(), corrected);
        }
    }
    return;
}


class PersonalNoteKeeper {
public:
    unordered_map<string,string> noteKeeper;
    bool empty() const;				    // is list empty?
    void traverse();                    // traversstring the list
    void search();                 // Search the element
    void modify();                 // Modify the element
    void deleteNote();             // Delete string the element
    void add(const string& t,const string& d);
    void loadFile();
    void saveFile();
};

bool PersonalNoteKeeper::empty() const		// is list empty?
{   
    return noteKeeper.empty();
}

void PersonalNoteKeeper::add(const string& t, const string& d)
{
    noteKeeper.insert({t,d});
}

void PersonalNoteKeeper::traverse(){
    if (empty())
    {
        cout << "The Notes is Empty! Please Add few" << endl;
        return;
    }
    unordered_map<string,string>::iterator it = noteKeeper.begin();
    for (; it != noteKeeper.end() ; ++it)
    {
        cout<<"Tag: "<<it->first<<"\t"<<"Data: "<<it->second<<endl;
    }
    return;
}

void PersonalNoteKeeper::search(){
    if (empty())
    {
        cout << "The Notes is Empty!" << endl;
        return;
    }
    string t;
    cout<<"Enter the tag please:\n";
    getline(cin >> ws, t, '\n');
    if(noteKeeper.count(t)){
        unordered_map<string,string>::iterator it = noteKeeper.find(t);
        cout<<"Tag: "<<it->first<<"\t"<<"Data: "<<it->second<<endl;
    }
    else{
        cout<<"Element with that tag not found!"<<endl;
    }
    return;
}

void PersonalNoteKeeper::modify(){
    if (empty())
    {
        cout << "The Notes is Empty!" << endl;
        return;
    }
    string t;
    cout<<"Enter the tag please:\n";
    getline(cin >> ws, t, '\n');
    Dictionary d;
    if(noteKeeper.count(t))
    {
        unordered_map<string,string>::iterator it = noteKeeper.find(t);
        cout<<"What do you want to modify?\n";
        cout<<"1.Tag\n2.Data"<<endl;
        int option=0;
        cin>>option;
        string update;
        if(option==1){
            cout<<"Enter the updated Tag:\n";
            getline(cin >> ws, update);
            d.checkString(&update,d.dict);
            string data = it->second;
            noteKeeper.insert({update,data});
        }
        else
        {
            cout<<"Enter the updated Data:\n";
            getline(cin >> ws, update);
            d.checkString(&update,d.dict);
            it->second = update;
        }
        cout << "Data Updated successfully!!" << endl;
    }
    else
    {
        cout<<"Data with that particular tag isn't available\n";
    }    
}

void PersonalNoteKeeper::deleteNote(){
    if (empty())
    {
        cout << "The Notes is Empty!" << endl;
        return;
    }
    string t;
    cout<<"Enter the tag please:\n";
    getline(cin >> ws, t, '\n');
    if (noteKeeper.count(t))
    {
        unordered_map<string,string>::iterator it = noteKeeper.find(t);
        noteKeeper.erase(it->first);
    }
    else
    {
        cout<<"Data with that particular tag isn't available\n";
    }
    
    return;
}

void PersonalNoteKeeper::loadFile(){
    string choice = "";
    cout << "File Name (.csv only): ";
        getline(cin >> ws, choice);
    if (choice.find(".csv") == string::npos)
        choice = choice + ".csv";
    if (!fopen(choice.c_str(), "r"))
    {
        cout << "No File named: " << choice << ", Please restart the steps!!" << endl;
        return;
    }
    string load;
    do
    {
        if (empty())
        {
            break;
        }
        cout<<"Do you want to append the notes to old one or load as a new file(Y/N): ";
       
        getline(cin>>ws, load);
        if (load == "Y" || load== "y" && load != "N" || load== "n")
        {
            break;
        }
        else if(load == "N" || load== "n")
        {
            noteKeeper.clear();
            break;
        }
    } while (load != "Y" || load!= "y" || load!= "N" || load!="n");

    ifstream myfile;
    myfile.open(choice);
    string line;
    if (myfile.is_open())
    {
        getline(myfile, line);
        line = "";
        while (!myfile.eof())
        {
            getline(myfile, line);
            cout<<line<<endl;
            string tag, data;
            tag = line.substr(0, line.find(","));
            data = line.substr(line.find(",") + 1, line.length());
            add(tag, data);
        }
        myfile.close();
    }
    cout << "Loaded" << endl;
    return;
}

void PersonalNoteKeeper::saveFile(){
    string choice = "";
    do
    {
        if (empty())
        {
            cout << "Empty Notes nothing to Save, Exiting" << endl;
            return;
        }
        cout << "Do you want to save the file?(Y/N): ";
        getline(cin>>ws, choice);
        if(choice == "N" || "n")
        {
            cout << "Exiting,\nThank you" << endl;
            return;
        }
        else if (choice == "Y" || choice== "y")
        {
            cout<<choice<<endl;
            ofstream myfile;
            cout << "Enter file name to be saved as: ";
            string name;
            getline(cin >> ws, name);
            name = name + ".csv";
            myfile.open(name, ios::in | ios::trunc);
            myfile << "Tag,Data\n";
            
            unordered_map<string,string>::iterator it = noteKeeper.begin();

            cout << "saving.." << endl;

            while ((it)!=noteKeeper.end() && !empty())
            {
                myfile << (*it).first << "," << (*it).second << "\n";
                ++it;
            }
            cout << "Done! Thank you" << endl;
            myfile.close();
            return;
        }
    } while (choice != "Y" || choice!= "y" || choice!= "N" || choice!= "n");
    return;
}

void printChoices()
{
    cout << "Enter your choice please:\n";
    cout << "1 : Add a new Note\n";
    cout << "2 : Search the Note\n";
    cout << "3 : Delete the Note\n";
    cout << "4 : Modify the Note\n";
    cout << "5 : Travese the Notes\n";
    cout << "6 : Load previous Notes File\n";
    cout << "7 : Delete All\n";
    cout << "8 : Exit the Note keeper\n";
}
int main(){
    
    PersonalNoteKeeper pNotesKeeper;

    Dictionary d;

    int choice = 0;
    while(choice != 8){
        printChoices();
        cin>>choice;
        switch(choice){
            case 1:{
                string tag, data;
                cout << "Enter the Tag: ";
                getline(cin >> ws, tag, '\n');
                d.checkString(&tag,d.dict);
                cout << "Enter the Data: ";
                getline(cin >> ws, data);
                d.checkString(&data,d.dict);
                pNotesKeeper.add(tag, data);
                break;
            }
            case 2:{
                pNotesKeeper.search();
                break;
            }
            case 3:{
                pNotesKeeper.deleteNote();
                break;
            }
            case 4:{
                pNotesKeeper.modify();
                break;}
            case 5:{
                pNotesKeeper.traverse();
                break;}
            case 6:
            {
                pNotesKeeper.loadFile();
                break;
            }
            case 7:
            {
                while (!(pNotesKeeper.empty()))
                {
                    pNotesKeeper.noteKeeper.clear();
                }
                cout << "Entire Notes has been Deleted!!" << endl;
                break;
            }
            case 8:
            {
                pNotesKeeper.saveFile();
                break;
            }
            default:{
                cout<<"Not a valid entry!\n";
                break;}
        }
    }   

    return 0;
}
