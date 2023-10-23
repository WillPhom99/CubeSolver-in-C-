#ifndef SOLUTIONBOOL_H_
#define SOLUTIONBOOL_H_

using namespace std;

#include "Rubik.h"

void solve_cube(Cube& cube);
int countMoves(string Algorithm);
size_t solution_length(Cube& cube);
void print_solution(Cube& cube);

#endif