//BST Implementation
#include "BST.h"
#include "BSTNode.h"
#include "Pokemon.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <typename itemtype, typename searchtype>
BST <itemtype, searchtype>::BST()
{
  m_root = nullptr;
}

template <typename itemtype, typename searchtype>
BST<itemtype, searchtype>::BST(const BST& Original)
{
  m_root = nullptr;
  recCopy(Original.m_root);
}

template <typename itemtype, typename searchtype>
BST<itemtype,searchtype> BST<itemtype, searchtype>::operator=(const BST& Original)
{
  this->m_root = nullptr;
  recCopy(Original.m_root);
  return(*(this));
}

template <typename itemtype, typename searchtype>
void BST<itemtype,searchtype>::recCopy(BSTNode<itemtype>* subtree)
{
  if (subtree != nullptr)
  {
    add(subtree->getEntry());
    recCopy(subtree->getLeft());
    recCopy(subtree->getRight());
  }
}

template <typename itemtype, typename searchtype>
BST <itemtype, searchtype>::~BST()
{
    recDelete(m_root);
}

template <typename itemtype, typename searchtype>
void BST<itemtype, searchtype>::recDelete(BSTNode<itemtype>* subtree)
{
  if (subtree != nullptr)
  {
    recDelete(subtree->getLeft());
    recDelete(subtree->getRight());
    delete subtree;
  }
}

template <typename itemtype, typename searchtype>
itemtype BST<itemtype, searchtype>::search (searchtype key) const
{
  int key_length = key.length();
  key[0] = toupper(key[0]);
  for (int i= 1; i<key_length; i++)
  {
    key[i] = tolower(key[i]);
  }
  try
  {
    return (recSearch (key, m_root));
  }
  catch(runtime_error& e)
  {
    cout << e.what();
    itemtype temp;
    return (temp);
  }
}

template <typename itemtype, typename searchtype>
bool BST<itemtype, searchtype>::isFound(itemtype key, BSTNode<itemtype>* subtree) const
{
    if (subtree->getEntry() == key)
    {
      return true;
    }
    if (subtree->getLeft()!= nullptr)
    {
      if(isFound(key,subtree->getLeft()))
      {
        return true;
      }
    }
    if (subtree->getRight()!= nullptr)
    {
      if(isFound(key,subtree->getRight()))
      {
        return true;
      }
    }
    return false;
}

template <typename itemtype, typename searchtype>
void BST<itemtype, searchtype>::remove (string word)
{
  if (m_root == nullptr)
  {
    throw (runtime_error("\nTree is Empty.\n\n"));
  }
  else
  {
    itemtype temp = search(word);
    if (temp != "0")
    {
      m_root = recRemove(temp, m_root);
    }
  }
}

template <typename itemtype, typename searchtype>
BSTNode<itemtype>* BST<itemtype, searchtype>::recRemove(itemtype temp, BSTNode<itemtype>* subtree)
{
  if (subtree == nullptr)
  {
    return subtree;
  }

  else if (subtree->getEntry() > temp)
  {
    BSTNode<itemtype>* Temp = recRemove(temp, subtree->getLeft());
    subtree->SetLeft(Temp);
  }
  else if (subtree->getEntry() < temp)
  {
    BSTNode<itemtype>* Temp =recRemove(temp, subtree->getRight());
    subtree->Setright(Temp);
  }
  else
  {
    subtree = itisEqual(subtree);
  }
  return subtree;
}

template <typename itemtype, typename searchtype>
BSTNode<itemtype>* BST<itemtype, searchtype>::itisEqual(BSTNode<itemtype>* subtree)
{
  if (subtree->getLeft() == nullptr && subtree->getRight() == nullptr)
  {
    delete subtree;
    subtree = nullptr;
  }
  else if (subtree->getLeft() == nullptr)
  {
    BSTNode<itemtype>* temp = subtree->getRight();
    delete subtree;
    return(temp);
  }
  else if (subtree->getRight() == nullptr)
  {
    BSTNode<itemtype>* temp = subtree->getLeft();
    delete subtree;
    return(temp);
  }
  else
  {
    BSTNode<itemtype>* temp = findmin(subtree->getRight());
    subtree->SetEntry(temp->getEntry());
    subtree->Setright(recRemove(temp->getEntry(),subtree->getRight()));
  }
  return (subtree);
}

template <typename itemtype, typename searchtype>
BSTNode<itemtype>* BST<itemtype, searchtype>::findmin (BSTNode<itemtype>* subtree)
{
  BSTNode<itemtype>* current = subtree;
  while (current->getLeft() != nullptr)
  {
    current = current->getLeft();
  }
  return (current);
}


template <typename itemtype, typename searchtype>
void BST<itemtype, searchtype>::add (itemtype item)
{
  if (m_root== nullptr)
  {
    m_root = new BSTNode<itemtype>(item);
  }
  else
  {
    if(!isFound(item,m_root))
    {
      recAdd(item, m_root);
    }
    else
    {
      throw(std::runtime_error("\nThe Pokemon you are trying to add is already on the list.\n\n"));
    }
  }
}

