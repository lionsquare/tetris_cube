#include <iostream>
#include <iomanip>
#include "Cube.h"
#include "PositionMatrix.h"
#include "Piece.h"
#include "TetrisPieces.h"

Cube::Cube()
{

	Cube::pieces.push_back(Piece("Abraham", Abraham).GetBitVectors());
	Cube::pieces.push_back(Piece("Deedee", Deedee).GetBitVectors());
	Cube::pieces.push_back(Piece("Estelle", Estelle).GetBitVectors());
	Cube::pieces.push_back(Piece("Gunther", Gunther).GetBitVectors());
	Cube::pieces.push_back(Piece("Hester", Hester).GetBitVectors());
	Cube::pieces.push_back(Piece("Joey", Joey).GetBitVectors());
	Cube::pieces.push_back(Piece("Lucy", Lucy).GetBitVectors());
	Cube::pieces.push_back(Piece("Percy", Percy).GetBitVectors());
	Cube::pieces.push_back(Piece("Rita", Rita).GetBitVectors());
	Cube::pieces.push_back(Piece("Steve", Steve).GetBitVectors());
	Cube::pieces.push_back(Piece("Tim", Tim).GetBitVectors());
	Cube::pieces.push_back(Piece("Zachary", Zachary).GetBitVectors());


	for (int a = 0; a < CUBE_SIZE; a++)
	{
		Cube::cube_bits[a] = 0;
	}
	for (unsigned int piece_id = 0; piece_id < Cube::pieces.size(); piece_id++)
	{
		Cube::moves_taken[piece_id].piece_type = 0;
		Cube::moves_taken[piece_id].bits = 0;
		Cube::remaining_pieces.insert(piece_id + 1);
		for (unsigned int b = 0; b < Cube::pieces[piece_id].size(); b++)
		{
			Move move = {piece_id + 1, Cube::pieces[piece_id][b]};
			Cube::starting_moves.push_back(move);
		}
	}

	Cube::possibility_tree.clear();
	Cube::possibility_tree.push_back(Cube::starting_moves);
}


Cube::~Cube()
{
}


void Cube::Solve(void)
{
	int move_index = 0;
	while ((move_index < N_PIECES) && (move_index >=0))
	{
		unsigned int level_moves = Cube::possibility_tree[move_index].size();
		//std::cout << "Move " << move_index << ":" << level_moves << " possibilities " << std::endl;

		// Make move
		Move my_move = Cube::possibility_tree[move_index].back();
		Cube::moves_taken[move_index] = my_move;
		Cube::possibility_tree[move_index].pop_back();
		Cube::remaining_pieces.erase(Cube::remaining_pieces.find(moves_taken[move_index].piece_type));
		//std::cout << "Making move " << my_move.piece_type << std::endl;

		// Update
		std::vector<Move> next_level = Cube::UpdatePossibilities(possibility_tree[move_index], my_move);
		Cube::possibility_tree.push_back(next_level);
		move_index++;
		
		if (move_index == 11)
		{
			std::cout << "success!" << std::endl;
			break;
		}

		// Check if possible
		while (!Cube::PossibilitiesRemain(next_level))
		{
			move_index--;
			Cube::possibility_tree.pop_back();
			Cube::remaining_pieces.insert(Cube::moves_taken[move_index].piece_type);
			Move blank_move = { 0, 0 };
			Cube::moves_taken[move_index] = blank_move;
			next_level = Cube::possibility_tree[move_index];
		}
		unsigned int end_level_moves = Cube::possibility_tree[move_index].size();
	}

	std::cout << "Solved!" << std::endl;
	for (int a = 0; a < 12; a++)
	{
		std::cout << Cube::moves_taken[a].piece_type << "\t" << std::setfill('0') << std::setw(16) << std::hex << moves_taken[a].bits << std::endl;
		PositionMatrix P;
		P.SetMatrix(moves_taken[a].bits);
		P.Display();
	}
	// apply contraints to eliminate possibilities
	// check that there are solutions left
	// undo move or pick next move
}

std::vector<Move> Cube::UpdatePossibilities(std::vector<Move> possible_moves, Move last_move)
{
	std::vector<Move> next_possible_moves;
	for (unsigned int a = 0; a < possible_moves.size(); a++)
	{
		bool still_possible = true;
		still_possible &= (possible_moves[a].piece_type != last_move.piece_type);
		still_possible &= ((possible_moves[a].bits & last_move.bits) == 0);
		if (still_possible)
		{
			next_possible_moves.push_back(possible_moves[a]);
		}
	}
	return next_possible_moves;
}


bool Cube::PossibilitiesRemain(std::vector<Move> possible_moves)
{
	std::set<int>::iterator it;
	for (it = Cube::remaining_pieces.begin(); it != Cube::remaining_pieces.end(); it++)
	{
		int num_to_look_for = *it;
		if (num_to_look_for == 0)
		{
			std::cout << "How did a 0 get in??" << std::endl;
		}
		bool num_found = false;
		for (unsigned int a = 0; a < possible_moves.size(); a++)
		{
			if (possible_moves[a].piece_type == num_to_look_for)
			{
				num_found = true;
				break;
			}
		}
		if (!num_found)
		{
			return false;
		}
	}
	return true;
}