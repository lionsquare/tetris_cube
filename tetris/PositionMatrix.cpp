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

void PositionMatrix::Display() const
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
void PositionMatrix::SetMatrix(unsigned long long new_id)
{
	PositionMatrix::matrix[0][0][0] = ((new_id & ((unsigned long long)1 << 63)) != 0);
	PositionMatrix::matrix[0][0][1] = ((new_id & ((unsigned long long)1 << 62)) != 0);
	PositionMatrix::matrix[0][0][2] = ((new_id & ((unsigned long long)1 << 61)) != 0);
	PositionMatrix::matrix[0][0][3] = ((new_id & ((unsigned long long)1 << 60)) != 0);
	PositionMatrix::matrix[0][1][0] = ((new_id & ((unsigned long long)1 << 59)) != 0);
	PositionMatrix::matrix[0][1][1] = ((new_id & ((unsigned long long)1 << 58)) != 0);
	PositionMatrix::matrix[0][1][2] = ((new_id & ((unsigned long long)1 << 57)) != 0);
	PositionMatrix::matrix[0][1][3] = ((new_id & ((unsigned long long)1 << 56)) != 0);
	PositionMatrix::matrix[0][2][0] = ((new_id & ((unsigned long long)1 << 55)) != 0);
	PositionMatrix::matrix[0][2][1] = ((new_id & ((unsigned long long)1 << 54)) != 0);
	PositionMatrix::matrix[0][2][2] = ((new_id & ((unsigned long long)1 << 53)) != 0);
	PositionMatrix::matrix[0][2][3] = ((new_id & ((unsigned long long)1 << 52)) != 0);
	PositionMatrix::matrix[0][3][0] = ((new_id & ((unsigned long long)1 << 51)) != 0);
	PositionMatrix::matrix[0][3][1] = ((new_id & ((unsigned long long)1 << 50)) != 0);
	PositionMatrix::matrix[0][3][2] = ((new_id & ((unsigned long long)1 << 49)) != 0);
	PositionMatrix::matrix[0][3][3] = ((new_id & ((unsigned long long)1 << 48)) != 0);


	PositionMatrix::matrix[1][0][0] = ((new_id & ((unsigned long long)1 << 47)) != 0);
	PositionMatrix::matrix[1][0][1] = ((new_id & ((unsigned long long)1 << 46)) != 0);
	PositionMatrix::matrix[1][0][2] = ((new_id & ((unsigned long long)1 << 45)) != 0);
	PositionMatrix::matrix[1][0][3] = ((new_id & ((unsigned long long)1 << 44)) != 0);
	PositionMatrix::matrix[1][1][0] = ((new_id & ((unsigned long long)1 << 43)) != 0);
	PositionMatrix::matrix[1][1][1] = ((new_id & ((unsigned long long)1 << 42)) != 0);
	PositionMatrix::matrix[1][1][2] = ((new_id & ((unsigned long long)1 << 41)) != 0);
	PositionMatrix::matrix[1][1][3] = ((new_id & ((unsigned long long)1 << 40)) != 0);
	PositionMatrix::matrix[1][2][0] = ((new_id & ((unsigned long long)1 << 39)) != 0);
	PositionMatrix::matrix[1][2][1] = ((new_id & ((unsigned long long)1 << 38)) != 0);
	PositionMatrix::matrix[1][2][2] = ((new_id & ((unsigned long long)1 << 37)) != 0);
	PositionMatrix::matrix[1][2][3] = ((new_id & ((unsigned long long)1 << 36)) != 0);
	PositionMatrix::matrix[1][3][0] = ((new_id & ((unsigned long long)1 << 35)) != 0);
	PositionMatrix::matrix[1][3][1] = ((new_id & ((unsigned long long)1 << 34)) != 0);
	PositionMatrix::matrix[1][3][2] = ((new_id & ((unsigned long long)1 << 33)) != 0);
	PositionMatrix::matrix[1][3][3] = ((new_id & ((unsigned long long)1 << 32)) != 0);

	PositionMatrix::matrix[2][0][0] = ((new_id & ((unsigned long long)1 << 31)) != 0);
	PositionMatrix::matrix[2][0][1] = ((new_id & ((unsigned long long)1 << 30)) != 0);
	PositionMatrix::matrix[2][0][2] = ((new_id & ((unsigned long long)1 << 29)) != 0);
	PositionMatrix::matrix[2][0][3] = ((new_id & ((unsigned long long)1 << 28)) != 0);
	PositionMatrix::matrix[2][1][0] = ((new_id & ((unsigned long long)1 << 27)) != 0);
	PositionMatrix::matrix[2][1][1] = ((new_id & ((unsigned long long)1 << 26)) != 0);
	PositionMatrix::matrix[2][1][2] = ((new_id & ((unsigned long long)1 << 25)) != 0);
	PositionMatrix::matrix[2][1][3] = ((new_id & ((unsigned long long)1 << 24)) != 0);
	PositionMatrix::matrix[2][2][0] = ((new_id & ((unsigned long long)1 << 23)) != 0);
	PositionMatrix::matrix[2][2][1] = ((new_id & ((unsigned long long)1 << 22)) != 0);
	PositionMatrix::matrix[2][2][2] = ((new_id & ((unsigned long long)1 << 21)) != 0);
	PositionMatrix::matrix[2][2][3] = ((new_id & ((unsigned long long)1 << 20)) != 0);
	PositionMatrix::matrix[2][3][0] = ((new_id & ((unsigned long long)1 << 19)) != 0);
	PositionMatrix::matrix[2][3][1] = ((new_id & ((unsigned long long)1 << 18)) != 0);
	PositionMatrix::matrix[2][3][2] = ((new_id & ((unsigned long long)1 << 17)) != 0);
	PositionMatrix::matrix[2][3][3] = ((new_id & ((unsigned long long)1 << 16)) != 0);


	PositionMatrix::matrix[3][0][0] = ((new_id & ((unsigned long long)1 << 15)) != 0);
	PositionMatrix::matrix[3][0][1] = ((new_id & ((unsigned long long)1 << 14)) != 0);
	PositionMatrix::matrix[3][0][2] = ((new_id & ((unsigned long long)1 << 13)) != 0);
	PositionMatrix::matrix[3][0][3] = ((new_id & ((unsigned long long)1 << 12)) != 0);
	PositionMatrix::matrix[3][1][0] = ((new_id & ((unsigned long long)1 << 11)) != 0);
	PositionMatrix::matrix[3][1][1] = ((new_id & ((unsigned long long)1 << 10)) != 0);
	PositionMatrix::matrix[3][1][2] = ((new_id & ((unsigned long long)1 << 9)) != 0);
	PositionMatrix::matrix[3][1][3] = ((new_id & ((unsigned long long)1 << 8)) != 0);
	PositionMatrix::matrix[3][2][0] = ((new_id & ((unsigned long long)1 << 7)) != 0);
	PositionMatrix::matrix[3][2][1] = ((new_id & ((unsigned long long)1 << 6)) != 0);
	PositionMatrix::matrix[3][2][2] = ((new_id & ((unsigned long long)1 << 5)) != 0);
	PositionMatrix::matrix[3][2][3] = ((new_id & ((unsigned long long)1 << 4)) != 0);
	PositionMatrix::matrix[3][3][0] = ((new_id & ((unsigned long long)1 << 3)) != 0);
	PositionMatrix::matrix[3][3][1] = ((new_id & ((unsigned long long)1 << 2)) != 0);
	PositionMatrix::matrix[3][3][2] = ((new_id & ((unsigned long long)1 << 1)) != 0);
	PositionMatrix::matrix[3][3][3] = ((new_id & ((unsigned long long)1 << 0)) != 0);


	PositionMatrix::GenerateID();
	PositionMatrix::UpdateBitCount();
}


