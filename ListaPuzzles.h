#ifndef LISTAPUZZLES_H
#define LISTAPUZZLES_H

#include "Puzzle.h"
#include <fstream>

const int MAX_PUZZLES = 100;

typedef tPuzzle tListaPuzzles[MAX_PUZZLES];
typedef tListaPuzzles tPuzzlesReunidos[2];

void inicializar(tPuzzlesReunidos& jr);
bool cargar(tPuzzlesReunidos& jr);
void guardar(const tPuzzlesReunidos& listas);
int elegirPuzzle(tListaPuzzles& lp);
bool insertarOrdenado(tListaPuzzles& l, tPuzzle* p);
bool buscar(const tListaPuzzles& lista, tPuzzle* puzzle, int& pos);

#endif
