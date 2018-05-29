#include <stdlib.h>
#include "Block.h"
#include "Console.h"
#include "Board.h"

// ��, ��, ��, s, z, ��, 1, 

// 01
// 23
// 45
// 67
// �� = 0, 1, 3, 5
// �� = 0, 2, 4, 5

static int coords[][4] = {
	{ 0, 1, 3, 5 }, // ��
	{ 0, 2, 4, 5 }, // ��
	{ 0, 2, 3, 4 }, // ��
	{ 0, 3, 4, 5 }, // s
	{ 1, 2, 3, 4 }, // z
	{ 0, 1, 2, 3 }, // ��
	{ 0, 2, 4, 6 } // 1
};

Block::Block()
{
	type = 1;
	//x = 0, y = 0;
}


Block::~Block()
{
}

void Block::init()
{
	int t = rand() % 7 + 1;
	init(t, 0, 0);
}

void Block::init(int type, int x, int y)
{
	this->type = type;

	for (int i = 0; i < 4; i++) {
		int v = coords[type - 1][i];
		int dx = v % 2;
		int dy = v / 2;
		points[i].x = x + dx;
		points[i].y = y + dy;
	}
}

// 01
// 23
// 45
// 67

void Block::draw()
{
	for (int i = 0; i < 4; i++) {
		Console::setCursor(points[i].x, points[i].y);
		Console::putChar('O');
	}
}

bool Block::move(int dx)
{
	int width = Board::get().getWidth();

	for (int i = 0; i < 4; i++) {
		int nx = points[i].x + dx;
		if (nx < 0 || nx >= width) {
			return false;
		}
		//points[i].x = nx;
	}

	for (int i = 0; i < 4; i++) {
		points[i].x += dx;
	}
	return true;
}

bool Block::moveDown()
{
	int height = Board::get().getHeight();

	for (int i = 0; i < 4; i++) {
		int ny = points[i].y + 1;
		if (ny >= height) {
			return false;
		}
	}

	for (int i = 0; i < 4; i++) {
		points[i].y++;
	}
	return true;
}

bool Block::rotate()
{
	int width = Board::get().getWidth();
	int height = Board::get().getHeight();

	int x = points[1].x;
	int y = points[1].y;

	Point copy[4];

	for (int i = 0; i < 4; i++) {
		int dx = points[i].x - x;
		int dy = points[i].y - y;
		int nx = x + dy;
		int ny = y - dx;
		if (nx < 0 || nx >= width) {
			return false;
		}
		if (ny >= height) {
			return false;
		}
		copy[i].x = nx;
		copy[i].y = ny;
	}

	for (int i = 0; i < 4; i++) {
		points[i] = copy[i];
	}

	return true;
}
