#include<bits/stdc++.h>

#include<iostream>

using namespace std;

class PersonalNoteKeeper {				        // a singly linked list
public:
    unordered_map<string,string> noteKeeper;
    PersonalNoteKeeper();				        // empty list constructor
    ~PersonalNoteKeeper();				        // destructor
    bool empty() const;				    // is list empty?
    void traverse();                    // traversstring the list
    void search(string t);                 // Search the element
    void modify(string t);                 // Modify the element
    void deleteNote(string t);             // Deletstring the element
    void add(unordered_map<string,string>* v, const string& t,const string& d);		// insert new node before v
};


bool PersonalNoteKeeper::empty() const		// is list empty?
{   

}




PersonalNoteKeeper::~PersonalNoteKeeper()			// destructor
{
    
}


void PersonalNoteKeeper::add(unordered_map<string,string>* v, const string& t, const string& d)		// insert new node before v
{

}

void PersonalNoteKeeper::traverse(){

}

void PersonalNoteKeeper::search(string t){

}

void PersonalNoteKeeper::modify(string t){
    // noteKeeper[t];
    if(true)//if present)
    {
        cout<<"What do you want to modify?\n";
        cout<<"1.Tag\n2.Data";
        int option=0;
        cin>>option;
        string update;
        if(option){
            cout<<"Enter the updated Tag:\n";

        }
        else
        {
            cout<<"Enter the updated Data:\n";
            cin>>update;
        }
    }
    else//absent
    {
        cout<<"Data with that particular tag isn't available\n";
    }    
}

void PersonalNoteKeeper::deleteNote(string t){
    noteKeeper[t];
    if (true)//delete if present)
    {

    }
    else//absent
    {
        cout<<"Data with that particular tag isn't available\n";
    }
    
    return;
}

void printChoices(){
    cout<<"Enter your choice please:\n";
    cout<<"1 : Add a new Note\n";
    cout<<"2 : Search the Note\n";
    cout<<"3 : Deletstring the Note\n";
    cout<<"4 : Modify the Note\n";
    cout<<"5 : Travesstring the Notes\n";
    cout<<"6 : Exit the Note keeper\n";
}

int main(){
    
    int choice = 0;
    while(choice != 6){
        printChoices();
        cin>>choice;
        switch(choice){
            case 1:{
                string tag,data;
                cout<<"Enter thstring tag followed by the Data\n";
                cin>>tag;
                cin>>data;
                break;
            }
            case 2:{
                string t;
                cout<<"Enter thstring tag please:\n";
                cin>>t;
                if (true)
                {
                    cout<<"\n";
                }
                else
                {
                    cout<<"Note not found!\n";
                }
                break;
            }
            case 3:{
                string t;
                cout<<"Enter thstring tag please:\n";
                cin>>t;
                break;
            }
            case 4:{
                string t;
                cout<<"Enter thstring tag please:\n";
                cin>>t;
                break;}
            case 5:{
                break;}
            case 6:{
                cout<<"Exiting";
                break;}
            default:{
                cout<<"Not a valid entry!\n";
                break;}
        }
    }   

    return 0;
}