int PositionMatrix::GetBitCount(void)
{
	return PositionMatrix::bit_count;
}


unsigned long long PositionMatrix::GetID(void) const
{
	return this->id;
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
}


bool PositionMatrix::ShiftUp(void)
{
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (this->matrix[3][row][col] != 0)
			{
				return false;
			}
		}
	}
	

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
	return true;
}


bool PositionMatrix::ShiftDown(void)
{
	for (int row = 0; row < 4; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (this->matrix[0][row][col] != 0)
			{
				return false;
			}
		}
	}
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
	return true;
}


bool PositionMatrix::ShiftLeft(void)
{
	for (int floor = 0; floor < 4; floor++)
	{
		for (int row = 0; row < 4; row++)
		{
			if (this->matrix[floor][row][0] != 0)
			{
				return false;
			}
		}
	}
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
	return true;
}


bool PositionMatrix::ShiftRight(void)
{
	for (int floor = 0; floor < 4; floor++)
	{
		for (int row = 0; row < 4; row++)
		{
			if (this->matrix[floor][row][3] != 0)
			{
				return false;
			}
		}
	}
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
	return true;
}


bool PositionMatrix::ShiftForward(void)
{
	for (int floor = 0; floor < 4; floor++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (this->matrix[floor][3][col] != 0)
			{
				return false;
			}
		}
	}
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
	return true;
}


