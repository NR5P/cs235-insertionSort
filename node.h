#ifndef NODE_H
#define NODE_H

#include <new>

template<typename T>
struct Node
{
    T data;
    Node *pNext;
    Node *pPrev;

    // default constructor
    Node() : pNext(nullptr), pPrev(nullptr) {}

    // non default constructor
    Node(T &t) : data(t), pNext(nullptr), pPrev(nullptr) {} 
};

template<typename T>
Node<T> *copy(const Node<T> *pHead)
{
    if (pHead == nullptr)
        return nullptr;
    
    try {
        Node<T> *pNewNode = new Node(pHead -> data);
    } catch(std::bad_alloc) {
        throw "ERROR: Unable to allocate a new Node";
    }

    while (pHead->pNext) {
        pNewNode = insert(pNewNode, pHead->data, true);
        pNewNode = pNewNode->pNext;
        pHead = pHead->pNext;
    }
}

template<typename T>
Node<T> *remove(Node<T> *pRemove)
{
    if (pRemove == nullptr)
        return nullptr;

    // update the pointers in pRemove->pPrev and pRemove->pNext
    if (pRemove->pNext) {
        pRemove->pNext->pPrev = pRemove->pPrev;
    }

    if (pRemove->pPrev) {
        pRemove->pPrev->pNext = pRemove->pNext;
    }

    // determine which node we will return
    pReturn = pRemove->pPrev ? pRemove->pPrev : pRemove->pNext;

    // now delete the node and return
    delete pRemove;
    return pReturn;
}

template<typename T>
Node<T> *insert(Node<T> *pCurrent, const T &t, bool after = false)
{
    try {
        Node<T> *pNewNode = new Node(pHead -> data);
    } catch (std::bad_alloc) {
        throw "ERROR: Unable to allocate a new Node";
    }

    if (pCurrent->pPrev && !after) {
        // make new nodes previous the insert before nodes previous
        pNewNode->pPrev = pCurrent->pPrev;

        // make the insert before nodes previous THIS node
        pCurrent->pPrev = pNewNode;

        // make the node befores next point to THIS node
        pCurrent->pPrev->pNext = pNewNode;

        // make THIS point to the next node
        pNewNode->pNext = pCurrent;
    } else if (pCurrent->pNext && after) {
        // make new nodes previous the insert before nodes previous
        pNewNode->pNext = pCurrent->pNext;

        // make the insert before nodes previous THIS node
        pCurrent->pNext = pNewNode;

        // make the node befores next point to THIS node
        pCurrent->pNext->pPrev = pNewNode;

        // make THIS point to the next node
        pNewNode->pPrev = pCurrent;
    }

    return pNewNode;
}

template<typename T>
Node<T> *find(Node<T> *pHead, const T &t)
{
    // loop through the linked lists
    for (Node<T> *p = pHead; p != nullptr; p = p->pNext) {
        if (t == p->data) {
            return p;
        }
    }

    return nullptr;
}

template<typename T>
Node<T> *findSorted(Node<T> *pHead, const T &t)
{
    //trivial case
    if (nullptr == pHead || t < pHead->data)
        return nullptr;

    // search for node
    while (pHead->data < t) {
        pHead = pHead->pNext;
    }

    return pHead;
}

template<typename T>
Node<T> *insertSorted(Node<T> *pHead, const T &t)
{
    try {
        // allocate a new node
        Node<T> *pNew = new Node<T>(t);
    } catch {
        throw "ERROR: Unable to allocate a new Node";
    }

    // find location in linked list immediately before
    // new node to be inserted
    Node<T> *pFind = findSorted(pHead, t);

    // insert the new node to the head of the list
    if (pFind == nullptr) {
        insert(pHead, pNew);
    } else {
        // otherwide insert the new node after the found one
        insert(pFind, pNew, true);
    }
}


template<typename T>
Node<T> *getNode(T &data)
{
// allocating space
Node* newNode = new Node();

// inserting the required data
newNode->data = data;
newNode->next = NULL;
return newNode;
}
#endif




















