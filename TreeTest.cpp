//TEST CLASS
#include "TreeTest.h"
#include <string>
#include "iostream"
using namespace std;


Pokemon* TreeTest::AddPokemon()
{
  Pokemon* NewPokemon = new Pokemon();
  string AmericanInput = "0";
  string JapaInput= "0";
  int IndexInput = 0;

  cout << "American Name: ";
  cin >> AmericanInput;

  AmericanInput[0] = toupper(AmericanInput[0]);
  for (int i= 1; i<AmericanInput.length(); i++)
  {
    AmericanInput[i] = tolower(AmericanInput[i]);
  }
  cout << "Pokedex Number: ";
  cin >> IndexInput;
  cout << "Japanese Name: ";
  cin >> JapaInput;

  JapaInput[0] = toupper(JapaInput[0]);
  for (int i= 1; i<JapaInput.length(); i++)
  {
    JapaInput[i] = tolower(JapaInput[i]);
  }
  NewPokemon->SetAmericanName(AmericanInput);
  NewPokemon->SetJapaName(JapaInput);
  NewPokemon->SetPokedex(IndexInput);

  return(NewPokemon);
}


void TreeTest::testAdds(BST<Pokemon, string> bst)
{
  Pokemon* NewPokemon = AddPokemon();
  try
  {
    bst.add(*NewPokemon);
    cout << "\nHere is the list after adding the Pokemon.\n\n";
    bst.Print();
    cout << endl;
  }
  catch (runtime_error& e)
  {
    cout << e.what();
  }
  delete NewPokemon;
}

void TreeTest::testRemoves(BST<Pokemon, string> bst)
{
  string PokeRemove;
  cout << "\nEnter the American Name of the Pokemon you want to remove: ";
  cin >> PokeRemove;

  PokeRemove[0] = toupper(PokeRemove[0]);
  for (int i= 1; i<PokeRemove.length(); i++)
  {
    PokeRemove[i] = tolower(PokeRemove[i]);
  }
  
  try
  {
    bst.remove(PokeRemove);
    cout << "\nHere is the list after removing the Pokemon.\n\n";
    bst.Print();
    cout << endl;
  }
  catch (runtime_error& e)
  {
    cout << e.what();
  }
}

void TreeTest::testWriteToFile(BST<Pokemon, string> bst)
{
  string File;
  cout << "\n outfile Name: ";
  cin >> File;
  bst.printTree(File, 1);
}
