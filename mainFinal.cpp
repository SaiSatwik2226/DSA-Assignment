#include <bits/stdc++.h>
#include <string.h>
#include <fstream>
#include <iostream>

#include <sys/stat.h>
#include <unistd.h>

using namespace std;

class Dictionary
{
public:
    Dictionary();
    ~Dictionary();

    unordered_set<string> dict;

    void addToDictionary(string s);

    bool checkSpell(const unordered_set<string> &dictionary, const string &word);
    vector<string> spellCheck(const string str, const unordered_set<string> &dictionary);
    void checkString(string *temp, unordered_set<string> &dictionary);
};

Dictionary::Dictionary()
{
    ifstream in;               //Input stream class to operate on files
    in.open("dictionary.txt"); //opens the file provided in the argument
    string line;
    vector<string> myvector;
    if (in.is_open()) //checking if the file is open
    {
        while (!in.eof()) //iterates till the 'end of file' is reached
        {
            getline(in, line); //extracts characters from user and stores them
            myvector.push_back(line);
        }
        in.close();
    }
    copy(myvector.begin(), myvector.end(), inserter(dict, dict.end())); //copying the contents from vector to unordered_set
}

Dictionary::~Dictionary()
{
    dict.clear();
}

void Dictionary::addToDictionary(string s)
{
    ofstream outfile;
    outfile.open("dictionary.txt", ios_base::app); // append instead of overwrite
    outfile << "\n"
            << s;
    return;
}

bool Dictionary::checkSpell(const unordered_set<string> &dictionary, const string &word)
{
    return dictionary.count(word) != 0; //checking if the word has occured atleast once in the dictionaty provided
}

vector<string> Dictionary::spellCheck(const string str, const unordered_set<string> &dictionary)
{
    vector<string> wrong_words;
    stringstream ss(str);
    string word;
    while (ss >> word) //extraction operator of the stringstream class
    {
        if (!checkSpell(dictionary, word))
        {
            // cout << word << endl;
            wrong_words.push_back(word); // if the word isn't found, then it's added to wrong_words vector
        }
    }
    return wrong_words;
}

void Dictionary::checkString(string *temp, unordered_set<string> &dictionary)
{
    vector<string> ans = spellCheck(*temp, dictionary);
    vector<string>::iterator it;
    if (!ans.empty())
    {
        cout << "The Following words are wrong:" << endl;
        for (it = ans.begin(); it != ans.end(); ++it)
        {
            cout << *it << endl;
            string corrected = "";
            do
            {
                cout << "1.Replace(Enter the correct one)\n2.Add to Dictionary" << endl;
                int in;
                cin >> in;
                if (in == 1)
                {
                    cin >> corrected; //if chose to replace, take input from user
                }
                else
                {
                    dictionary.insert(*it); // else add that to our dictionary
                    string choice = "";
                    do
                    {
                        cout << "Save it to dictionary.txt?(Y/N)" << endl;
                        cin >> choice;
                        if (choice == "Y" || choice == "y")
                        {
                            addToDictionary(*it);
                            break;
                        }
                        else if (choice == "N" || choice == "n")
                        {
                            break;
                        }
                    } while (choice != "Y" || choice != "y" || choice != "N" || choice != "n");
                    break;
                }
            } while (!checkSpell(dict, corrected));

            (*temp).replace((*temp).find(*it), (*it).length(), corrected); // replacing the original word with the new one in the string
        }
    }
    return;
}

template <typename E>
class DoubleLinkedList; //forward declare the class

template <typename E>
class DNode
{ // singly linked list node
public:
    E data;                // data of the note
    E tag;                 // tag for the note
    DNode<E> *next = NULL; // next item in the list
    DNode<E> *prev = NULL;
    friend class DoubleLinkedList<E>; // provide DoubleLinkedList access
};

template <typename E>
class DoubleLinkedList
{ // a singly linked list
public:
    DoubleLinkedList();                    // empty list constructor
    ~DoubleLinkedList();                   // destructor
    bool empty() const;                    // is list empty?
    const E &front() const;                // return front element
    const E &back() const;                 // return back element
    void addFront(const E &t, const E &d); // add to front of list
    void removeFront();                    // remove front item list
    void addBack(const E &t, const E &d);  // add to back of list
    void removeBack();                     // remove from back
    void traverse();                       // traverse the list

