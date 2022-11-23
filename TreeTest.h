//TEST HEADER
#ifndef TREE_TEST_H
#define TREE_TEST_H
#include "BST.h"
#include "Pokemon.h"
#include <string>
using namespace std;


class TreeTest
{
  private:
    Pokemon* AddPokemon();
  public:
    void testAdds(BST<Pokemon, string> bst);
    void testRemoves(BST<Pokemon, string> bst);
    void testWriteToFile(BST<Pokemon, string> bst);
};
#endif
