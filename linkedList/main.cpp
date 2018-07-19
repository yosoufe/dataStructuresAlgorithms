#include <iostream>
#include "linkedlist.h"

#include <forward_list>

using namespace std;

// standard c++ linkedlist is std::forward_list
// https://en.cppreference.com/w/cpp/container/forward_list

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

  list.erase(0);list.erase(5);list.erase(9);

  for(int i = 0; i < 7 ; i++)
  {
    cout << list.PopBack() << ", ";
  }
  cout << endl;
  cout << list.isEmpty()<< endl;

  /********************************/

  std::forward_list<double> stdlist;
  stdlist.push_front(10);
  cout << stdlist.front() << endl;
  return 0;
}
