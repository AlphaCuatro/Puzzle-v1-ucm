#ifndef MATRIZ_H
#define	MATRIZ_H

#include <iostream>
#include <fstream>
#include "Coordenada.h"
#include "UtilidadesSYS.h"

using namespace std;
//cambiar pragma once por if load

const int MAX_DIM = 64;

struct tMatrizChar
{
	int numFilas;
	int numCols;
	uint8 elementos[MAX_DIM][MAX_DIM];
};
bool operator == (tMatrizChar const& mat1, tMatrizChar const& mat2);

bool swapF(tMatrizChar& matriz, int f1, int f2);
bool swapC(tMatrizChar& matriz, int c1, int c2);
void rotarD(tMatrizChar& matriz);
bool voltearF(tMatrizChar& matriz, int f);
bool voltearC(tMatrizChar& matriz, int c);
void voltearV(tMatrizChar& matriz);
void voltearH(tMatrizChar& matriz);
bool swapD(tMatrizChar& matriz, int d);
bool voltearD(tMatrizChar& matriz, int d);
bool swap(tMatrizChar& matriz, tCoor pos1, tCoor pos2);
bool voltearID(tMatrizChar& matriz);
bool swapAdy(tMatrizChar& matriz, tCoor pos1, tCoor pos2);
bool cargar(tMatrizChar& matriz, istream& ent);

#endif