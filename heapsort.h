#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <vector>
using namespace std;

namespace mySort {

template <typename It>
It parent(It it, It begin){
  //(idx-1)/2
  return begin+(it-begin-1)/2;
}

template <typename It>
It leftChild(It it, It begin){
  //2*(idx+1)-1;
  return begin+2*(it-begin+1)-1;
}

template <typename It>
It rightChild(It it, It begin){
  // 2*(idx+1);
  return begin+2*(it-begin+1);
}

template <typename It>
void siftUp(It it, It begin)
{
  while (it>begin && ( *(parent(it,begin))< *it ))
  {
    // swap
    std::iter_swap(it, parent(it,begin));
    it = parent(it,begin);
  }
}

template <typename It>
void siftDown(It it, It begin, It end)
{
  int len = std::distance(begin , end);
  if (len < 2) return;
  It maxIt = it;
  It currIt = it;
  while (true)
  {
    It leftIt = leftChild(currIt,begin);
    It rightIt = rightChild(currIt,begin);
    if ( leftIt < end )
    {
      if( *leftIt > *maxIt) maxIt = leftIt;
    }
    if ( rightIt < end )
    {
      if ( *rightIt > *maxIt) maxIt = rightIt;
    }
    if (maxIt != currIt)
    {
      std::iter_swap(currIt, maxIt);
      currIt = maxIt;
    }
    else
    {
      break;
    }
  }
}

template <typename It>
void buildHeap(It begin,It end)
{
  int length = std::distance(begin,end);
  if (length < 2) return;
  for(It it = parent(end-1,begin); it >= begin; it--)
  {
    siftDown(it, begin,end);
  }

}


template <typename It>
void heapSort(It begin,It end)
{
  int length = std::distance(begin,end);
  if (length < 2) return;

}

}

#endif // HEAPSORT_H
