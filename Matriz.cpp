#include "Matriz.h"

bool swapF(tMatrizChar& matriz, int f1, int f2) {
	int aux = 0;
	if (f1 < 0 || f1 >= matriz.numFilas || f2 < 0 || f2 >= matriz.numFilas) {
		return false;
	}
	else {
		if (f1 != f2) {
			for (int c = 0; c < matriz.numCols; ++c) {
				//swap
				aux = matriz.elementos[f1][c];
				matriz.elementos[f1][c] = matriz.elementos[f2][c];
				matriz.elementos[f2][c] = aux;
			}
			return true;
		}
	}
}
bool swapC(tMatrizChar& matriz, int c1, int c2) {
	int aux = 0;
	if (c1 < 0 || c1 >= matriz.numCols || c2 < 0 || c2 >= matriz.numCols) {
		return false;
	}
	else {
		if (c1 != c2) {
			for (int f = 0; f < matriz.numFilas; ++f) {
				//sustituir por swap
				aux = matriz.elementos[f][c1];
				matriz.elementos[f][c1] = matriz.elementos[f][c2];
				matriz.elementos[f][c2] = aux;
			}
			return true;
		}
	}
}
void rotarD(tMatrizChar& matriz) {
	tMatrizChar aux = matriz;
	matriz.numFilas = aux.numCols;
	matriz.numCols = aux.numFilas;
	for (int f = 0; f < aux.numFilas; ++f) {
		for (int c = 0; c < aux.numCols; ++c) {
			matriz.elementos[c][aux.numFilas - 1 - f] = aux.elementos[f][c];
		}
	}
}
bool voltearF(tMatrizChar& matriz, int f) {
	int aux;
	if (f < 0 || f >= matriz.numFilas) {
		return false;
	}
	else {
		for (int c = 0; c < matriz.numCols / 2; ++c) {
			//swap
			aux = matriz.elementos[f][c];
			matriz.elementos[f][c] = matriz.elementos[f][matriz.numCols - c - 1];
			matriz.elementos[f][matriz.numCols - c - 1] = aux;
		}
		return true;
	}
}
bool voltearC(tMatrizChar& matriz, int c) {
	int aux;
	if (c < 0 || c >= matriz.numCols) {
		return false;
	}
	else {
		for (int f = 0; f < matriz.numFilas / 2; ++f) {
			//swap
			aux = matriz.elementos[f][c];
			matriz.elementos[f][c] = matriz.elementos[matriz.numFilas - f - 1][c];
			matriz.elementos[matriz.numFilas - f - 1][c] = aux;
		}
		return true;
	}
}
void voltearV(tMatrizChar& matriz) {
	int aux;
	for (int f = 0; f < matriz.numFilas; ++f) {
		//swapC
		for (int c = 0; c < matriz.numCols / 2; ++c) {
			aux = matriz.elementos[f][c];
			matriz.elementos[f][c] = matriz.elementos[f][matriz.numCols - c - 1];
			matriz.elementos[f][matriz.numCols - c - 1] = aux;
		}
	}
}
void voltearH(tMatrizChar& matriz) {
	int aux;
	for (int f = 0; f < matriz.numFilas / 2; ++f) {
		//swapF
		for (int c = 0; c < matriz.numCols; ++c) {
			aux = matriz.elementos[f][c];
			matriz.elementos[f][c] = matriz.elementos[matriz.numFilas - f - 1][c];
			matriz.elementos[matriz.numFilas - f - 1][c] = aux;
		}
	}
}
bool swapD(tMatrizChar& matriz, int d) {
	tMatrizChar aux = matriz;
	if (d < 0 || d >= matriz.numCols) {
		return false;
	}
	else if (matriz.numCols != matriz.numFilas) {
		return false;
	}
	else {
		for (int f = 0; f + d < matriz.numFilas; ++f) {
			//swap
			aux.elementos[f][f + d] = matriz.elementos[f][f + d];
			matriz.elementos[f][f + d] = matriz.elementos[f + d][f];
			matriz.elementos[f + d][f] = aux.elementos[f][f + d];
		}
		return true;
	}
}
bool voltearD(tMatrizChar& matriz, int d) {
	int aux;
	if (d < 0 || d >= matriz.numCols) {
		return false;
	}
	else if (matriz.numCols != matriz.numFilas) {
		return false;
	}
	else {
		for (int f = 0; f < (matriz.numFilas - d) / 2; ++f) {
			//swap
			aux = matriz.elementos[f][f + d];
			matriz.elementos[f][f + d] = matriz.elementos[matriz.numCols - f - d - 1][matriz.numCols - f - 1];
			matriz.elementos[matriz.numCols - f - 1 - d][matriz.numCols - f - 1] = aux;
		}
		return true;
	}
}
//cambiar entero por booleano con while
bool operator == (tMatrizChar const& mat1, tMatrizChar const& mat2) {
	int igual = 0;
	if (mat1.numFilas != mat2.numFilas || mat1.numCols != mat2.numCols) {
		return false;
	}
	else if (mat1.numFilas == mat2.numFilas && mat1.numCols == mat2.numCols) {
		for (int f = 0; (f < mat1.numFilas) && (igual == 0); ++f)
			for (int c = 0; c < mat1.numCols; ++c)
				if (mat1.elementos[f][c] != mat2.elementos[f][c]) {
					igual = 1;
				}
		if (igual == 1) {
			return false;
		}
		else if (igual == 0) {
			return true;
		}
	}
}
bool swap(tMatrizChar& matriz, tCoor pos1, tCoor pos2) {
	int aux = 0;
	if (pos1.x >= matriz.numCols || pos1.y >= matriz.numFilas ||
		pos2.x >= matriz.numCols || pos2.y >= matriz.numFilas) {
		return false;
	}
	else {
		aux = matriz.elementos[pos1.y][pos1.x];
		matriz.elementos[pos1.y][pos1.x] = matriz.elementos[pos2.y][pos2.x];
		matriz.elementos[pos2.y][pos2.x] = aux;
		return true;
	}
}
bool voltearID(tMatrizChar& matriz) {
	int aux;
	if (matriz.numCols != matriz.numFilas) {
		return false;
	}
	else {
		for (int f = 0; f < matriz.numFilas; ++f) {
			//cambiar por swapD
			for (int d = 0; d < matriz.numCols; ++d) {
				aux = matriz.elementos[f][f + d];
				matriz.elementos[f][f + d] = matriz.elementos[f + d][f];
				matriz.elementos[f + d][f] = aux;
			}
		}
		return true;
	}
}
bool swapAdy(tMatrizChar& matriz, tCoor pos1, tCoor pos2) {
	int aux = 0;
	if (pos1.x - 1 < 0 || pos1.y - 1 < 0 ||
		pos1.x + 1 >= matriz.numCols || pos1.y + 1 >= matriz.numFilas ||
		pos2.x - 1 < 0 || pos2.y - 1 < 0 ||
		pos2.x + 1 >= matriz.numCols || pos2.y + 1 >= matriz.numFilas) {
		return false;
	}
	else {
		//-1, -1
		aux = matriz.elementos[pos1.y - 1][pos1.x - 1];
		matriz.elementos[pos1.y - 1][pos1.x - 1] = matriz.elementos[pos2.y - 1][pos2.x - 1];
		matriz.elementos[pos2.y - 1][pos2.x - 1] = aux;
		//-1, 0
		aux = matriz.elementos[pos1.y - 1][pos1.x];
		matriz.elementos[pos1.y - 1][pos1.x] = matriz.elementos[pos2.y - 1][pos2.x];
		matriz.elementos[pos2.y - 1][pos2.x] = aux;
		//-1, 1
		aux = matriz.elementos[pos1.y - 1][pos1.x + 1];
		matriz.elementos[pos1.y - 1][pos1.x + 1] = matriz.elementos[pos2.y - 1][pos2.x + 1];
		matriz.elementos[pos2.y - 1][pos2.x + 1] = aux;
		//0, -1
		aux = matriz.elementos[pos1.y][pos1.x - 1];
		matriz.elementos[pos1.y][pos1.x - 1] = matriz.elementos[pos2.y][pos2.x - 1];
		matriz.elementos[pos2.y][pos2.x - 1] = aux;
		//0, 1
		aux = matriz.elementos[pos1.y][pos1.x + 1];
		matriz.elementos[pos1.y][pos1.x + 1] = matriz.elementos[pos2.y][pos2.x + 1];
		matriz.elementos[pos2.y][pos2.x + 1] = aux;
		//1, -1
		aux = matriz.elementos[pos1.y + 1][pos1.x - 1];
		matriz.elementos[pos1.y + 1][pos1.x - 1] = matriz.elementos[pos2.y + 1][pos2.x - 1];
		matriz.elementos[pos2.y + 1][pos2.x - 1] = aux;
		//1, 0
		aux = matriz.elementos[pos1.y + 1][pos1.x];
		matriz.elementos[pos1.y + 1][pos1.x] = matriz.elementos[pos2.y + 1][pos2.x];
		matriz.elementos[pos2.y + 1][pos2.x] = aux;
		//1, 1
		aux = matriz.elementos[pos1.y + 1][pos1.x + 1];
		matriz.elementos[pos1.y + 1][pos1.x + 1] = matriz.elementos[pos2.y + 1][pos2.x + 1];
		matriz.elementos[pos2.y + 1][pos2.x + 1] = aux;

		return true;
	}
}
bool cargar(tMatrizChar& matriz, istream& ent) {
	ent >> matriz.numFilas >> matriz.numCols;
	bool ok = !ent.fail() && matriz.numFilas <= MAX_DIM && matriz.numCols >= 0;
	int f = 0;
	while (f < matriz.numFilas && ok) {
		int c = 0;
		while (c < matriz.numCols && ok) {
			ent >> matriz.elementos[f][c];
			if (ent.fail()) ok = false;
			else ++c;
		}
		if (ok) ++f;
	}
	return ok;
}