    void add(DNode<E> *v, const E &t, const E &d); // insert new node before v
    void remove(DNode<E> *v);                      // remove node v
    DNode<E> *search();                            // Search the element
    void modify();                                 // Modify the element
    void deleteNote();                             // Delete the element
    void saveFile();
    void loadFile();

private:
    DNode<E> *header; // head of the list
    DNode<E> *trailer;
};

template <typename E>
DoubleLinkedList<E>::DoubleLinkedList() // constructor
{
    header = NULL;
    trailer = NULL;
}
template <typename E>
bool DoubleLinkedList<E>::empty() const // is list empty?
{
    return header == trailer && header == NULL;
}

template <typename E>
DoubleLinkedList<E>::~DoubleLinkedList() // destructor
{
    while (!(empty()))
    {
        removeFront();
    }
    delete header;
    delete trailer;
}

template <typename E>
void DoubleLinkedList<E>::add(DNode<E> *v, const E &t, const E &d) // insert new node after v
{

    DNode<E> *u = new DNode<E>;
    if (empty())
    {
        header = u;
        trailer = u;
    }
    else if (header == v && header != trailer)
    {
        u->next = header;
        header->prev = u;
        header = u;
    }
    else if (trailer == v)
    {
        u->prev = trailer;
        trailer->next = u;
        trailer = u;
    }
    else
    {
        u->next = v->next;
        u->prev = v;
        v->next->prev = u;
        v->next = u;
    }

    u->tag = t;
    u->data = d;
}

template <typename E>
void DoubleLinkedList<E>::addFront(const E &t, const E &d)
{
    add(header, t, d);
}

template <typename E>
void DoubleLinkedList<E>::addBack(const E &t, const E &d) // add to back of list
{
    add(trailer, t, d);
}

template <typename E>
void DoubleLinkedList<E>::removeFront() // remove from front
{
    if (empty())
    {
        cout << "empty" << endl;
        return;
    }
    DNode<E> *temp = header;

    if (header == trailer)
    {
        header = NULL;
        trailer = NULL;
    }
    else
    {
        header = header->next;
    }

    delete temp;
    return;
}

template <typename E>
void DoubleLinkedList<E>::removeBack() // remove from back
{
    if (empty())
    {
        cout << "empty" << endl;
        return;
    }
    DNode<E> *temp = trailer;
    if (header == trailer)
    {
        header = NULL;
        trailer = NULL;
    }
    else
    {
        trailer = trailer->prev;
        trailer->next = NULL;
    }
    delete temp;
    return;
}

template <typename E>
void DoubleLinkedList<E>::traverse()
{
    DNode<E> *temp = header;
    if (empty())
        cout << "Notes is Empty! Please Add some" << endl;
    else
    {
        while (temp != NULL)
        {
            cout << "Tag: " << temp->tag << "\t"
                 << "Data: " << temp->data << endl;
            temp = temp->next;
        }
    }

    return;
}

template <typename E>
DNode<E> *DoubleLinkedList<E>::search()
{
    DNode<E> *searchElement = header;

    if (empty())
    {
        cout << "The Notes is Empty!" << endl;
        return NULL;
    }

    string t;
    cout << "Enter the tag please:\n";
    getline(cin >> ws, t);

    while (searchElement != NULL)
    {
        if (searchElement->tag == t)
            return searchElement;
        searchElement = searchElement->next;
    }

    cout << "Data with that particular tag isn't available" << endl;
    return NULL;
}

template <typename E>
void DoubleLinkedList<E>::modify()
{
    if (empty())
    {
        cout << "The Notes is Empty!" << endl;
        return;
    }
    DNode<E> *modifyElement = search();
    Dictionary d;
    if (modifyElement != NULL)
    {
        cout << "What do you want to modify?\n";
        cout << "1.Tag\n2.Data" << endl;
        int option = 0;
        cin >> option;
        string update;
        if (option == 1)
        {
            cout << "Enter the updated Tag:\n";
            getline(cin >> ws, update);
            d.checkString(&update, d.dict);
            modifyElement->tag = update;
        }
        else
        {
            cout << "Enter the updated Data:\n";
            getline(cin >> ws, update);
            d.checkString(&update, d.dict);
            modifyElement->data = update;
        }
        cout << "Data Updated successfully!!" << endl;
    }
    return;
}

