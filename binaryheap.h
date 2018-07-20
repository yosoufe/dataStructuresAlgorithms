#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <vector>
#include <limits>

template <typename T>
class BinaryHeap
{
protected:
  std::vector<T> m_arr;
  int m_size;

  /**
   * @brief returns the index of the parent
   * @param idx
   * @return the index of the parent
   */
  int parent(int idx){return(idx-1)/2;}

  /**
   * @brief leftChild
   * @param idx
   * @return the left child
   */
  int leftChild(int idx){return 2*(idx+1)-1;}
  int rightChild(int idx){return 2*(idx+1);}

  void swap(int idx1, int idx2)
  {
    T temp = m_arr[idx1];
    m_arr[idx1] = m_arr[idx2];
    m_arr[idx2] = temp;
  }

  void siftUp(int idx)
  {
    while (idx>0 && ( m_arr[parent(idx)] < m_arr[idx] ))
    {
      // swap
      swap(idx, parent(idx));
      idx = parent(idx);
    }
  }

  void siftDown(int idx)
  {
    int maxIdx = idx;
    while (true)
    {
      int leftIdx = leftChild(idx);
      int rightIdx = rightChild(idx);
      if ( leftIdx < m_size )
      {
        if(m_arr[leftIdx] > m_arr[maxIdx]) maxIdx = leftIdx;
      }
      if ( rightIdx < m_size )
      {
        if (m_arr[rightIdx] > m_arr[maxIdx]) maxIdx = rightIdx;
      }
      if (maxIdx != idx)
      {
        swap(idx, maxIdx);
        idx = maxIdx;
      }
      else
      {
        break;
      }
    }
  }

public:
  BinaryHeap() {}

  /**
   * @brief inserts an element inside the heap binary tree
   * @param node is the element to be inserted
   */
  void insert(T node)
  {
    if(m_size == m_arr.size()) m_arr.push_back(node);
    else m_arr[m_size] = node;
    siftUp(m_size);
    m_size += 1;
  }

  /**
   * @brief returns and removes the max value from the heap
   * @return the maximum element
   */
  T extractMax()
  {
    T res = m_arr[0];
    m_arr[0] = m_arr[m_size-1];
    m_size -= 1;
    siftDown(0);
    return  res;
  }

  /**
   * @brief gets the maximum value
   * @return the max
   */
  T getMax(){return m_arr[0];}

  /**
   * @brief removes the element at index idx
   * @param idx
   */
  void remove(int idx)
  {
    m_arr[idx] = std::numeric_limits<T>::max();
    siftUp(idx);
    extractMax();
  }

  /**
   * @brief changes the priority of node idx to the value val
   * @param idx
   * @param val
   */
  void changePriority (int idx, T val)
  {
    T oldVal = m_arr[idx];
    m_arr[idx]= val;
    if (val > oldVal)
      siftUp(idx);
    else
      siftDown(idx);
  }
};

#endif // BINARYHEAP_H
