#include <iostream>
#include "binaryheap.h"
#include <algorithm>
#include <random>
#include "heapsort.h"

using namespace std;
vector <float> vecOrigin;
int main()
{
  cout << "---binary Heap example and the max ---" << endl;
  BinaryHeap<int> hp;
  hp.insert(10);
  hp.insert(3);
  hp.insert(15);
  hp.insert(8);
  cout << hp.extractMax() << endl;

  // c++ standard heap

  cout << "--- Origignal vector to try in place heap making ---" << endl;
  vector<float> vec;
  vector<float> vec2;
  for (int i = 0; i <10 ; i++){
    vec.push_back(float(rand())/RAND_MAX);
    cout << vec.back() << ", ";
  }
  vec2 = vec;
  vecOrigin = vec;
  cout << endl << "---after std make heap---" << endl;
  std::make_heap(vec.begin(),vec.end());

  for (unsigned int i = 0; i <10 ; i++){
    cout << vec[i] << ", ";
  }
  cout << endl << "--- after my make heap ---" << endl;
  mySort::buildHeap(vec2.begin(),vec2.end());
  for (unsigned int i = 0; i <10 ; i++){
    cout << vec2[i] << ", ";
  }

  cout << endl << "--- STD sort ---" << endl;
  for (int i = 0; i <10 ; i++){
    cout << vec.front() << ", ";
    std::pop_heap(vec.begin(),vec.end());
    vec.pop_back();
  }
  cout << endl;
  // std::pop_heap // std::push_heap

  return 0;
}
