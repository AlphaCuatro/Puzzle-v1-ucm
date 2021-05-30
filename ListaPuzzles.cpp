#include "ListaPuzzles.h"

void inicializar(tPuzzlesReunidos& jr)
{
	
}
bool cargar(tPuzzlesReunidos& jr)
{
	ifstream archivo;
	archivo.open("datosPuzzles.txt");

	if (!archivo.is_open())
	{
		cout << "Error al cargar la lista de puzzles";
		return false;
	}
	/*
	else
	{
		for (int a = 0; a < 2; a++)
		{
			for (int b = 0; b < MAX_PUZZLES; b++)
			{
				archivo >> jr[a][b].nombrePuzzle;
				archivo >> jr[a][b].nombreFichero;
				archivo >> jr[a][b].tipoPuzzle;
				archivo >> jr[a][b].numMaxMovs;
				archivo >> jr[a][b].matriz.numFilas;
				archivo >> jr[a][b].matriz.numCols;
				
				for (int i = 0; i < jr[a][b].matriz.numFilas; i++)
				{
					for (int j = 0; j < jr[a][b].matriz.numCols; j++)
					{
						archivo >> jr[a][b].matriz.elementos[i][j];
						cout << jr[a][b].matriz.elementos[i][j];

					}
				}
				archivo >> jr[a][b].matrizFinal.numFilas;
				archivo >> jr[a][b].matrizFinal.numCols;
				for (int i = 0; i < jr[a][b].matrizFinal.numFilas; i++)
				{
					for (int j = 0; j < jr[a][b].matrizFinal.numCols; j++)
					{
						archivo >> jr[a][b].matrizFinal.elementos[i][j];
						cout << jr[a][b].matrizFinal.elementos[i][j];
					}
				}
				
			}
		}
		
		return true;
	}
	*/
}
void guardar(const tPuzzlesReunidos& listas)
{
	ifstream archivo;
	archivo.open("listaPuzzles.txt");

	for (int a = 0; a < 2; a++)
	{
		for (int b = 0; b < MAX_PUZZLES; b++)
		{
			
			cout << "." << listas[a][b].nombreFichero << "." << endl;
		}
	}
}