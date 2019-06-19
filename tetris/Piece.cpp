#include "Piece.h"
#include <iostream>
#include <set>
#include <algorithm>

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


std::vector<PositionMatrix> Piece::GetPossiblePositions()
{
	std::vector<PositionMatrix> arrangements;
	return arrangements;
}


std::vector<unsigned long long> Piece::GetBitVectors()
{
	std::vector<unsigned long long> bit_vectors;
	for (unsigned int a = 0; a < this->possible_positions.size(); a++)
	{
		if (this->possible_positions[a].GetID() == 0)
		{
			std::cout << "Zero ID!!!" << std::endl;
			continue;
		}
		bit_vectors.push_back(this->possible_positions[a].GetID());
	}
	return bit_vectors;
}


void Piece::GeneratePossiblePositions()
{
	Piece::possible_positions.clear();
	Piece::rotations.clear();

	this->GenerateRotations();
	

	std::set<PositionMatrix>::iterator it = this->rotations.begin();

	while (it != this->rotations.end())
	{
		PositionMatrix modified = *it;
		Piece::Shift64(modified);
		it++;
	}
	
	std::sort(Piece::possible_positions.begin(), Piece::possible_positions.end());
	Piece::possible_positions.erase(std::unique(Piece::possible_positions.begin(), Piece::possible_positions.end()), Piece::possible_positions.end());


	for (unsigned int a = 0; a < Piece::possible_positions.size(); a++)
	{
		int bc = Piece::possible_positions[a].GetBitCount();
		if (bc != this->original_position.GetBitCount())
		{
			std::cout << "Big problem!!! Destructive operation\n";
		}
		
	}
}


void Piece::Shift64(const PositionMatrix &base_position)
{
	PositionMatrix modified = base_position;
	int count = 0;
	for (int floor_shift = 0; floor_shift < 4; floor_shift++)
	{
		for (int row_shift = 0; row_shift < 4; row_shift++)
		{
			for (int col_shift = 0; col_shift < 4; col_shift++)
			{
				modified.ShiftToCorner();
				bool stays_in_bounds = true;
				for (int c = 0; c < col_shift; c++)
				{
					stays_in_bounds &= modified.ShiftRight();
				}
				for (int r = 0; r < row_shift; r++)
				{
					stays_in_bounds &= modified.ShiftForward();
				}
				for (int f = 0; f < floor_shift; f++)
				{
					stays_in_bounds &= modified.ShiftUp();
				}
				if (stays_in_bounds)
				{
					Piece::possible_positions.push_back(modified);
					count++;
				}

			}
		}
	}
}

void Piece::GenerateRotations(void)
{
	this->rotations.clear();
	for (int cw_rot = 0; cw_rot < 4; cw_rot++)
	{
		for (int up_rot = 0; up_rot < 4; up_rot++)
		{
			PositionMatrix modified = Piece::original_position;
			for (int cw = 0; cw < cw_rot; cw++)
			{
				modified.RotateLeft();
			}
			for (int up = 0; up < up_rot; up++)
			{
				modified.RotateUp();
			}
			this->rotations.insert(modified);
		}
	}
	for (int cw_rot = 0; cw_rot < 4; cw_rot++)
	{
		for (int up_rot = 0; up_rot < 4; up_rot++)
		{
			PositionMatrix modified = Piece::original_position;
			for (int up = 0; up < up_rot; up++)
			{
				modified.RotateUp();
			}
			for (int cw = 0; cw < cw_rot; cw++)
			{
				modified.RotateLeft();
			}
			this->rotations.insert(modified);
		}
	}
	for (int cw_rot = 0; cw_rot < 4; cw_rot++)
	{
		for (int up_rot = 0; up_rot < 4; up_rot++)
		{
			PositionMatrix modified = Piece::original_position;
			modified.RotateRight();
			for (int up = 0; up < up_rot; up++)
			{
				modified.RotateUp();
			}
			for (int cw = 0; cw < cw_rot; cw++)
			{
				modified.RotateRight();
			}
			this->rotations.insert(modified);
		}
	}
}


// ------------------------------ Unit Tests ------------------------------- //
bool Piece::RunUnitTests()
{
	return false;
}