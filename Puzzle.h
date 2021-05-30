#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
using namespace std;

struct tPuzzle
{
	string nombrePuzzle;
	string nombreFichero;
	int tipoPuzzle;
	int numMaxMovs;
	struct tMatriz;
	struct tMatrizFinal;
};

#endif