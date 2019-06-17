#pragma once
class PositionMatrix
{
public:
	PositionMatrix();
	~PositionMatrix();
	void Display() const;
	void SetMatrix(int new_matrix[4][4][4]);
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
private:
	void GenerateID();
	void UpdateBitCount();
	int matrix[4][4][4];
	unsigned long long id;
	int bit_count;
};

