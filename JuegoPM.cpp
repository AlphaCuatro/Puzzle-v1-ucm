#include "JuegoPM.h"

void mainJuegoPM(tJuegoPM& jpm) {
	
	string modo;
	bool fin = false;

	if (jpm.modo == 1) { modo = "1"; }
	if (jpm.modo == 2) { modo = "2"; }
	if (jpm.modo == 3) {  }

	iniciar(jpm, modo);
	cargar1(jpm);

	while (jugar(jpm))
	{
			mostrar(jpm);
			jugar(jpm);
			accion(jpm);
			jpm.numAccionesRealizadas++;
	}
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
	case 3:
		a = 3;
		break;
	default:
		a = 0;
		break;
	}
	return a;
}
bool iniciar(tJuegoPM& jpm, std::string modo)
{
	std::string str;
	jpm.numAccionesRealizadas = 0;
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

	//cargar(jpm.matriz, jpm.archivo);

	jpm.archivo >> jpm.matriz.numFilas >> jpm.matriz.numCols;

	for (int f = 0; f < jpm.matriz.numFilas; f++)
	{
		for (int c = 0; c < jpm.matriz.numCols; c++)
		{
			jpm.archivo >> jpm.matriz.elementos[f][c];
		}
	}

	jpm.archivo >> jpm.matrizObjetivo.numFilas >> jpm.matrizObjetivo.numCols;


	for (int f = 0; f < jpm.matriz.numFilas; f++)
	{
		for (int c = 0; c < jpm.matriz.numCols; c++)
		{
			jpm.archivo >> jpm.matrizObjetivo.elementos[f][c];
		}
	}
	jpm.archivo >> jpm.numAccionesLimite;

	return true;
}
void mostrar(tJuegoPM const& jpm)
{
	borrar();
	
	//MATRIZ
	// Imprime y espacia los numeros indicativos de la fila sobre la matriz
	cout << "   ";
	for (int num = 0; num < jpm.matriz.numFilas; num++)
	{
		if (num < 10)
		{
			cout << num << " ";
		}
		else if (num >= 10)
		{
			cout << num;
		}
	}
	cout << endl;
	// Imprime el numero de fila y la fila
	for (int f = 0; f < jpm.matriz.numFilas; f++)
	{
		colorCTA(7, 0);
		cout << " " << f << " ";
		for (int c = 0; c < jpm.matriz.numCols; c++)
		{

			if (jpm.matriz.elementos[f][c] == '0') { colorCTA(0, 0); cout << "  "; }
			if (jpm.matriz.elementos[f][c] == '1') { colorCTA(1, 1); cout << "  "; }
			if (jpm.matriz.elementos[f][c] == '2') { colorCTA(2, 2); cout << "  "; }
			if (jpm.matriz.elementos[f][c] == '3') { colorCTA(3, 3); cout << "  "; }
			if (jpm.matriz.elementos[f][c] == '4') { colorCTA(4, 4); cout << "  "; }
			if (jpm.matriz.elementos[f][c] == '5') { colorCTA(5, 5); cout << "  "; }
			if (jpm.matriz.elementos[f][c] == '6') { colorCTA(6, 6); cout << "  "; }
			if (jpm.matriz.elementos[f][c] == '7') { colorCTA(7, 7); cout << "  "; }
			if (jpm.matriz.elementos[f][c] == '8') { colorCTA(8, 8); cout << "  "; }
			if (jpm.matriz.elementos[f][c] == '9') { colorCTA(9, 9); cout << "  "; }
		}
		cout << endl;
		colorCTA(7, 0);
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
		else if (num >= 10)
		{
			cout << num;
		}
	}
	cout << endl;
	// Imprime el numero de fila y los colores en la fila
	for (int f = 0; f < jpm.matrizObjetivo.numFilas; f++)
	{
		cout << " " << f << " ";
		for (int c = 0; c < jpm.matrizObjetivo.numCols; c++)
		{
			if (jpm.matrizObjetivo.elementos[f][c] == '0') { colorCTA(0, 0); cout << "  "; }
			if (jpm.matrizObjetivo.elementos[f][c] == '1') { colorCTA(1, 1); cout << "  "; }
			if (jpm.matrizObjetivo.elementos[f][c] == '2') { colorCTA(2, 2); cout << "  "; }
			if (jpm.matrizObjetivo.elementos[f][c] == '3') { colorCTA(3, 3); cout << "  "; }
			if (jpm.matrizObjetivo.elementos[f][c] == '4') { colorCTA(4, 4); cout << "  "; }
			if (jpm.matrizObjetivo.elementos[f][c] == '5') { colorCTA(5, 5); cout << "  "; }
			if (jpm.matrizObjetivo.elementos[f][c] == '6') { colorCTA(6, 6); cout << "  "; }
			if (jpm.matrizObjetivo.elementos[f][c] == '7') { colorCTA(7, 7); cout << "  "; }
			if (jpm.matrizObjetivo.elementos[f][c] == '8') { colorCTA(8, 8); cout << "  "; }
			if (jpm.matrizObjetivo.elementos[f][c] == '9') { colorCTA(9, 9); cout << "  "; }
		}
		cout << endl;
		colorCTA(7, 0);
	}
	cout << endl;
	cout << "Te quedan " << jpm.numAccionesLimite - jpm.numAccionesRealizadas << " movimientos." << endl;
	cout << endl;
}
bool jugar(tJuegoPM& jpm)
{
	if (jpm.matriz == jpm.matrizObjetivo)
	{
		borrar();
		cout << "Felicidades! Has ganado la partida!";
		return false;
	}
	if (jpm.numAccionesLimite == jpm.numAccionesRealizadas)
	{
		borrar();
		cout << "Te has quedado sin movimientos! Intentalo de nuevo";
		pausa();
		return false;
	}
	else return true;
}
void accion(tJuegoPM& jpm)
{
	int a, b, c, d;
	string funcion;

	cout << "Comando: ";
	cin >> funcion;

	if (jpm.modo == 1)
	{
		if (funcion == "SF") { 
			cin >> a >> b;
			swapF(jpm.matriz, a, b); 
		}
		else if (funcion == "SC") { 
			cin >> a >> b;
			swapC(jpm.matriz, a, b); 
		}
		else if (funcion == "SD") { 
			cin >> a;
			swapD(jpm.matriz, a); 
		}
		else if (funcion == "VF") { 
			cin >> a;
			voltearF(jpm.matriz, a); 
		}
		else if (funcion == "VC") { 
			cin >> a;
			voltearC(jpm.matriz, a); 
		}
		else if (funcion == "VD") {
			cin >> a;
			voltearD(jpm.matriz, a); 
		}
	}
	else if (jpm.modo == 2)
	{
		if (funcion == "VV") { 
			voltearV(jpm.matriz); 
		}
		else if (funcion == "VH") { 
			voltearH(jpm.matriz); 
		}
		else if (funcion == "RD") { 
			rotarD(jpm.matriz); 
		}
		else if (funcion == "SA"){
			cin >> a >> b >> c >> d;
			tCoor e;
			tCoor f;

			e.x = a;
			e.y = b;
			f.x = c;
			f.y = d;
			swapAdy(jpm.matriz, e, f);
		}
		else if (funcion == "VD") { 
			cin >> a;
			voltearD(jpm.matriz, a); 
		}
	}
	else { cout << "Acción no válida"; }
}

