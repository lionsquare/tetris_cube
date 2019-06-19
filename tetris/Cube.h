#pragma once
#include <vector>
#include <tuple>
#include <set>
#define CUBE_SIZE 64


typedef struct _Move
{
	unsigned int piece_type;
	unsigned long long bits;
} Move;

class Cube
{
public:
	Cube();
	~Cube();
	void Solve();
private:
	int cube_bits[64];
	std::vector<std::vector<unsigned long long>> pieces;
	Move moves_taken[12];
	std::vector<Move> starting_moves;
	std::vector<std::vector<Move>> possibility_tree;
	std::vector<Move> UpdatePossibilities(std::vector<Move>, Move);
	bool PossibilitiesRemain(std::vector<Move>);
	std::set<int> remaining_pieces;
};

