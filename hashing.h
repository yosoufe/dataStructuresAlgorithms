#ifndef HASHING_H
#define HASHING_H

#include <list> // doubly linked list for chaining
#include <random>
#include <cmath>

/*
 *
 */

template <typename Key, typename Value>
class hashMap
{
  struct name
  {
    name() {}
  };

  typedef struct hashNode
  {
    Key key;
    Value value;
    hashNode(){}
    hashNode(Key k, Value v):key(k),value(v){}
  }hashNode;

private:
  int m_prime = 10000019;
  std::vector<std::list<hashNode>> m_dataStructure;

/***** for hashing integer *******
 * Universal Family:
 * h_{p}^{a,b}(x) = ( (ax+b) mod p ) mod m
 */
  int m_a, m_b;
  size_t m_m;

  inline unsigned int hashing(int key){return  ( ((m_a * key + m_b) % m_prime) % m_m ); }
  inline unsigned int hashing(unsigned int key){return  ( ((m_a * key + m_b) % m_prime) % m_m ); }

/***** for hashing String *******
 * Universal Family (polynomial):
 * h_p^x = ( sigma_{i=0}^{|S|-1} S[i]x^i ) mod p
 */
  int m_str_x;

  inline int hashing(std::string key){
    unsigned int hash = 0;
    for (int unsigned i = 0; i < key.size(); i++)
    {
      const char& c = key[i];
      hash += int( (c * std::pow(m_str_x,i)) ) % m_prime;
    }
    return hashing(hash % m_prime); // call int hashing function
  }


public:
  hashMap(size_t siz = 32):
    m_a( std::rand()%(m_prime-1)+1    ),
    m_b( std::rand()%(m_prime+1)      ),
    m_str_x( std::rand()%(m_prime+1) ),
    m_m( siz )
  {
    m_dataStructure.resize(m_m);
  }



  void add(Key key, Value value)
  {
    // hashing
    int idx = hashing(key);
    bool found = false;
    std::list<hashNode>& chain = m_dataStructure[idx];
    typename std::list<hashNode>::iterator it;
    for ( it = chain.begin();
          it != chain.end();
          it++)
    {
      hashNode& node = *it;
      if(node.key == key)
      {
        node.value = value;
        found = true;
      }
    }
    if (!found) chain.push_front(hashNode(key,value));
  }

  hashNode* find(Key key)
  {
    int idx = hashing(key);
    std::list<hashNode>& chain = m_dataStructure[idx];
    typename std::list<hashNode>::iterator it;
    for ( it = chain.begin();
          it != chain.end();
          it++)
    {
      hashNode& node = *it;
      if(node.key == key)
      {
        return &(node);
      }
    }
    return this->end();
  }

  hashNode* end(){
    std::list<hashNode>& end = m_dataStructure.back();
    hashNode& end2 = *end.end();
    return (&end2);
  }

  void remove(Key key)
  {
    int idx = hashing(key);
    std::list<hashNode>& chain = m_dataStructure[idx];
    typename std::list<hashNode>::iterator it;
    for ( it = chain.begin();
          it != chain.end();
          it++)
    {
      if(it->key == key)
      {
        chain.erase(it);
        return;
      }
    }
  }
};

#endif // HASHING_H
