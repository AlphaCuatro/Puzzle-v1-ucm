#pragma once

#include "UtilidadesSYS.h"
#include "Matriz.h"
#include <iostream>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int DIM_MAX = 64;

struct tJuegoPM
{
	int numFilasMatriz;
	int numColumnasMatriz;
	tMatrizChar matriz;

	int numFilasMatrizObjetivo;
	int numColumnasMatrizObjetivo;
	tMatrizChar matrizObjetivo;

	int numAccionesRealizadas;
	int numAccionesLimite;

	string nombreFichero;
	ifstream archivo;
};
void mainJuegoPM();
int menu();
bool iniciar(tJuegoPM& jpm, string modo);
bool cargar(tJuegoPM& jpm);
void mostrar(tJuegoPM const& jpm);
bool jugar(tJuegoPM& jpm);
void accion(tJuegoPM& jpm);


//unificar tMatriz
typedef unsigned char tMatrizChar[DIM_MAX][DIM_MAX];