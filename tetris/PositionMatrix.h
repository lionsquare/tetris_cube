#pragma once
class PositionMatrix
{
public:
	PositionMatrix();
	~PositionMatrix();
	void Display();
	void SetMatrix(int new_matrix[4][4][4]);
	void RotateLeft();
	void RotateRight();
	void RotateUp();
	void RotateDown();
	void ShiftUp();
	void ShiftDown();
	void ShiftLeft();
	void ShiftRight();
	void ShiftForward();
	void ShiftBackward();
	int GetBitCount();
	unsigned long long GetID();
private:
	void GenerateID();
	void UpdateBitCount();
	int matrix[4][4][4];
	unsigned long long id;
	int bit_count;
};

