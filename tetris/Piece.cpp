#include "Piece.h"
#include <iostream>


Piece::Piece(std::string new_name, PositionMatrix given_position)
{
	Piece::name = new_name;
	Piece::original_position = given_position;
	Piece::possible_positions = std::vector<PositionMatrix>();
	Piece::GeneratePossiblePositions();

}


Piece::Piece(std::string new_name, int given_position[4][4][4])
{
	Piece::name = new_name;
	PositionMatrix first_position = PositionMatrix();
	first_position.SetMatrix(given_position);
	Piece::original_position = first_position;
	Piece::possible_positions = std::vector<PositionMatrix>();
	Piece::GeneratePossiblePositions();

}


Piece::~Piece()
{
}


std::vector<PositionMatrix> GetPossiblePositions()
{
	std::vector<PositionMatrix> arrangements;
	return arrangements;
}


std::vector<unsigned long long> GetBitVectors()
{
	std::vector<unsigned long long> bit_vectors;
	return bit_vectors;
}


void Piece::GeneratePossiblePositions()
{
	Piece::possible_positions.clear();
	possible_positions.push_back(Piece::original_position);

	int bit_check = Piece::original_position.GetBitCount();
	PositionMatrix modified = Piece::original_position;
	

	Piece::Shift3(modified, bit_check, DIRECTION_UP);


	for (unsigned int a = 0; a < Piece::possible_positions.size(); a++)
	{
		std::cout<<std::hex<<Piece::possible_positions[a].GetID()<<std::endl;
	}


	/*
	for (int a = 0; a < possible_positions.size(); a++)
	{
		possible_positions[a].Display();
	}
	*/

}


void Piece::Shift3(const PositionMatrix &base_position, const int bit_check, int direction)
{
	PositionMatrix copied_position = base_position;
	for (int a = 1; a < 4; a++)
	{
		for (int b = 0; b < a; b++)
		{
			switch(direction)
			{
				case DIRECTION_UP:
					copied_position.ShiftUp();
					break;
				case DIRECTION_DOWN:
					copied_position.ShiftDown();
					break;
				case DIRECTION_LEFT:
					copied_position.ShiftLeft();
					break;
				case DIRECTION_RIGHT:
					copied_position.ShiftRight();
					break;
				case DIRECTION_FORWARD:
					copied_position.ShiftForward();
					break;
				case DIRECTION_BACKWARD:
					copied_position.ShiftBackward();
					break;
				default:
					break;
			}
		}
		if (copied_position.GetBitCount() == bit_check)
		{
			Piece::possible_positions.push_back(copied_position);
		}
		else
		{
			return;
		}
	}
}
