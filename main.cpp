#include <iostream>
#include "binaryheap.h"

using namespace std;

int main()
{
  BinaryHeap<int> hp;
  hp.insert(10);
  hp.insert(3);
  hp.insert(15);
  hp.insert(8);
  cout << hp.extractMax() << endl;
  return 0;
}
