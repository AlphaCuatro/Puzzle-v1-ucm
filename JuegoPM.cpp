#include "JuegoPM.h"

void mainJuegoPM(tJuegoPM& jpm) {
	iniciar(jpm, jpm.modo);
	cargar(jpm);
	mostrar(jpm);
	if (jugar(jpm)) { accion(jpm); }
	else { menu(); }
}
int menu()
{
	int modo;
	int a;
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
		a = 1;
		break;
	case 2:
		a = 2;
		break;
	default:
		a = 3;
		break;
	}
	return a;
}
bool iniciar(tJuegoPM& jpm, std::string modo)
{
	std::string str;
	jpm.numAccionesRealizadas = 0;
	//Cambiar si sacamos el nombre del fichero de algún menú
	cout << "Nombre del fichero que quieras cargar: ";

	cin >> jpm.nombreFichero;
	cargar1(jpm);
	return true;
	
}
bool cargar1(tJuegoPM& jpm)
{
	tMatrizChar matriz1;
	jpm.archivo.open(jpm.nombreFichero);

	if (!jpm.archivo.is_open())
	{
		cout << "Error al leer el archivo";
	}

	// Modulo Matriz ----> cargar(tMatrizChar x, istream y) 

	cargar(jpm.matriz, jpm.archivo);
	return true;
}
void mostrar(tJuegoPM const& jpm)
{
	//MATRIZ
	// Imprime y espacia los numeros indicativos de la fila sobre la matriz
	cout << "   ";
	for (int num = 0; num < jpm.matriz.numFilas; num++)
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
	for (int f = 0; f < jpm.matriz.numFilas; f++)
	{
		
		for (int c = 0; c < jpm.matriz.numCols; c++)
		{
			cout << " " << c << " ";
			switch (jpm.matriz.elementos[f][c]) // negro(0), rojo(12), verde(10), azul(9), amarillo(14), magenta(13), cian2(3), blanco(15), gris(8), cian1(11) 
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
	// MATRIZ OBJETIVO
	// Imprime y espacia los numeros indicativos de la fila sobre la matriz
	cout << "   ";
	for (int num = 0; num < jpm.matriz.numFilas; num++)
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
	for (int f = 0; f < jpm.matrizObjetivo.numFilas; f++)
	{
		
		for (int c = 0; c < jpm.matrizObjetivo.numCols; c++)
		{
			cout << " " << c << " ";

			switch (jpm.matriz.elementos[f][c]) // negro(0), rojo(12), verde(10), azul(9), amarillo(14), magenta(13), cian2(3), blanco(15), gris(8), cian1(11) 
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


	if (jpm.numAccionesLimite > jpm.numAccionesRealizadas)
	{
		accion(jpm);
		return true;
	}
	else if (jpm.numAccionesLimite = jpm.numAccionesRealizadas)
	{
		cout << "Te has quedado sin movimientos!" << endl;
		return false;
	}

}
void accion(tJuegoPM& jpm)
{
	int a, b, c, d;
	std::string funcion;

	cout << "Comando: ";
	cin >> funcion >> a >> b >> c >> d;

	if (jpm.modo == 1)
	{
		if (funcion == "SF") { swapF(jpm.matriz, a, b); }
		else if (funcion == "SC") { swapC(jpm.matriz, a, b); }
		else if (funcion == "SD") { swapD(jpm.matriz, a); }
		else if (funcion == "VF") { voltearF(jpm.matriz, a); }
		else if (funcion == "VC") { voltearC(jpm.matriz, a); }
		else if (funcion == "VD") { voltearD(jpm.matriz, a); }
	}
	else if (jpm.modo == 2)
	{
		if (funcion == "VV") { voltearV(jpm.matriz); }
		else if (funcion == "VH") { voltearH(jpm.matriz); }
		else if (funcion == "RD") { rotarD(jpm.matriz); }
		else if (funcion == "SA")
		{
			tCoor e;
			tCoor f;

			e.x = a;
			e.y = b;
			f.x = c;
			f.y = d;
			swapAdy(jpm.matriz, e, f);
		}
		else if (funcion == "VD") { voltearD(jpm.matriz, a); }
	}
	else { cout << "Acción no válida"; }
}

//hacer un maincpp con llamada a mainjuegoPM