#include "ListaPuzzles.h"

void inicializar(tPuzzlesReunidos& jr){}
bool cargar(tPuzzlesReunidos& jr)
{
	ifstream archivo;
	archivo.open("datosPuzzles.txt");

	if (!archivo.is_open())
	{
		cout << "Error al cargar la lista de puzzles";
		return false;
	}
	
	else if (archivo.is_open())
	{
		int numPuzzles;
		archivo >> numPuzzles;
		jr->cont = numPuzzles;

		for (int a = 0; a < 2; a++)
		{
			for (int b = 0; b < numPuzzles; b++)
			{
				// Excepción de memoria (ni idea de cómo arreglarlo, he estado horas aquí)
				archivo >> jr[a].listas[b]->nombrePuzzle;
				archivo >> jr[a].listas[b]->nombreFichero;
			}
		}

		for (int i = 0; i < 0; i++)
		{
			for (int j = 0; j < numPuzzles; j++)
			{
				cout << jr[i].listas[j]->nombrePuzzle;
				cout << jr[i].listas[j]->nombreFichero;
			}
		}
		archivo.close();
		return true;
	}
}
void guardar(const tPuzzlesReunidos& listas)
{
	int numPuzzles;

	ifstream archivo;
	archivo.open("datosPuzzles.txt");
	archivo >> numPuzzles;
	archivo.close();

	ofstream archivo;
	archivo.open("listaPuzzles.txt");

	if (archivo.is_open())
	{
		for (int a = 0; a < 2; a++)
		{
			for (int b = 0; b < numPuzzles; b++)
			{
				archivo << listas[a].listas[b]->nombrePuzzle;
				archivo << listas[a].listas[b]->nombreFichero;
			}
		}
	}
}
int elegirPuzzle(tListaPuzzles& lp)
{
	int opcion;

	cout << "En esta versión están disponibles los siguientes retos:" << endl;
	cout << endl;

	for (int a = 0; a < lp.cont; a++)
	{
		cout << a + 1 << ". " << lp.listas[a]->nombrePuzzle << " con un número máximo de " << lp.listas[a]->numMaxMovs << " movimientos" << endl;
	}
	cout << endl;
	cout << "0. Salir" << endl;
	cout << "-1. Ordenar la lista de mayor a menor" << endl;
	cout << "-2. Ordenar la lista de menor a mayor" << endl;
	cout << endl;
	cout << endl;

	cin >> opcion;
	return opcion;
}
bool insertarOrdenado(tListaPuzzles& l, tPuzzle* p) {} // No posible realizar inserciones sin implementacion correcta del tipo
bool buscar(const tListaPuzzles& lista, tPuzzle* puzzle, int& pos) {} // No posible realizar busquedas sin implementacion correcta del tipo 