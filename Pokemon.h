//POKEMON HEADER
#ifndef POKEMON_H
#define POKEMON_H
#include <string>
using namespace std;

class Pokemon
{
  private:
    string AmericanName;
    string JapaName;
    int pokedex;

  public:
    Pokemon();
    Pokemon(const Pokemon& Original);
    void SetAmericanName(string american);
    void SetJapaName(string japa);
    void SetPokedex(int pokeIndex);
    string getAmericanName() const;
    string getJapaName() const;
    int getPokedex() const;
    bool operator>(const Pokemon &item) const;
    bool operator<(const Pokemon &item) const;
    bool operator==(const Pokemon &item) const;
    bool operator==(const string &item) const;
    bool operator!=(const string &item) const;
    bool operator<(const string &item) const;
    bool operator>(const string &item) const;
};
#endif
