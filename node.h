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


    // determine which node we will return


    // now delete the node and return
    delete pRemove;
    return pReturn;
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