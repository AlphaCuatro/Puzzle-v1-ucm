#include "Main.h"

int main()
{
	tJuegoPM jpm;
	//MENU
	switch (menu())
	{
	case 1: jpm.modo = 1; break;
	case 2: jpm.modo = 2; break;
	case 3: jpm.modo = 3; break;
	case 4: return 0;
	}
	cout << "" << endl;
	
	//NOMBRE FICHERO
	cout << "Nombre del fichero: " << endl;
	cin >> jpm.nombreFichero;

	if (jpm.modo == 1) { jpm.nombreFichero.append("_1D.txt"); }
	if (jpm.modo == 2) { jpm.nombreFichero.append("_2D.txt"); }
	
	mainJuegoPM(jpm);
}
