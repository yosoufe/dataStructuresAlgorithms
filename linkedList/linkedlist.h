#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define ERROR   -1

class LinkedList
{
  struct node{
    double key;
    node* nextNode;
    node():key(0),nextNode(nullptr){}
  };

private:
  node* m_head;

public:
  LinkedList():m_head(nullptr){}

//  PushFront(Key)            add to front
//  Key TopFront()            return front item
//  PopFront()                remove and return front item (first)
//  PushBack(Key)             add to back
//  Key TopBack()             return back item
//  PopBack()                 remove and return back item (last)
//  Boolean Find(Key)         is key in list?
//  Erase(Key)                remove key from list
//  Boolean Empty()           empty list?
//  AddBefore(Node, Key)      adds key before node // Not Yet Implemented
//  AddAfter(Node, Key)       adds key after node  // Not Yet Implemented

  void pushFront(double key)
  {
    node* newElement = new node();
    newElement->nextNode = m_head;
    m_head = newElement;
    newElement->key = key;
  }

  //  Key TopFront()            return front item
  double topFront()
  {
    if (m_head!=nullptr) return ERROR;
    return m_head->key;
  }

  //  PopFront()                remove and return front item
  double popFront()
  {
    if(isEmpty())return ERROR;
    double keyToReturn = m_head->key;
    node* toRemove = m_head;
    m_head = m_head->nextNode;
    delete toRemove;
    return keyToReturn;
  }

  //  PushBack(Key)             add to back
  void pushBack(double key)
  {
    if(m_head == nullptr){this->pushFront(key);return;}
    node* curr = m_head;
    while(curr->nextNode != nullptr) curr = curr->nextNode;
    // now curr is pointing to the last node
    curr->nextNode = new node();
    curr->nextNode->key = key;
  }

  //  Key TopBack()             return back item
  double topBack()
  {
    if(m_head == nullptr)return ERROR;
    node* curr = m_head;
    while(curr->nextNode != nullptr) curr = curr->nextNode;
    // now curr is pointing to the last node
    return curr->key;
  }

  //  PopBack()                 remove and return back item
  double PopBack()
  {
    if(m_head == nullptr)return ERROR;
    node* curr = m_head;
    node** ptr2PrevNextNode = &m_head;
    double toRetrun;
    while(curr->nextNode != nullptr)
    {
      ptr2PrevNextNode = &curr->nextNode;
      curr = curr->nextNode;
    }
    // now curr is pointing to the last node
    // and ptr2PrevNextNode is pointing to the pointer that is
    // pointing to the last node (the one that should become nullptr)
    *ptr2PrevNextNode = nullptr;
    toRetrun = curr->key;
    delete curr;
    return toRetrun;
  }

  //  Boolean Find(Key)         is key in list?
  bool find(double key)
  {
    if(m_head == nullptr)return false;
    node* curr = m_head;
    do{
      if(curr->key == key) return true;
      curr = curr->nextNode;
    }while(curr != nullptr);
    return false;
  }

  //  Erase(Key)                remove key from list
  void erase(double key)
  {
    node* curr = m_head;
    node** ptr2PrevNextNode = &m_head;
    while(curr != nullptr)
    {
      if(curr->key == key)
      {
        *ptr2PrevNextNode = curr->nextNode;
        delete curr;
        return;
      }
      ptr2PrevNextNode = &curr->nextNode;
      curr = curr->nextNode;
    }
  }

  bool isEmpty()
  {
    return (m_head == nullptr);
  }
};

#endif // LINKEDLIST_H
