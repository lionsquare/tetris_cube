#pragma once
class PositionMatrix
{
public:
	PositionMatrix();
	~PositionMatrix();
	void Display() const;
	void SetMatrix(int new_matrix[4][4][4]);
	void SetMatrix(unsigned long long new_id);
	void RotateLeft();
	void RotateRight();
	void RotateUp();
	void RotateDown();
	// Shift functions are guaranteed not to move pieces off the board
	bool ShiftUp();
	bool ShiftDown();
	bool ShiftLeft();
	bool ShiftRight();
	bool ShiftForward();
	bool ShiftBackward();
	void ShiftToCorner();
	int GetBitCount();
	unsigned long long GetID() const;
	inline bool operator< (const PositionMatrix& rhs) const { return (this->GetID() < rhs.GetID()); }
	inline bool operator> (const PositionMatrix& rhs) const { return (this->GetID() > rhs.GetID()); }
	inline bool operator== (const PositionMatrix& rhs) const { return (this->GetID() == rhs.GetID()); }
	bool RunUnitTests();
private:
	void GenerateID();
	void UpdateBitCount();
	int matrix[4][4][4];
	unsigned long long id;
	int bit_count;
	bool TestRotateLeft();
	bool TestRotateRight();
	bool TestRotateUp();
	bool TestRotateDown();
	bool TestShiftUp();
	bool TestShiftDown();
	bool TestShiftLeft();
	bool TestShiftRight();
	bool TestShiftForward();
	bool TestShiftBackward();
	bool TestShiftToCorner();
	bool TestGetBitCount();
	bool TestGetID();
	bool MatrixEqual(const int[4][4][4], const int[4][4][4]);
	int test_piece[4][4][4] = { {{1, 0, 0, 0}, //8C88 F000 0000 0000
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
								 {0, 0, 0, 0}},

							    {{0, 0, 0, 0},
								 {0, 0, 0, 0},
								 {0, 0, 0, 0},
								 {0, 0, 0, 0}} };
	int simple_test_piece[4][4][4] = { {{0, 0, 0, 0},
								  {0, 0, 0, 0},
								  {0, 0, 0, 0},
								  {0, 0, 0, 0}},

								 {{0, 0, 0, 0},
								  {0, 1, 0, 0},
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
};

