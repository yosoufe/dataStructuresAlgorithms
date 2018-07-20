#include <iostream>
#include "binaryheap.h"
#include <algorithm>
#include <random>

using namespace std;

int main()
{
  BinaryHeap<int> hp;
  hp.insert(10);
  hp.insert(3);
  hp.insert(15);
  hp.insert(8);
  cout << hp.extractMax() << endl;

  // c++ standard heap
  vector<float> vec;
  for (int i = 0; i <10 ; i++){
    vec.push_back(float(rand())/RAND_MAX);
    cout << vec.back() << ", ";
  }
  cout << endl << "---after heap---" << endl;
  make_heap(vec.begin(),vec.end());

  for (unsigned int i = 0; i <10 ; i++){
    cout << vec[i] << ", ";
  }
  cout << endl << "--- sort ---" << endl;

  for (int i = 0; i <10 ; i++){
    cout << vec.front() << ", ";
    pop_heap(vec.begin(),vec.end());
    vec.pop_back();
  }
  cout << endl;

  // pop_heap // push_heap


  return 0;
}