template <typename E>
void DoubleLinkedList<E>::remove(DNode<E> *s)
{
    if (header == s)
        removeFront();
    else if (trailer == s)
        removeBack();
    else
    {
        s->prev->next = s->next;
        delete s;
    }
    return;
}

template <typename E>
void DoubleLinkedList<E>::deleteNote()
{
    if (empty())
    {
        cout << "The Notes is Empty!" << endl;
        return;
    }
    DNode<E> *deleteNotes = search();

    if (deleteNotes != NULL)
    {
        remove(deleteNotes);
        cout << "Note deleted Successfully!!" << endl;
    }
    else
    {
        cout << "Data with that particular tag isn't available\n";
    }

    return;
}

template <typename E>
void DoubleLinkedList<E>::saveFile()
{

    string choice = "";
    do
    {
        if (empty())
        {
            cout << "Empty Notes nothing to Save, Exiting" << endl;
            return;
        }
        cout << "Do you want to save the file?(Y/N): ";
        getline(cin >> ws, choice);
        if (choice == "N" || choice == "n")
        {
            cout << "Exiting,\nThank you" << endl;
            return;
        }
        else if (choice == "Y" || choice == "y")
        {
            cout << choice << endl;
            ofstream myfile;
            cout << "Enter file name to be saved as: ";
            string name;
            getline(cin >> ws, name);
            name = name + ".csv";
            myfile.open(name, ios::in | ios::trunc); //open for input operations as well as for appending at eof
            myfile << "Tag,Data\n";
            DNode<E> *temp = header;

            cout << "saving.." << endl;

            while (temp != NULL && !empty())
            {
                myfile << temp->tag << "," << temp->data << "\n";
                temp = temp->next;
            }
            cout << "Done! Thank you" << endl;
            myfile.close();
            return;
        }
    } while (choice != "Y" || choice != "y" || choice != "N" || choice != "n");
    return;
}

template <typename E>
void DoubleLinkedList<E>::loadFile()
{
    string choice = "";
    cout << "File Name (.csv only): ";
    getline(cin >> ws, choice);
    if (choice.find(".csv") == string::npos) //checks if the user has given .csv extension, if not adds it
        choice = choice + ".csv";
    if (!fopen(choice.c_str(), "r")) //checks if the file is open or not
    {
        cout << "No File named: " << choice << ", Please restart the steps!!" << endl;
        return;
    }
    string load = "";
    do
    {
        if (empty())
        {
            break;
        }
        cout << "Do you want to append the notes to old one or load as a new file(Y/N): ";
        cin >> load;
        if (load == "Y" || load == "y")
        {
            break;
        }
        else if (load == "N" || load == "n")
        {
            while (!(empty()))
            {
                removeFront();
            }
            break;
        }
    } while (load != "Y" || load != "y" || load != "N" || load != "n");

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
            string tag, data;
            tag = line.substr(0, line.find(","));
            data = line.substr(line.find(",") + 1, line.length());
            addBack(tag, data);
        }
        myfile.close();
    }
    cout << "Loaded" << endl;
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

int main()
{
    DoubleLinkedList<string> notesKeeper;

    Dictionary d;

    int choice = 0;
    while (choice != 8)
    {
        printChoices();
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string tag, data;
            cout << "Enter the Tag: ";
            getline(cin >> ws, tag, '\n');
            d.checkString(&tag, d.dict);
            cout << "Enter the Data: ";
            getline(cin >> ws, data);
            d.checkString(&data, d.dict);
            notesKeeper.addBack(tag, data);
            break;
        }
        case 2:
        {
            DNode<string> *point = notesKeeper.search();
            if (point != NULL)
            {
                cout << "Tag: " << point->tag << "\t"
                     << "Data: " << point->data << endl;
            }
            break;
        }
        case 3:
        {
            notesKeeper.deleteNote();
            break;
        }
        case 4:
        {
            notesKeeper.modify();
            break;
        }
        case 5:
        {
            notesKeeper.traverse();
            break;
        }
        case 6:
        {
            notesKeeper.loadFile();
            break;
        }
        case 7:
        {
            while (!(notesKeeper.empty()))
            {
                notesKeeper.removeFront();
            }
            cout << "Entire Notes has been Deleted!!" << endl;
            break;
        }
        case 8:
        {
            notesKeeper.saveFile();
            exit(0);
            break;
        }
        default:
        {
            cout << "Not a valid entry!\n";
            break;
        }
        }
    }
    return 0;
}
