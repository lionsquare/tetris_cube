#pragma once
#include <string>
#include <vector>
#include <set>
#include "PositionMatrix.h"


class Piece
{
public:
	Piece(std::string new_name, PositionMatrix given_position);
	Piece(std::string new_name, int given_position[4][4][4]);
	~Piece();
	std::vector<PositionMatrix> GetPossiblePositions();
	std::vector<unsigned long long> GetBitVectors();
	bool RunUnitTests();
private:
	std::string name;
	std::vector<PositionMatrix> possible_positions;
	std::set<PositionMatrix> rotations;
	PositionMatrix original_position;
	void GeneratePossiblePositions();
	void Shift64(const PositionMatrix &base_position);
	void GenerateRotations();
};