bool PositionMatrix::ShiftBackward(void)
{
	for (int floor = 0; floor < 4; floor++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (this->matrix[floor][0][col] != 0)
			{
				return false;
			}
		}
	}
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
	return true;
}

// Function to move piece to back, left, bottom corner
void PositionMatrix::ShiftToCorner(void)
{
	for (int a = 0; a < 3; a++)
	{
		this->ShiftLeft();
		this->ShiftBackward();
		this->ShiftDown();
	}
}

// --------------------------------- Unit Tests --------------------------- //
bool PositionMatrix::RunUnitTests(void)
{
	bool passes_all_unit_tests = true;
	passes_all_unit_tests &= PositionMatrix::TestRotateLeft();
	passes_all_unit_tests &= PositionMatrix::TestRotateRight();
	passes_all_unit_tests &= PositionMatrix::TestRotateUp();
	passes_all_unit_tests &= PositionMatrix::TestRotateDown();
	passes_all_unit_tests &= PositionMatrix::TestShiftUp();
	passes_all_unit_tests &= PositionMatrix::TestShiftDown();
	passes_all_unit_tests &= PositionMatrix::TestShiftLeft();
	passes_all_unit_tests &= PositionMatrix::TestShiftRight();
	passes_all_unit_tests &= PositionMatrix::TestShiftForward();
	passes_all_unit_tests &= PositionMatrix::TestShiftBackward();
	passes_all_unit_tests &= PositionMatrix::TestShiftToCorner();
	passes_all_unit_tests &= PositionMatrix::TestGetBitCount();
	passes_all_unit_tests &= PositionMatrix::TestGetID();
	if (passes_all_unit_tests)
	{
		std::cout << "PositionMatrix passes all unit tests!" << std::endl;
	}
	else
	{
		std::cout << "PositionMatrix fails unit tests :(" << std::endl;
	}
	return passes_all_unit_tests;
}


bool PositionMatrix::TestRotateLeft(void)
{
	PositionMatrix::SetMatrix(PositionMatrix::test_piece);
	PositionMatrix::RotateLeft();
	int answer[4][4][4] = { {{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 1, 0, 0},
							 {1, 1, 1, 1}},

							{{1, 0, 0, 0},
							 {1, 0, 0, 0},
							 {1, 0, 0, 0},
							 {1, 0, 0, 0}},

							{{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}},

							{{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}} };
	if (!PositionMatrix::MatrixEqual(PositionMatrix::matrix, answer))
	{
		return false;
	}
	return true;
}