template <typename itemtype, typename searchtype>
void BST<itemtype, searchtype>::recAdd(itemtype item, BSTNode<itemtype>* Subtree)
{
  if (Subtree->getEntry() > item)
  {
    if (Subtree->getLeft() != nullptr)
    {
      recAdd(item, Subtree->getLeft());
    }
    else
    {
      BSTNode<itemtype>* temp = new BSTNode<itemtype> (item);
      Subtree->SetLeft(temp);
    }
  }
  else
  {
    if (Subtree->getRight() != nullptr)
    {
      recAdd(item, Subtree->getRight());
    }
    else
    {
      BSTNode<itemtype>* temp = new BSTNode<itemtype> (item);
      Subtree->Setright(temp);
    }
  }
}

template <typename itemtype, typename searchtype>
itemtype BST<itemtype, searchtype>::recSearch (searchtype key, BSTNode<itemtype>* Subtree) const
{
  if (Subtree == nullptr)
  {
    throw(std::runtime_error("\nThe Pokemon you are looking for is not in the Pokedex!\n\n"));
  }
  if (Subtree->getEntry() == key)
  {
    return (Subtree->getEntry());
  }
  else if (Subtree->getEntry() < key)
  {
    return(recSearch(key, Subtree->getRight()));
  }
  else
  {
    return (recSearch(key,Subtree->getLeft()));
  }
}

template <typename itemtype, typename searchtype>
void BST<itemtype,searchtype>::getinfo(BSTNode<itemtype>* subtree)
{
  outFile << subtree->getEntry().getAmericanName() << " ";
  outFile << subtree->getEntry().getPokedex() << " ";
  outFile << subtree->getEntry().getJapaName() << " ";
  outFile << endl;
}

template <typename itemtype, typename searchtype>
void BST<itemtype,searchtype>::Print()
{
  PrintToScreen(m_root);
}

template <typename itemtype, typename searchtype>
void BST<itemtype,searchtype>::PrintToScreen(BSTNode<itemtype>* subtree)
{
  if (subtree->getLeft()!= nullptr)
  {
    PrintToScreen(subtree->getLeft());
  }
  if (subtree!= nullptr)
  {
    cout << subtree->getEntry().getAmericanName() << " ";
    cout << subtree->getEntry().getPokedex() << " ";
    cout << subtree->getEntry().getJapaName() << " ";
    cout << endl;
  }
  if (subtree->getRight()!= nullptr)
  {
    PrintToScreen(subtree->getRight());
  }
}

template <typename itemtype, typename searchtype>
void BST<itemtype,searchtype>::recprintpreOrder(BSTNode<itemtype>* subtree)
{
  if (subtree!= nullptr)
  {
    getinfo(subtree);
  }
  if (subtree->getLeft()!= nullptr)
  {
    recprintpreOrder(subtree->getLeft());
  }
  if (subtree->getRight()!= nullptr)
  {
    recprintpreOrder(subtree->getRight());
  }
}

template <typename itemtype, typename searchtype>
void BST<itemtype,searchtype>::recprintinOrder(BSTNode<itemtype>* subtree)
{
  if (subtree->getLeft()!= nullptr)
  {
    recprintinOrder(subtree->getLeft());
  }
  if (subtree!= nullptr)
  {
    getinfo(subtree);
  }
  if (subtree->getRight()!= nullptr)
  {
    recprintinOrder(subtree->getRight());
  }
}

template <typename itemtype, typename searchtype>
void BST<itemtype,searchtype>::recprintpostOrder(BSTNode<itemtype>* subtree)
{
  if (subtree->getLeft()!= nullptr)
  {
    recprintpostOrder(subtree->getLeft());
  }
  if (subtree->getRight()!= nullptr)
  {
    recprintpostOrder(subtree->getRight());
  }
  if (subtree!= nullptr)
  {
    getinfo(subtree);
  }
}

template <typename itemtype, typename searchtype>
void BST<itemtype,searchtype>::printTree(string File, int order)
{
  if(m_root != nullptr)
  {
    cout << "\nThe Pokedex is saved to file: " << File << endl << endl;
    outFile.open(File);
    switch(order)
    {
      case 1:
      {
        outFile << "In-order Travesal Pokedex\n\n";
        recprintinOrder(m_root);
        break;
      }
      case 2:
      {
        outFile << "Pre-order Travesal Pokedex\n\n";
        recprintpreOrder(m_root);
        break;
      }
      case 3:
      {
        outFile << "Post-order Travesal Pokedex\n\n";
        recprintpostOrder(m_root);
        break;
      }
      outFile.close();
    }
  }
  else
  {
    cout << "\n\nThe Pokedex is Empty.\n\n";
  }
}
