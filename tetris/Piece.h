#pragma once
#include <string>
#include <vector>
#include <set>
#include "PositionMatrix.h"

#define DIRECTION_UP 0
#define DIRECTION_DOWN 1
#define DIRECTION_LEFT 2
#define DIRECTION_RIGHT 3
#define DIRECTION_FORWARD 4
#define DIRECTION_BACKWARD 5

class Piece
{
public:
	Piece(std::string new_name, PositionMatrix given_position);
	Piece(std::string new_name, int given_position[4][4][4]);
	~Piece();
	std::vector<PositionMatrix> GetPossiblePositions();
	std::vector<unsigned long long> GetBitVectors();
private:
	std::string name;
	std::vector<PositionMatrix> possible_positions;
	std::set<PositionMatrix> rotations;
	PositionMatrix original_position;
	void GeneratePossiblePositions();
	void Shift3(const PositionMatrix &base_position, const int bit_check, int direction);
	void Shift64(const PositionMatrix &base_position);
};

