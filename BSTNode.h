//BST NODE HEADER
#ifndef BSTNODE_H
#define BSTNODE_H

template <typename itemtype>
class BSTNode
{
  private:
    itemtype m_entry;
    BSTNode<itemtype>* leftchild;
    BSTNode<itemtype>* rightchild;

  public:
    BSTNode(itemtype entry);
    void SetEntry(itemtype entry);
    void SetLeft(BSTNode<itemtype>* left);
    void Setright(BSTNode<itemtype>* right);
    BSTNode<itemtype>* getLeft();
    BSTNode<itemtype>* getRight();
    itemtype getEntry();
};
#include "BSTNode.cpp"
#endif
