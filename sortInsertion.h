/***********************************************************************
 * Header:
 *    INSERTION SORT
 * Summary:
 *    This will contain just the prototype for insertionSortTest(). You may
 *    want to put other class definitions here as well.
 * Author
 *    <your names here>
 ************************************************************************/

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "node.h"

/***********************************************
 * INSERTION SORT
 * Sort the items in the array
 **********************************************/
template <class T>
void sortInsertion(T array[], int num)
{
  // No point in continuing if num == 0.
  if (num == 0)
  {
    return;
  }

  // remove item from original array

  // put in linked list

  // copy items back into old array
  
  Node <T> * pSortedHead = new Node <T>(array[0]);

  // Loop to go through all elements inside the array.
  for (int i = 0;i < num; i++)
  {
      insertSorted(pSortedHead, array[i]);
  }

  // Loop to copy the elements from the linked-list back into the input array.
  for (int i = 0; i < num; i++)
  {
    //Set each array element starting with element 0 equal to the data stored in pHead.
    array[i] = pSortedHead->data;
    pSortedHead = remove(pSortedHead); 
  }
  
  

  
}

#endif // INSERTION_SORT_H

