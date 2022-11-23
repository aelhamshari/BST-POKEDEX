//BST Header
#ifndef BST_H
#define BST_H
#include "BSTNode.h"
#include <fstream>
#include <stdexcept>
using namespace std;

template <typename itemtype, typename searchtype>
class BST
{
  private:
    BSTNode <itemtype>* m_root;
    ofstream outFile;
    itemtype recSearch (searchtype key, BSTNode<itemtype>* Subtree) const; // catches the error from the public searchtype
    void recAdd(itemtype item, BSTNode<itemtype>* Subtree);
    BSTNode<itemtype>* recRemove(itemtype temp, BSTNode<itemtype>* subtree);
    bool isFound(itemtype key, BSTNode<itemtype>* subtree) const;
    void recCopy(BSTNode<itemtype>* subtree);
    void recDelete(BSTNode<itemtype>* subtree);
    void PrintToScreen(BSTNode<itemtype>* subtree);
    void recprintpreOrder(BSTNode<itemtype>* subtree);
    void recprintinOrder(BSTNode<itemtype>* subtree);
    void recprintpostOrder(BSTNode<itemtype>* subtree);
    void getinfo(BSTNode<itemtype>* subtree);
    BSTNode<itemtype>* findmin(BSTNode<itemtype>* subtree);
    BSTNode<itemtype>* itisEqual(BSTNode<itemtype>* subtree);

  public:
    BST();
    ~BST();
    BST(const BST<itemtype,searchtype>& Original);
    BST<itemtype,searchtype> operator=(const BST<itemtype,searchtype>& Original);
    itemtype search (searchtype key) const;
    void add (itemtype item);
    void remove (string word);
    void printTree(string File, int order);
    void Print();
};
#include "BST.cpp"
#endif