bool PositionMatrix::TestRotateRight(void)
{
	PositionMatrix::SetMatrix(PositionMatrix::test_piece);
	PositionMatrix::RotateRight();
	int answer[4][4][4] = { {{1, 1, 1, 1},
							 {0, 0, 1, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}},

							{{0, 0, 0, 1},
							 {0, 0, 0, 1},
							 {0, 0, 0, 1},
							 {0, 0, 0, 1}},

							{{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}},

							{{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}} };
	if (!PositionMatrix::MatrixEqual(PositionMatrix::matrix, answer))
	{
		return false;
	}
	return true;
}


bool PositionMatrix::TestRotateUp(void)
{
	PositionMatrix::SetMatrix(PositionMatrix::test_piece);
	PositionMatrix::RotateUp();
	int answer[4][4][4] = { {{1, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}},

							{{1, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}},

							{{1, 1, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}},

							{{1, 0, 0, 0},
							 {1, 1, 1, 1},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}} };
	if (!PositionMatrix::MatrixEqual(PositionMatrix::matrix, answer))
	{
		return false;
	}
	return true;
}


bool PositionMatrix::TestRotateDown(void)
{
	PositionMatrix::SetMatrix(PositionMatrix::test_piece);
	PositionMatrix::RotateDown();
	int answer[4][4][4] = { {{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {1, 1, 1, 1},
							 {1, 0, 0, 0}},

							{{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {1, 1, 0, 0}},

							{{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {1, 0, 0, 0}},

							{{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {1, 0, 0, 0}} };
	if (!PositionMatrix::MatrixEqual(PositionMatrix::matrix, answer))
	{
		return false;
	}
	return true;
}


bool PositionMatrix::TestShiftUp(void)
{
	PositionMatrix::SetMatrix(PositionMatrix::test_piece);
	PositionMatrix::ShiftUp();
	int answer[4][4][4] = { {{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}},

							{{1, 0, 0, 0},
							 {1, 1, 0, 0},
							 {1, 0, 0, 0},
							 {1, 0, 0, 0}},

							{{1, 1, 1, 1},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}},

							{{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}} };
	if (!PositionMatrix::MatrixEqual(PositionMatrix::matrix, answer))
	{
		return false;
	}
	return true;
}


bool PositionMatrix::TestShiftDown(void)
{
	PositionMatrix::SetMatrix(PositionMatrix::test_piece);
	bool shift_succeeds = PositionMatrix::ShiftDown();
	if (shift_succeeds)
	{
		return false;
	}

	PositionMatrix::ShiftUp();
	PositionMatrix::ShiftDown();

	if (!PositionMatrix::MatrixEqual(PositionMatrix::matrix, PositionMatrix::test_piece))
	{
		return false;
	}
	return true;
}


bool PositionMatrix::TestShiftLeft(void)
{
	PositionMatrix::SetMatrix(PositionMatrix::test_piece);
	bool shift_succeeds = PositionMatrix::ShiftLeft();
	if (shift_succeeds)
	{
		return false;
	}
	PositionMatrix::SetMatrix(PositionMatrix::simple_test_piece);
	shift_succeeds = PositionMatrix::ShiftLeft();
	if (!shift_succeeds)
	{
		return false;
	}
	int answer[4][4][4] = { {{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}},

							{{0, 0, 0, 0},
							 {1, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}},

							{{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}},

							{{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}} };
	if (!PositionMatrix::MatrixEqual(PositionMatrix::matrix, answer))
	{
		return false;
	}
	return true;
}


bool PositionMatrix::TestShiftRight(void)
{
	PositionMatrix::SetMatrix(PositionMatrix::test_piece);
	bool shift_succeeds = PositionMatrix::ShiftRight();
	if (shift_succeeds)
	{
		return false;
	}
	PositionMatrix::SetMatrix(PositionMatrix::simple_test_piece);
	shift_succeeds = PositionMatrix::ShiftRight();
	if (!shift_succeeds)
	{
		return false;
	}
	int answer[4][4][4] = { {{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}},

							{{0, 0, 0, 0},
							 {0, 0, 1, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}},

							{{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}},

							{{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}} };
	if (!PositionMatrix::MatrixEqual(PositionMatrix::matrix, answer))
	{
		return false;
	}
	return true;
}


bool PositionMatrix::TestShiftForward(void)
{
	int tp[4][4][4] =     { {{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}},

							{{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 1, 0, 0}},

							{{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}},

							{{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}} };

	PositionMatrix::SetMatrix(tp);
	bool shift_succeeds = PositionMatrix::ShiftForward();
	if (shift_succeeds)
	{
		return false;
	}
	PositionMatrix::SetMatrix(PositionMatrix::simple_test_piece);
	shift_succeeds = PositionMatrix::ShiftForward();
	if (!shift_succeeds)
	{
		return false;
	}
	int answer[4][4][4] = { {{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}},

							{{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 1, 0, 0},
							 {0, 0, 0, 0}},

							{{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}},

							{{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}} };
	if (!PositionMatrix::MatrixEqual(PositionMatrix::matrix, answer))
	{
		return false;
	}
	return true;
}


bool PositionMatrix::TestShiftBackward(void)
{
	int tp[4][4][4] =     { {{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}},

							{{0, 1, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}},

							{{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}},

							{{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}} };

	PositionMatrix::SetMatrix(tp);
	bool shift_succeeds = PositionMatrix::ShiftBackward();
	if (shift_succeeds)
	{
		return false;
	}
	if (!PositionMatrix::MatrixEqual(PositionMatrix::matrix, tp))
	{
		return false;
	}

	PositionMatrix::SetMatrix(PositionMatrix::simple_test_piece);
	shift_succeeds = PositionMatrix::ShiftBackward();
	if (!shift_succeeds)
	{
		return false;
	}
	int answer[4][4][4] = { {{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}},

							{{0, 1, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}},

							{{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}},

							{{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}} };
	if (!PositionMatrix::MatrixEqual(PositionMatrix::matrix, answer))
	{
		return false;
	}
	return true;
}


bool PositionMatrix::TestShiftToCorner(void)
{
	PositionMatrix::SetMatrix(PositionMatrix::test_piece);
	PositionMatrix::ShiftToCorner();
	if (!PositionMatrix::MatrixEqual(PositionMatrix::matrix, PositionMatrix::test_piece))
	{
		return false;
	}
	PositionMatrix::SetMatrix(PositionMatrix::simple_test_piece);
	PositionMatrix::ShiftToCorner();
	int answer[4][4][4] = { {{1, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}},

							{{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}},

							{{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}},

							{{0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0},
							 {0, 0, 0, 0}} };
	if (!PositionMatrix::MatrixEqual(PositionMatrix::matrix, answer))
	{
		return false;
	}
	return true;
}


bool PositionMatrix::TestGetBitCount(void)
{
	PositionMatrix::SetMatrix(simple_test_piece);
	if (PositionMatrix::GetBitCount() != 1)
	{
		return false;
	}
	PositionMatrix::SetMatrix(test_piece);
	if (PositionMatrix::GetBitCount() != 9)
	{
		return false;
	}
	return true;
}


bool PositionMatrix::TestGetID(void)
{
	PositionMatrix::SetMatrix(simple_test_piece);
	if (PositionMatrix::GetID() != 0x0000040000000000)
	{
		return false;
	}
	PositionMatrix::SetMatrix(test_piece);
	if (PositionMatrix::GetID() != 0x8C88F00000000000)
	{
		return false;
	}
	return true;
}


bool PositionMatrix::MatrixEqual(const int A[4][4][4], const int B[4][4][4])
{
	for (int floor = 0; floor < 4; floor++)
	{
		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				if (A[floor][row][col] != B[floor][row][col])
				{
					return false;
				}
			}
		}
	}
	return true;
}