//BST Node Implementation
#include "BSTNode.h"

template <typename itemtype>
BSTNode<itemtype>::BSTNode(itemtype entry)
{
  m_entry = entry;
  leftchild = nullptr;
  rightchild = nullptr;
}

template <typename itemtype>
void BSTNode<itemtype>::SetEntry(itemtype entry)
{
  m_entry = entry;
}

template <typename itemtype>
void BSTNode<itemtype>::SetLeft(BSTNode<itemtype>* left)
{
  leftchild = left;
}

template <typename itemtype>
void BSTNode<itemtype>::Setright(BSTNode<itemtype>* right)
{
  rightchild = right;
}

template <typename itemtype>
BSTNode<itemtype>* BSTNode<itemtype>::getLeft()
{
  return(leftchild);
}

template <typename itemtype>
BSTNode<itemtype>* BSTNode<itemtype>::getRight()
{
  return(rightchild);
}

template <typename itemtype>
itemtype BSTNode<itemtype>::getEntry()
{
  return(m_entry);
}
