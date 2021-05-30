#ifndef JUEGOPM_H
#define JUEGOPM_H

#include "UtilidadesSYS.h"
#include "Matriz.h"
using namespace std;

const int DIM_MAX = 64;

struct tJuegoPM
{
	int modo;
	struct tMatrizChar matriz;
	struct tMatrizChar matrizObjetivo;

	int numAccionesRealizadas;
	int numAccionesLimite;

	std::string nombreFichero;
	ifstream archivo;
};

void mainJuegoPM(tJuegoPM& jpm);
int menu();
bool iniciar(tJuegoPM& jpm, std::string modo);
bool cargar1(tJuegoPM& jpm);
void mostrar(tJuegoPM const& jpm);
bool jugar(tJuegoPM& jpm);
void accion(tJuegoPM& jpm);

#endif