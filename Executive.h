//Executive Class HEADER
#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Pokemon.h"
#include "BST.h"
#include "BSTNode.h"
#include <string>
using namespace std;

class Executive
{
  private:
    string filename;
    BST<Pokemon,string> Poketree;
    BST<Pokemon,string> PokeCopy;

  public:
    Executive(string f);
    ~Executive();
    void run();
    void input();
    void PokeSearch();
    void PokeSave(bool copyCreated);
    void PokeAdd();
    void PokeRemove();
    void TestBST();
    void interaction();
};
#endif
