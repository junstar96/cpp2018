#include "Board.h"

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20

Board *Board::s_board;

Board::Board()
{
	s_board = this;

	const int size = BOARD_WIDTH * BOARD_HEIGHT;
	bits = new int[size];
	for (int i = 0; i < size; i++) {
		bits[i] = 0;
	}
}


Board::~Board()
{
	delete[] bits;
}

//Board &Board::get()
//{
//	return *g_board;
//}

//inline int Board::getWidth()
//{
//	return width;
//}
//
//inline int Board::getHeight()
//{
//	return height;
//}
