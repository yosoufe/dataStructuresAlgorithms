/**
 * @brief General Tree class
 *
 * Tree traversal (Walking a tree):
 * Visit the nodes in particular order
 *    Depth-first
 *    Breadth-first
 */

#ifndef TREE_H
#define TREE_H

#include <queue>

template <typename T>
class tree
{
public:
  struct treeNode
  {
    T key;
    // vector of children
    treeNode* left;
    treeNode* right;
    treeNode() {}
  };
  tree();
private:
  treeNode* m_head;

  /**
   * @brief Depth-frist Traversal and print
   * @param tree  a pointer to the head of tree
   *
   * explore completely one subtree before
   * exploring its sibling.
   *
   * Recursive Implementation
   */
  void _inOrderTraversal(treeNode* tree)
  {
    if (tree == nullptr)
      return;
    inOrderTraversal(tree->left);
    print(tree->key);
    inOrderTraversal(tree->right);
  }

  void _preOrderTraversal(treeNode* tree)
  {
    if (tree == nullptr) return;
    print(tree->key);
    _preOrderTraversal(tree->left);
    _preOrderTraversal(tree->right);
  }

  /**
   * @brief Breadth first traversal
   * @param tree
   *
   * it is using the queue
   */
  void _levelTraversal(treeNode* tree)
  {
    if (tree==nullptr) return;
    std::queue<treeNode*> q;

    q.push(tree);
    while (!q.empty())
    {
      treeNode* node= q.front();
      q.pop();
      print(node);
      if(node->left != nullptr) q.push(node->left);
      if(node->right != nullptr) q.push(node->right);
    }
  }

public:
  int heigt();  // return 1 + max(height(left),height(right))
  int size();   // return 1 + size(left) + size(right)

  void print(T key)
  {
    (void)key;
  }

  /**
   * @brief Depth-frist Traversal and print recursively
   */
  void inOrderTraversal(){_inOrderTraversal(m_head);}

  /**
   * @brief preOrderTraversal
   */
  void preOrderTraversal(){_preOrderTraversal(m_head);}
  // TODO: PostOrderTraversal is missing

  /**
   * @brief breadth-first traversal
   */
  void levelTraversal(){_levelTraversal(m_head);}
};

#endif // TREE_H
