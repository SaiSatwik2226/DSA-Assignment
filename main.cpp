#include<bits/stdc++.h>
#include<string.h>

#include<hash_map>

using namespace std;

using namespace std;

template<typename E>
class SingleLinkedList;                      //forward declare the class

template <typename E>
class SNode {					        // singly linked list node
private:
    E elem;					            // linked list element value
    SNode<E>* next;				        // next item in the list
    friend class SingleLinkedList<E>;		// provide SingleLinkedList access
};

template <typename E>
class SingleLinkedList {				        // a singly linked list
public:
    SingleLinkedList();				        // empty list constructor
    ~SingleLinkedList();				        // destructor
    bool empty() const;				    // is list empty?
    const E& front() const;			    // return front element
    void addFront(const E& e);			// add to front of list
    void removeFront();				    // remove front item list
    void traverse();                    // traverse the list
    SNode<E>* search(E s);                 // Search the element
    SNode<E>* modify(E s);                 // Modify the element
    void deleteNote(E s);             // Delete the element
private:
    SNode<E>* head;				        // head of the list
};

template <typename E>
SingleLinkedList<E>::SingleLinkedList()			// constructor
    : head(NULL) { }

template <typename E>
bool SingleLinkedList<E>::empty() const		// is list empty?
{ return head == NULL; }

template <typename E>
const E& SingleLinkedList<E>::front() const	// return front element
{ return head->elem; }

template <typename E>
SingleLinkedList<E>::~SingleLinkedList()			// destructor
{ while (!empty()) removeFront(); }

template <typename E>
void SingleLinkedList<E>::addFront(const E& e) {		// add to front of list
    SNode<E>* v = new SNode<E>;				    // create new node
    v->elem = e;					            // store data
    v->next = head;					            // head now follows v
    head = v;						            // v is now the head
}

template <typename E>
void SingleLinkedList<E>::removeFront() {			// remove front item
    SNode<E>* old = head;				        // save current head
    head = old->next;					        // skip over old head
    delete old;					        	    // delete the old head
}

template <typename E>
void SingleLinkedList<E>::traverse(){
    SNode<E> *temp = head;
    while(temp != NULL){
        cout<<temp->elem<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

template<typename E>
SNode<E>* SingleLinkedList<E>::search(E s){
    SNode<E>* searchElement;

    return searchElement;
}

template<typename E>
SNode<E>* SingleLinkedList<E>::modify(E s){
    SNode<E>* modifyElement = search(s);

    return modifyElement;
}

template<typename E>
void SingleLinkedList<E>::deleteNote(E s){
    SNode<E>* deleteNotes = search(s);

    return;
}

int main(){
    
    return 0;
}