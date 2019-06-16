#include "PositionMatrix.h"
#include <iostream>


PositionMatrix::PositionMatrix()
{
	for (int floor = 0; floor < 4; floor++)
	{
		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				PositionMatrix::matrix[floor][row][col] = 0;
			}
		}
	}
	PositionMatrix::bit_count = 0;
	PositionMatrix::GenerateID();
}


PositionMatrix::~PositionMatrix()
{
}

void PositionMatrix::Display()
{
	for (int row = 0; row < 4; row++)
	{
		for (int floor = 0; floor < 4; floor++)
		{
			for (int col = 0; col < 4; col++)
			{
				std::cout << PositionMatrix::matrix[floor][row][col] << " ";
			}
			std::cout << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void PositionMatrix::SetMatrix(int new_matrix[4][4][4])
{
	for (int floor = 0; floor < 4; floor++)
	{
		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				PositionMatrix::matrix[floor][row][col] = new_matrix[floor][row][col];
			}
		}
	}
	PositionMatrix::GenerateID();
	PositionMatrix::UpdateBitCount();
}


int PositionMatrix::GetBitCount(void)
{
	return PositionMatrix::bit_count;
}


unsigned long long PositionMatrix::GetID(void)
{
	return PositionMatrix::id;
}


void PositionMatrix::GenerateID(void)
{
	unsigned long long total = 0;
	for (int floor = 0; floor < 4; floor++)
	{
		int shift = 16 * (3-floor);
		unsigned long long partial_sum = 0;
		
		for (int bit = 0; bit < 16; bit++)
		{
			int col = 3 - (bit % 4);
			int row = 3 - (bit / 4);
			partial_sum += (PositionMatrix::matrix[floor][row][col] << bit);
		}
			
		total += (partial_sum << shift);
	}
	PositionMatrix::id = total;
	//std::cout << "ID: " << total << std::endl;
}


void PositionMatrix::UpdateBitCount(void)
{
	int total_bits = 0;
	for (int floor = 0; floor < 4; floor++)
	{
		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				total_bits += PositionMatrix::matrix[floor][row][col];
			}
		}
	}
	PositionMatrix::bit_count = total_bits;
}


void PositionMatrix::RotateLeft(void)
{
	int temp_grid[4][4];
	for (int floor = 0; floor < 4; floor++)
	{
		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				temp_grid[row][col] = PositionMatrix::matrix[floor][row][col];
			}
		}

		
		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				PositionMatrix::matrix[floor][3-row][col] = temp_grid[col][row];
			}
		}
	
	}
	PositionMatrix::GenerateID();
	PositionMatrix::UpdateBitCount();
}


void PositionMatrix::RotateRight(void)
{
	int temp_grid[4][4];
	for (int floor = 0; floor < 4; floor++)
	{
		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				temp_grid[row][col] = PositionMatrix::matrix[floor][3-row][col];
			}
		}

		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				PositionMatrix::matrix[floor][row][col] = temp_grid[col][row];
			}
		}
	}

	PositionMatrix::GenerateID();
	PositionMatrix::UpdateBitCount();
}


void PositionMatrix::RotateUp(void)
{
	int temp_grid[4][4];
	for (int col = 0; col < 4; col++)
	{
		for (int row = 0; row < 4; row++)
		{
			for (int floor = 0; floor < 4; floor++)
			{
				temp_grid[floor][row] = PositionMatrix::matrix[floor][row][col];
			}
		}


		for (int floor = 0; floor < 4; floor++)
		{
			for (int row = 0; row < 4; row++)
			{
				PositionMatrix::matrix[3-floor][row][col] = temp_grid[row][floor];
			}
		}

	}

	PositionMatrix::GenerateID();
	PositionMatrix::UpdateBitCount();
}


