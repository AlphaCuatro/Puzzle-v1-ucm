#include "Main.h"
#include "JuegoPM.h"
#include "JuegoPM.cpp"
#include <iostream>

using namespace std;

void cargarArchivo(string nombreFichero, tMatrizChar& matrizInicial, tMatrizChar& matrizFinal, int& numAcciones, int filasMatrizInicial, int filasMatrizFinal, int columnasMatrizInicial, int columnasMatrizFinal);

void intToChar(tMatrizChar& matrizInicial, tMatrizChar matrizFinal, tMatrizChar& matrizInicialChar, tMatrizChar matrizFinalChar, int filasMatrizInicial, int filasMatrizFInal, int columnasMatrizInicial, int columnasMatrizFinal);

int main()
{


	switch (menu())
	{
	case 1: modo = 1; break;
	case 2: modo = 2; break;
	case 3: return 0;
	}
	cout << "" << endl;
	cout << "Nombre del fichero: " << endl;
	cin >> nombreFichero;

	if (modo == 1) { nombreFichero.append("_1D.txt"); }
	if (modo == 2) { nombreFichero.append("_2D.txt"); }

	cargarArchivo(nombreFichero, matrizInicial, matrizFinal, numAcciones, filasMatrizInicial, filasMatrizFinal, columnasMatrizInicial, columnasMatrizFinal);
	intToChar(matrizInicial, matrizFinal, matrizInicialChar, matrizFinalChar, filasMatrizInicial, filasMatrizFinal, columnasMatrizInicial, columnasMatrizFinal);
}
