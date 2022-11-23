//MAIN
#include "Executive.h"
#include <iostream>
using namespace std;

int main (int argc, char** argv)
{
  if (argc !=2)
  {
    cout << "Invalid Number of Arguments.\n";
  }
  else
  {
    Executive Exec(argv[1]);
    Exec.run();
  }
  return (0);
}
