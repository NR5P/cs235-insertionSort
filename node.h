#ifndef NODE_H
#define NODE_H

#include <new>

template<typename T>
struct Node
{
   T data;
   Node* pNext;
   Node* pPrev;

   // default constructor
   Node() : pNext(nullptr), pPrev(nullptr) {}

   // non default constructor
   Node(T& t) : data(t), pNext(nullptr), pPrev(nullptr) {}

   Node(const T& t) : data(t), pNext(nullptr), pPrev(nullptr) {}
};

template<typename T>
Node<T>* copy(const Node<T>* pHead)
{
   if (pHead == nullptr)
      return nullptr;

   int howManyTimesMoved = 0;

   Node<T> * pNewNode = new (std::nothrow) Node<T>(pHead->data);
   if (pNewNode == nullptr)
      throw "ERROR: Unable to allocate a new Node";
   while (pHead->pNext != nullptr) {
      howManyTimesMoved++;
      pNewNode->pNext = new Node<T>(pHead->pNext->data);
      pNewNode->pNext->pPrev = pNewNode;

      // go to the next one
      pNewNode = pNewNode->pNext;
      pHead = pHead->pNext;
   }
   for (int i = 0; i < howManyTimesMoved; i++)
      pNewNode = pNewNode->pPrev;

   return pNewNode;
}

template<typename T>
Node<T>* remove(Node<T> * pRemove)
{
   if (pRemove == nullptr)
      return nullptr;

   Node<T> * pReturn = new (std::nothrow) Node<T>();
   if (pReturn == nullptr)
      throw "ERROR: Unable to allocate a new Node";

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

template <class T>
Node <T>* insert(Node <T> * pCurrent, const T & t, bool after = false) throw (const char*)
{
   try
   {
      Node<T>* pNew = new Node<T>(t);


      // If it's empty
      if (NULL == pCurrent)
      {
         pCurrent = pNew;
         return pNew;

      }

      // Adds to before
      if (!after)
      {
         pNew->pNext = pCurrent;
         pNew->pPrev = pCurrent->pPrev;
         if (pNew->pNext)
            pNew->pNext->pPrev = pNew;
         pCurrent = pNew;
         return pCurrent;
      }

      //adds after
      pNew->pNext = pCurrent->pNext;
      pNew->pPrev = pCurrent;
      pCurrent->pNext = pNew;
      if (pNew->pNext)
      {
         pCurrent->pPrev->pNext = pNew;
      }         

      pCurrent->pPrev = pNew;
      return pNew;
   }
   catch (const char* error)
   {

      throw "ERROR: Unable to allocate a new Node";

   }
   return NULL;
}

template<typename T>
Node<T>* find(Node<T> * pHead, const T & t)
{
   // loop through the linked lists
   for (Node<T>* p = pHead; p != nullptr; p = p->pNext) {
      if (t == p->data) {
         return p;
      }
   }

   return nullptr;
}

template<typename T>
Node<T>* findSorted(Node<T> * pHead, const T & t)
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
Node<T>* insertSorted(Node<T> * &pHead, const T & t)
{
   Node<T>* pNew = new (std::nothrow) Node<T>(t);
   if (pNew == nullptr)
      throw "ERROR: Unable to allocate a new Node";

   // find location in linked list immediately before
   // new node to be inserted
   Node<T> * pFind = findSorted(pHead, t);

   // insert the new node to the head of the list
   if (pFind == nullptr) {
      insert(pHead, pNew);
   }
   else {
      // otherwide insert the new node after the found one
      insert(pFind, pNew, true);
   }
}

template<typename T>
std::ostream& operator<<(std::ostream & out, const Node<T> * pHead)
{
   if (pHead == nullptr)
      return out;

   // display data
   std::cout << pHead->data;

   // if there is something after us, display it
   if (pHead->pNext)
      return out << ", " << pHead->pNext;
   else
      return out;
}

template<typename T>
void freeData(Node<T> * &pHead)
{
   Node <T>* pNext;
   for (Node<T>* p = pHead; p; p = pNext) {
      pNext = p->pNext;
      delete p;
   }
   pHead = nullptr;
}

#endif




















