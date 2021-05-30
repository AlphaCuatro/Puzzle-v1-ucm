#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include "Matriz.h"
using namespace std;

struct tPuzzle
{
	string nombrePuzzle;
	string nombreFichero;
	int tipoPuzzle;
	int numMaxMovs;
	tMatrizChar matriz;
	tMatrizChar matrizFinal;
};

#endif