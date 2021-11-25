#include<bits/stdc++.h>
#include<string.h>

#include<hash_map>

#include<spellCheck.h>

using namespace std;

template<typename E>
class DoubleLinkedList;                      //forward declare the class

template <typename E>
class DNode {					        // singly linked list node
public:
    E data;					            // data of the note
    E tag;                              // tag for the note
    DNode<E>* next;				        // next item in the list
    DNode<E>* prev;
    friend class DoubleLinkedList<E>;		// provide DoubleLinkedList access
};

template <typename E>
class DoubleLinkedList {				        // a singly linked list
public:
    DoubleLinkedList();				        // empty list constructor
    ~DoubleLinkedList();				        // destructor
    bool empty() const;				    // is list empty?
    const E& front() const;			    // return front element
    const E& back() const;			    // return back element
    void addFront(const E& t,const E& d);			// add to front of list
    void removeFront();				    // remove front item list
    void addBack(const E& t,const E& d);	// add to back of list
    void removeBack();				// remove from back
    void traverse();                    // traverse the list
    DNode<E>* search(E t);                 // Search the element
    DNode<E>* modify(E t);                 // Modify the element
    void deleteNote(E t);             // Delete the element
    void add(DNode<E>* v, const E& t,const E& d);		// insert new node before v
    void remove(DNode<E>* v);			// remove node v
private:
    DNode<E>* header;				        // head of the list
    DNode<E>* trailer;
};

template <typename E>
DoubleLinkedList<E>::DoubleLinkedList()			// constructor
{
    header = new DNode<T>;
    trailer = new DNode<T>;
    header->next = trailer;
    trailer->prev = header;
}
template <typename E>
bool DoubleLinkedList<E>::empty() const		// is list empty?
{   
    return header->next==trailer;
}

template <typename E>
const E& DoubleLinkedList<E>::front() const	// return front element
{   return header->next->data; }

template<typename E>
const E& DoubleLinkedList<E>::back() const{
    return trailer->prev->data;
}

template <typename E>
DoubleLinkedList<E>::~DoubleLinkedList()			// destructor
{
    while (!(empty()))
    {
        removeFront();
    }
    delete header;
    delete trailer;
}

template<typename E>
void DoubleLinkedList<E>::add(DNode<E>* v, const E& t, const E& d)		// insert new node before v
{
    DNode<E> *u = new DNode<E>;
    u->tag = t;
    u->data = d;
    u->next = v->next;
    u->prev = v;
    v->next->prev = u;
    v->next = u;
}

template<typename E>
void DoubleLinkedList<E>::addFront(const E& t, const E& d){
    add(header,t,d);
}

template<typename E>
void DoubleLinkedList<E>::addBack(const E& t, const E& d)	// add to back of list
{
    add(trailer->prev,t,d);
}

template<typename E>
void DoubleLinkedList<E>::removeFront()				// remove from front
{
    if(empty())
    {
        cout<<"empty"<<endl;
        return;
    }
    remove(header->next);
    return;
}

template<typename E>
void DoubleLinkedList<E>::removeBack()				// remove from back
{
    if(empty())
    {
        cout<<"empty"<<endl;
        return;
    }
    remove(trailer->prev);
}

template<typename E>
void DoubleLinkedList<E>::traverse(){
    DNode<E> *temp = header;
    while(temp != trailer){
        cout<<temp->tag<<"\n"<<temp->data;
        temp = temp->next;
    }
    cout<<endl;
}

template<typename E>
DNode<E>* DoubleLinkedList<E>::search(E t){
    DNode<E>* searchElement = head;
    do
    {
        if(searchElement->tag == t)
            return searchElement;
        searchElement = searchElement->next;
    } while ((searchElement->tag!=t));
    return NULL;
}

template<typename E>
DNode<E>* DoubleLinkedList<E>::modify(E t){
    DNode<E>* modifyElement = search(s);
    if (deleteNotes!=NULL)
    {
        cout<<"What do you want to modify?\n";
        cout<<"1.Tag\n2.Data";
        int option=0;
        cin>>option;
        string update;
        if(option){
            cout<<"Enter the updated Tag:\n"
            cin>>update;
            modifyElement->tag = update;
        }
        else
        {
            cout<<"Enter the updated Data:\n";
            cin>>update;
            modifyElement->data = update;
        }
    }
    else
    {
        cout<<"Data with that particular tag isn't available\n"
    }    
    return modifyElement;
}

template<typename E>
void DoubleLinkedList<E>::deleteNote(E t){
    DNode<E>* deleteNotes = search(s);
    if (deleteNotes!=NULL)
    {
        remove(deleteNotes);
    }
    else
    {
        cout<<"Data with that particular tag isn't available\n"
    }
    
    return;
}

void printChoices(){
    cout<<"Enter your choice please:\n";
    cout<<"1 : Add a new Note\n";
    cout<<"2 : Search the Note\n";
    cout<<"3 : Delete the Note\n";
    cout<<"4 : Modify the Note\n";
    cout<<"5 : Travese the Notes\n";
    cout<<"6 : Exit the Note keeper\n";
}

int main(){
    DoubleLinkedList<string> sll;
    int choice = 0;
    while(choice != 6){
        printChoices();
        cin>>choice;
        switch(choice){
            case 1:{
                string tag,data;
                cout<<"Enter the Tag followed by the Data\n";
                cin>>tag;
                cin>>data;
                sll.addFront(tag,data);
                break;
            }
            case 2:{
                string t;
                cout<<"Enter the tag please:\n";
                cin>>t;
                DNode<string>* point =  sll.search(t);
                if (point!=NULL)
                {
                    cout<<point->tag;
                    cout<<"\n";
                    cout<<point->data;
                }
                else
                {
                    cout<<"Note not found!\n";
                }
                break;
            }
            case 3:{
                string t;
                cout<<"Enter the tag please:\n";
                cin>>t;
                sll.deleteNote(t);
                break;
            }
            case 4:{
                string t;
                cout<<"Enter the tag please:\n";
                cin>>t;
                sll.modify(t);
                break;}
            case 5:{
                sll.traverse();
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