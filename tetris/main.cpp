#include <iostream>
#include "Cube.h"
#include "PositionMatrix.h"
#include "Piece.h"
using namespace std;



int main()
{
	cout << "Welcome to Sevy's Tetris Cube Solver" << endl;

	Cube tetris_cube = Cube();
	tetris_cube.Solve();


	return 0;
}

/* Here are the steps I have outlined:
1. For each type of piece, generate every possible position matrix and convert to bit string
2. Create a guess and check system where you fill in a piece position matrix for every one of the 64 cubes
3. Check all the possibilities

*/