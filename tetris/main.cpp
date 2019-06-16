#include <iostream>
#include "TetrisPieces.h"
#include "PositionMatrix.h"
#include "Piece.h"
using namespace std;

int main()
{
	cout << "Welcome to Sevy's Tetris Cube Solver" << endl;


	Piece Lucy0 = Piece("Lucy", Lucy);
	/*PositionMatrix P = PositionMatrix();
	

	
	P.SetMatrix(Lucy);
	P.Display();
	P.RotateLeft();
	P.Display();
	P.RotateRight();
	P.Display();
	P.RotateUp();
	P.Display();
	P.RotateDown();
	P.Display();

	P.SetMatrix(Lucy);
	P.Display();

	P.ShiftBackward();
	P.Display();

	P.SetMatrix(Lucy);
	P.ShiftForward();
	P.Display();

	P.SetMatrix(Lucy);
	P.ShiftDown();
	P.Display();

	P.SetMatrix(Lucy);
	P.ShiftUp();
	P.Display();

	P.SetMatrix(Lucy);
	P.ShiftLeft();
	P.Display();

	P.SetMatrix(Lucy);
	P.ShiftRight();
	P.Display(); */
	return 0;
}

/* Here are the steps I have outlined:
1. For each type of piece, generate every possible position matrix and convert to bit string
2. Create a guess and check system where you fill in a piece position matrix for every one of the 64 cubes
3. Check all the possibilities

*/