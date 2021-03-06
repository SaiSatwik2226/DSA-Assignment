#include <bits/stdc++.h>
#include <string.h>

// #include "spellCheck.h"

using namespace std;

// void loadDict()
// {
//     ifstream in;
//     in.open("Dictionary.txt");
//     string line;
//     vector<string> myvector;
//     if (in.is_open())
//     {
//         while (!in.eof())
//         {
//             getline(in, line);
//             // myvector.push_back(line);
//             myDict.insert(line);
//         }
//         in.close();
//     }
//     //unordered_set<string>
//     // myDict(myvector.begin(), myvector.end());

//     // copy(myvector.begin(), myvector.end(), inserter(myDict, myDict.end()));
//     unordered_set<string>::iterator it = myDict.begin();
//     for (int i = 0; i < 10; i++)
//     {
//         cout<<(*it)<<endl;
//         ++it;
//     }
    
//     return;
// }
// bool checkSpell(const string word)
// {
//     cout<<word<<endl;
//     // cout<<myDict.count(word)<<endl;

//     unordered_set<string>::iterator it = myDict.find(word);
//     if ( it == myDict.end()) {
//         cout<<"not found"<<endl;
//     }
//     return myDict.count(word) != 0;
// }

// vector<string> spellCheck(const string str)
// {
//     vector<string> wrong_words;
//     stringstream s(str);
//     string word;
//     while (s >> word)
//     {
//         if (!checkSpell(word))
//         {
//             wrong_words.push_back(word);
//         }
//     }

//     vector<string>::iterator it;
//     for (it = wrong_words.begin(); it != wrong_words.end(); ++it)
//     {
//         // temp.replace(temp.find(" " + (*it) + " "), (*it).length() + 2, " " + red + (*it) + reset + " ");
//         // temp.replace(temp.find(*it), (*it).length(),red+(*it)+reset);
//         // cout << *it << endl;
//     }

//     return wrong_words;
// }

bool checkSpell(const unordered_set<string> &dictionary, const string &word)
{
    return dictionary.count(word) != 0;
}

vector<string> spellCheck(const string str, const unordered_set<string> &dictionary)
{
    vector<string> wrong_words;
    stringstream ss(str);
    string word;
    while (ss >> word)
    {
        if (!checkSpell(dictionary, word))
        {
            cout<<word<<endl;
            wrong_words.push_back(word);
        }
    }
    return wrong_words;
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
    DNode<E> *search(E t);                         // Search the element
    void modify(E t);                              // Modify the element
    void deleteNote(E t);                          // Delete the element
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
DNode<E> *DoubleLinkedList<E>::search(E t)
{
    DNode<E> *searchElement = header;

    if (empty())
    {
        cout << "The Notes is Empty!" << endl;
        return NULL;
    }

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
void DoubleLinkedList<E>::modify(E t)
{
    DNode<E> *modifyElement = search(t);

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
            modifyElement->tag = update;
        }
        else
        {
            cout << "Enter the updated Data:\n";
            getline(cin >> ws, update);
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
void DoubleLinkedList<E>::deleteNote(E t)
{
    DNode<E> *deleteNotes = search(t);

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

void printChoices()
{
    cout << "Enter your choice please:\n";
    cout << "1 : Add a new Note\n";
    cout << "2 : Search the Note\n";
    cout << "3 : Delete the Note\n";
    cout << "4 : Modify the Note\n";
    cout << "5 : Travese the Notes\n";
    cout << "6 : Exit the Note keeper\n";
}

void checkString(string temp,const unordered_set<string> &dictionary)
{
    // vector<string> mispelled = spellCheck(temp);
    // if (mispelled.size() != 0)
    // {
    //     string red = "\033[31m";
    //     string reset = "\033[0m";
    //     // temp = " " + temp + " ";
    //     vector<string>::iterator it;
    //     for (it = mispelled.begin(); it != mispelled.end(); ++it)
    //     {
    //         // temp.replace(temp.find(" " + (*it) + " "), (*it).length() + 2, " " + red + (*it) + reset + " ");
    //         temp.replace(temp.find(*it), (*it).length(),red+(*it)+reset);
    //     }
    //     cout<<temp<<endl;
    // }
    // vector<string>::iterator it;
    //     for (it = mispelled.begin(); it != mispelled.end(); ++it)
    //     {
    //         // temp.replace(temp.find(" " + (*it) + " "), (*it).length() + 2, " " + red + (*it) + reset + " ");
    //         // temp.replace(temp.find(*it), (*it).length(),red+(*it)+reset);
    //         cout<<*it<<endl;
    //     }
        
    vector<string> ans = spellCheck(temp, dictionary);
    vector<string>::iterator it;
    for (it = ans.begin(); it != ans.end(); ++it)
    {
        cout << *it << endl;
    }
    return;
}

int main()
{
    DoubleLinkedList<string> notesKeeper;
    // loadDict();
    
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
    // vector<string> ans = spellCheck(str, dict);
    // vector<string>::iterator it;
    // for (it = ans.begin(); it != ans.end(); ++it)
    // {
    //     cout << *it << endl;
    // }
    int choice = 0;
    while (choice != 6)
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
            cout << "Enter the Data: ";
            getline(cin >> ws, data);
            // data = "zoo";
            checkString(data,dict);
            notesKeeper.addBack(tag, data);
            break;
        }
        case 2:
        {
            string t;
            cout << "Enter the tag please:\n";
            getline(cin >> ws, t);
            DNode<string> *point = notesKeeper.search(t);
            if (point != NULL)
            {
                cout << "Tag: " << point->tag << "\t"
                     << "Data: " << point->data << endl;
            }
            break;
        }
        case 3:
        {
            string t;
            cout << "Enter the tag please:\n";
            getline(cin >> ws, t);
            notesKeeper.deleteNote(t);
            break;
        }
        case 4:
        {
            string t;
            cout << "Enter the tag please:\n";
            getline(cin >> ws, t);
            notesKeeper.modify(t);
            break;
        }
        case 5:
        {
            notesKeeper.traverse();
            break;
        }
        case 6:
        {
            cout << "Exiting"<<endl;
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