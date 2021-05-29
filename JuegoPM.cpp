#include "JuegoPM.h"





void mainJuegoPM() {
	menu();

}
int menu()
{
	int modo;
	cout << "Elija cual de la versiones del juego desea ejecutar (cualquier opción no válida acabará con la ejecución del programa)" << endl;
	cout << "" << endl;
	cout << "1. Modo 1D" << endl;
	cout << "2. Modo 2D" << endl;
	cout << "3. Salir" << endl;
	cout << "" << endl;
	cout << "Opcion: ";
	cin >> modo;
	switch (modo)
	{
	case 1:
		return 1;
		break;
	case 2:
		return 2;
		break;
	default:
		return 3;
		break;
	}
	return 3;
}
bool iniciar(tJuegoPM& jpm, string modo)
{
	jpm.numAccionesRealizadas = 0;
	//Cambiar si sacamos el nombre del fichero de algún menú
	cout << "Nombre del fichero que quieras cargar: ";
	cin >> jpm.nombreFichero;
	//
	cargar(jpm);
}
bool cargar(tJuegoPM& jpm)
{
	tMatrizChar matriz;
	jpm.archivo.open(jpm.nombreFichero);

	if (!jpm.archivo.is_open())
	{
		cout << "Error al leer el archivo";
	}

	// Modulo Matriz ----> cargar(tMatrizChar x, istream y) 
	cargar(jpm.matriz, jpm.archivo);
}
void mostrar(tJuegoPM const& jpm)
{
	//MATRIZ
	// Imprime y espacia los numeros indicativos de la fila sobre la matriz
	cout << "   ";
	for (int num = 0; num < jpm.numFilasMatriz; num++)
	{
		if (num < 10)
		{
			cout << num << " ";
		}
		else if (num > 10)
		{
			cout << num;
		}
	}

	// Imprime el numero de fila y la fila
	for (int f = 0; f < jpm.numFilasMatriz; f++)
	{
		
		for (int c = 0; c < jpm.numColumnasMatriz; c++)
		{
			cout << " " << c << " ";
			switch (jpm.matriz[f][c]) // negro(0), rojo(12), verde(10), azul(9), amarillo(14), magenta(13), cian2(3), blanco(15), gris(8), cian1(11) 

			{
			case '0': colorCTA(0, 0);	cout << "  "; break;
			case '1': colorCTA(12, 12); cout << "  "; break;
			case '2': colorCTA(10, 10); cout << "  "; break;
			case '3': colorCTA(9, 9);	cout << "  "; break;
			case '4': colorCTA(14, 14); cout << "  "; break;
			case '5': colorCTA(13, 13); cout << "  "; break;
			case '6': colorCTA(11, 11); cout << "  "; break;
			case '7': colorCTA(15, 15); cout << "  "; break;
			}
		}
	}
	// MATRIZ OBJETIVO
	// Imprime y espacia los numeros indicativos de la fila sobre la matriz
	cout << "   ";
	for (int num = 0; num < jpm.numFilasMatriz; num++)
	{
		if (num < 10)
		{
			cout << num << " ";
		}
		else if (num > 10)
		{
			cout << num;
		}
	}

	// Imprime el numero de fila y los colores en la fila
	for (int f = 0; f < jpm.numFilasMatrizObjetivo; f++)
	{

		for (int c = 0; c < jpm.numColumnasMatrizObjetivo; c++)
		{
			cout << " " << c << " ";

			int a = jpm.matriz[f][c];
			switch (a) // negro(0), rojo(12), verde(10), azul(9), amarillo(14), magenta(13), cian2(3), blanco(15), gris(8), cian1(11) 
			{
			case 0: colorCTA(0, 0);	cout << "  "; break;
			case 1: colorCTA(12, 12); cout << "  "; break;
			case 2: colorCTA(10, 10); cout << "  "; break;
			case 3: colorCTA(9, 9);	cout << "  "; break;
			case 4: colorCTA(14, 14); cout << "  "; break;
			case 5: colorCTA(13, 13); cout << "  "; break;
			case 6: colorCTA(11, 11); cout << "  "; break;
			case 7: colorCTA(15, 15); cout << "  "; break;
			}
		}
	}
	cout << "Te quedan " << jpm.numAccionesLimite - jpm.numAccionesRealizadas << " movimientos." << endl;
}
bool jugar(tJuegoPM& jpm)
{
	int a, b;
	string funcion;

	if (jpm.numAccionesLimite > jpm.numAccionesRealizadas)
	{
		cout << "Comando: ";
		cin >> funcion >> a >> b;

		if (funcion == "SF") { swapF(jpm.matriz, a, b); }
		else if (funcion == "SC") { swapC(jpm.matriz, a, b); }
		else if (funcion == "SD") { swapD(jpm.matriz, a, b); }
		else if (funcion == "VF") { voltearF(jpm.matriz, a, b); }
		else if (funcion == "VC") {}
		else if (funcion == "") {}
		else if (funcion == "") {}
		else if (funcion == "") {}
		else if (funcion == "") {}
		else if (funcion == "") {}
		else if (funcion == "") {}
	}
	else if (jpm.numAccionesLimite = jpm.numAccionesRealizadas)
	{
		cout << "Te has quedado sin movimientos!" << endl;
	}
}
void accion(tJuegoPM& jpm)
{
	
}

//hacer un maincpp con llamada a mainjuegoPM