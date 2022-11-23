Pokedex: main.o Executive.o Pokemon.o TreeTest.o
	g++ -g -std=c++11 -Wall main.o Executive.o Pokemon.o TreeTest.o -o Pokedex

main.o: main.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

Executive.o: Executive.cpp BST.h BST.cpp BSTNode.cpp BSTNode.h
	g++ -g -std=c++11 -Wall -c Executive.cpp

Pokemon.o: Pokemon.cpp
	g++ -g -std=c++11 -Wall -c Pokemon.cpp

TreeTest.o: TreeTest.cpp
	g++ -g -std=c++11 -Wall -c TreeTest.cpp

clean:
		rm *.o Poke
