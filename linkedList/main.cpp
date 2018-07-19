#include <iostream>
#include "linkedlist.h"

using namespace std;


int main()
{
  LinkedList list;

  /********************************/
  // add items to the front
  for(int i = 0; i < 10 ; i++)
    list.pushFront(i);

  // read and remove items from front
  for(int i = 0; i < 10 ; i++)
  {
    cout << list.popFront() << ", ";
  }
  cout << endl;
  cout << list.isEmpty()<< endl;


  /********************************/
  for(int i = 0; i < 10 ; i++)
    list.pushBack(i);

  cout << list.find(9) << ", " << list.find(15) << endl;

  for(int i = 0; i < 10 ; i++)
  {
    cout << list.PopBack() << ", ";
  }
  cout << endl;
  cout << list.isEmpty()<< endl;

  /********************************/


  return 0;
}
