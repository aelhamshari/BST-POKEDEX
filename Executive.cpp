//EXECUTIVE CLASS TO RUN THE POKEDEX
#include "Executive.h"
#include "Pokemon.h"
#include "BST.h"
#include "BSTNode.h"
#include "TreeTest.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

Executive::Executive(string f)
{
  filename = f;
}

Executive::~Executive()
{
}

void Executive::input()
{
  ifstream inFile;
  inFile.open(filename);
  string read = "0";
  while(!(inFile.eof()))
  {
    Pokemon NewPokemon;
    inFile >> read;
    NewPokemon.SetAmericanName(read);
    inFile >> read;
    NewPokemon.SetPokedex(stoi(read));
    inFile >> read;
    NewPokemon.SetJapaName(read);

    try
    {
      Poketree.add(NewPokemon);
    }
    catch (runtime_error& e)
    {
      e.what();
    }
  }
  inFile.close();
}
void Executive::run()
{
  input();
  interaction();
}

void Executive::PokeSearch()
{
  string Pokesearch = "0";
  cout << "\nEnter the american name of the pokemon: ";
  cin >> Pokesearch;
  Pokemon Result = Poketree.search(Pokesearch);
  if (Result.getJapaName() != "0")
  {
    cout << "\nHere is the Pokemon you searched for:\nPokemon American Name: "
          << Result.getAmericanName()
          << "\nPokemon Pokedex:  " << Result.getPokedex() 
          << "\nPokemon Japanese Name: " << Result.getJapaName() << endl << endl;
  }
}

void Executive::PokeSave(bool copyCreated)
{
  string filename = "0";
  int printorder = 0;
  int pokedextype = 0;
  cout << "\nOutput file name: ";
  cin >> filename;
  cout << "\nWhich pokedex:\n1)original\n2)copy\n";
  cout << "Pokedex Type: ";
  cin >> pokedextype;

  while (pokedextype < 1 or pokedextype > 2)
  {
    cout << "Please Enter a valid pokedex\nPokedex Type: ";
    cin >> pokedextype;
  }
  if (pokedextype == 2 && !(copyCreated))
  {
    cout << "\nYou have to create a copy first!\n\n";
    return;
  }

  cout << "\nchoose traversal order:\n1)inorder\n2)preorder\n3)postorder\n";
  cout << "Traversal order: ";
  cin >> printorder;
  while (printorder < 1 or printorder > 3)
  {
    cout << "Please Enter a valid print order\nTraversal order: ";
    cin >> printorder;
  }
  if (pokedextype ==1)
  {
    Poketree.printTree(filename,printorder);
  }
  else if (pokedextype == 2 && copyCreated)
  {
    PokeCopy.printTree(filename,printorder);
  }
}

void Executive::PokeAdd()
{
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

  Pokemon NewPokemon;
  NewPokemon.SetAmericanName(AmericanInput);
  NewPokemon.SetJapaName(JapaInput);
  NewPokemon.SetPokedex(IndexInput);
  
  try
  {
    PokeCopy.add(NewPokemon);
    cout << "\nThe pokemon is added to the copy tree.\n\n";
  }
  catch (runtime_error& e)
  {
    cout << e.what();
  }
}

void Executive::PokeRemove()
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
    PokeCopy.remove(PokeRemove);
  }
  catch (runtime_error& e)
  {
    cout << e.what();
  }
}

void Executive::TestBST()
{
  int testnumber = 0;
  cout << "\nWhich test do you want to run?\n1)Test Adds\n2)Test Removes\n3)Test write to file\n";
  cout << "Test: ";
  cin >> testnumber;

  while (testnumber < 1 || testnumber > 3)
  {
    cout << "Please Input a valid Test number\n:Test: ";
    cin >> testnumber;
  }

  TreeTest test;
  switch (testnumber)
  {
    case 1:
    {
      test.testAdds(Poketree);
      break;
    }
    case 2:
    {
      test.testRemoves(Poketree);
      break;
    }
    case 3:
    {
      test.testWriteToFile(Poketree);
      break;
    }
  }
  
}
void Executive::interaction()
{
  int choice = 0;
  bool copycreated = false;
  bool again = true;
  cout << "Welcome to The POKEDEX!!\n";
  do
  {
    cout << "Choose:\n1)Search\n2)Save\n3)Add\n4)Remove\n5)Copy\n6)Test\n7)Exit.\n";
    cout << "choice: ";
    cin >> choice;
    switch(choice)
    {
      case 1:
      {
        PokeSearch();
        break;
      }
    
      case 2:
      {
        PokeSave(copycreated);
        break;
      }

      case 3:
      {
        if (copycreated)
        {
          PokeAdd();
        }
        else
        {
          cout << "\nYou can't add new Pokemon until you create a copy.\n\n";
        }
        break;
      }
      case 4:
      {
        if (copycreated)
        {
          PokeRemove();
        }
        else
        {
          cout << "\nYou can't remove Pokemon until you create a copy.\n\n";
        }
        break;
      }
      case 5:
      {
        if (!copycreated)
        {
          PokeCopy = Poketree;
          cout << "\nA copy is made.\n\n";
          copycreated = true;
        }
        else
        {
          cout << "\nCopy already created!\n\n";
        }
        break;
      }
      case 6:
      {
        TestBST();
        break;
      }
      case 7:
      {
        again = false;
        break;
      }
      default:
        cout << "Enter a valid option 1-7\n\n";
    }
  }while (choice < 1 || choice > 7 || again);

}
