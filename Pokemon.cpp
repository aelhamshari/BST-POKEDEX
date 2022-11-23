//POKEMON IMPELEMENTATION
#include "Pokemon.h"
#include <string>
using namespace std;

Pokemon::Pokemon()
{
  AmericanName = "0";
  JapaName = "0";
  pokedex = 0;
}

Pokemon::Pokemon(const Pokemon& Original)
{
  this->SetAmericanName(Original.getAmericanName());
  this->SetJapaName(Original.getJapaName());
  this->SetPokedex(Original.getPokedex());
}

bool Pokemon::operator>(const Pokemon &item) const
{
  if (this->getAmericanName() > item.getAmericanName())
  {
    return (true);
  }
  return(false);
}

bool Pokemon::operator<(const Pokemon &item) const
{
  if (this->getAmericanName() < item.getAmericanName())
  {
    return (true);
  }
  return(false);
}

bool Pokemon::operator==(const Pokemon &item) const
{
  if (this->getAmericanName() == item.getAmericanName())
  {
    return (true);
  }
  else if (this->getJapaName() == item.getJapaName())
  {
    return (true);
  }
  if (this->getPokedex() == item.getPokedex())
  {
    return (true);
  }
  return(false);
}

bool Pokemon::operator==(const string &item) const
{
  if (this->getAmericanName() == item)
  {
    return (true);
  }
  return(false);
}

bool Pokemon::operator!=(const string &item) const
{
  if (this->getAmericanName() != item)
  {
    return (true);
  }
  return(false);
}

bool Pokemon::operator<(const string &item) const
{
  if (this->getAmericanName() < item)
  {
    return (true);
  }
  return(false);
}

bool Pokemon::operator>(const string &item) const
{
  if (this->getAmericanName() > item)
  {
    return (true);
  }
  return(false);
}

void Pokemon::SetAmericanName(string american)
{
  AmericanName = american;
}

void Pokemon::SetJapaName(string japa)
{
  JapaName = japa;
}

void Pokemon::SetPokedex(int pokeIndex)
{
  pokedex = pokeIndex;
}

string Pokemon::getAmericanName() const
{
  return (AmericanName);
}

string Pokemon::getJapaName() const
{
  return (JapaName);
}

int Pokemon::getPokedex() const
{
  return (pokedex);
}
