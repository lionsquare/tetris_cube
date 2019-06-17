#include "Piece.h"
#include <iostream>
#include <set>

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
	int bit_check = Piece::original_position.GetBitCount();
	

	Piece::rotations.clear();
	std::set<unsigned long long> unique_positions;
	

	// Generate the 24 orientations
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
			Piece::rotations.insert(modified);
			unique_positions.insert(modified.GetID());
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
			unique_positions.insert(modified.GetID());
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
			unique_positions.insert(modified.GetID());
		}
	}
	std::cout << "Unique IDs:\t" << unique_positions.size() << std::endl;
	//Piece::Shift64(modified);

	for (unsigned int a = 0; a < Piece::possible_positions.size(); a++)
	{
		std::cout<<std::hex<<Piece::possible_positions[a].GetID()<<std::endl;
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
					std::cout << count << std::endl;
					Piece::possible_positions.push_back(modified);
					modified.Display();
					count++;
				}

			}
		}
	}
}


void Piece::Shift3(const PositionMatrix &base_position, const int bit_check, int direction)
{
	PositionMatrix copied_position = base_position;
	if (copied_position.GetBitCount() == bit_check)
	{
		Piece::possible_positions.push_back(copied_position);
	}
	else
	{
		return;
	}
	for (int a = 0; a < 3; a++)
	{
		bool stays_in_bounds = false;
		switch (direction)
		{
		case DIRECTION_UP:
			stays_in_bounds = copied_position.ShiftUp();
			break;
		case DIRECTION_DOWN:
			stays_in_bounds = copied_position.ShiftDown();
			break;
		case DIRECTION_LEFT:
			stays_in_bounds = copied_position.ShiftLeft();
			break;
		case DIRECTION_RIGHT:
			stays_in_bounds = copied_position.ShiftRight();
			break;
		case DIRECTION_FORWARD:
			stays_in_bounds = copied_position.ShiftForward();
			break;
		case DIRECTION_BACKWARD:
			stays_in_bounds = copied_position.ShiftBackward();
			break;
		default:
			break;

		}
		if (stays_in_bounds)
		{
			Piece::possible_positions.push_back(copied_position);
		}
		else
		{
			return;
		}
	}
}
