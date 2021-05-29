#ifndef MATRIZ_H
#define	MATRIZ_H

#include <iostream>
#include <fstream>
#include "Coordenada.h"

using namespace std;
//cambiar pragma once por if load

const int MAX_DIM = 10;

typedef struct {
	int numFilas, numCols;
	//uint8
	uint8 elementos[MAX_DIM][MAX_DIM];
} tMatrizChar;

bool swapF(tMatrizChar& matriz, int f1, int f2);
bool swapC(tMatrizChar& matriz, int c1, int c2);
void rotarD(tMatrizChar& matriz);
bool voltearF(tMatrizChar& matriz, int f);
bool voltearC(tMatrizChar& matriz, int c);
void voltearV(tMatrizChar& matriz);
void voltearH(tMatrizChar& matriz);
bool swapD(tMatrizChar& matriz, int d);
bool voltearD(tMatrizChar& matriz, int d);
bool operator == (tMatrizChar const& mat1, tMatrizChar const& mat2);
bool swap(tMatrizChar& matriz, tCoor pos1, tCoor pos2);
bool voltearID(tMatrizChar& matriz);
bool swapAdy(tMatrizChar& matriz, tCoor pos1, tCoor pos2);
bool cargarMatriz(tMatrizChar& matriz, istream& ent);

#endif