void PositionMatrix::RotateDown(void)
{
	int temp_grid[4][4];
	for (int col = 0; col < 4; col++)
	{
		for (int row = 0; row < 4; row++)
		{
			for (int floor = 0; floor < 4; floor++)
			{
				temp_grid[floor][row] = PositionMatrix::matrix[3-floor][row][col];
			}
		}


		for (int floor = 0; floor < 4; floor++)
		{
			for (int row = 0; row < 4; row++)
			{
				PositionMatrix::matrix[floor][row][col] = temp_grid[row][floor];
			}
		}

	}

	PositionMatrix::GenerateID();
	PositionMatrix::UpdateBitCount();
}


void PositionMatrix::ShiftUp(void)
{
	for (int floor = 3; floor > 0; floor--)
	{
		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				PositionMatrix::matrix[floor][row][col] = PositionMatrix::matrix[floor - 1][row][col];
			}
		}
	}
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			PositionMatrix::matrix[0][row][col] = 0;
		}
	}
	PositionMatrix::GenerateID();
	PositionMatrix::UpdateBitCount();
}


void PositionMatrix::ShiftDown(void)
{
	for (int floor = 0; floor < 3; floor++)
	{
		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				PositionMatrix::matrix[floor][row][col] = PositionMatrix::matrix[floor + 1][row][col];
			}
		}
	}
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			PositionMatrix::matrix[3][row][col] = 0;
		}
	}
	PositionMatrix::GenerateID();
	PositionMatrix::UpdateBitCount();
}


void PositionMatrix::ShiftLeft(void)
{
	for (int col = 0; col < 3; col++)
	{
		for (int floor = 0; floor < 4; floor++)
		{
			for (int row = 0; row < 4; row++)
			{
			
				PositionMatrix::matrix[floor][row][col] = PositionMatrix::matrix[floor][row][col + 1];
			}
		}
	}
	for (int row = 0; row < 4; row++)
	{
		for (int floor = 0; floor < 4; floor++)
		{
			PositionMatrix::matrix[floor][row][3] = 0;
		}
	}
	PositionMatrix::GenerateID();
	PositionMatrix::UpdateBitCount();
}


void PositionMatrix::ShiftRight(void)
{
	for (int col = 3; col > 0; col--)
	{
		for (int floor = 0; floor < 4; floor++)
		{
			for (int row = 0; row < 4; row++)
			{

				PositionMatrix::matrix[floor][row][col] = PositionMatrix::matrix[floor][row][col - 1];
			}
		}
	}
	for (int row = 0; row < 4; row++)
	{
		for (int floor = 0; floor < 4; floor++)
		{
			PositionMatrix::matrix[floor][row][0] = 0;
		}
	}
	PositionMatrix::GenerateID();
	PositionMatrix::UpdateBitCount();
}


void PositionMatrix::ShiftForward(void)
{
	for (int row = 3; row > 0; row--)
	{
		for (int floor = 0; floor < 4; floor++)
		{
			for (int col = 0; col < 4; col++)
			{

				PositionMatrix::matrix[floor][row][col] = PositionMatrix::matrix[floor][row - 1][col];
			}
		}
	}
	for (int col = 0; col < 4; col++)
	{
		for (int floor = 0; floor < 4; floor++)
		{
			PositionMatrix::matrix[floor][0][col] = 0;
		}
	}
	PositionMatrix::GenerateID();
	PositionMatrix::UpdateBitCount();
}


void PositionMatrix::ShiftBackward(void)
{
	for (int row = 0; row < 3; row++)
	{
		for (int floor = 0; floor < 4; floor++)
		{
			for (int col = 0; col < 4; col++)
			{

				PositionMatrix::matrix[floor][row][col] = PositionMatrix::matrix[floor][row + 1][col];
			}
		}
	}
	for (int col = 0; col < 4; col++)
	{
		for (int floor = 0; floor < 4; floor++)
		{
			PositionMatrix::matrix[floor][3][col] = 0;
		}
	}
	PositionMatrix::GenerateID();
	PositionMatrix::UpdateBitCount();
}