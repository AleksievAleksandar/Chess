#ifndef BOARD_UTILS_H
#define BOARD_UTILS_H

//C system includes

//C++ system includes
#include <cstdint>

//Thitrd-party includes

//Own includes
#include "utils/drawing/Point.h"
#include "game/utils/BoardPos.h"

//Forward Declarations

class BoardUtils
{
public:
	static BoardPos getBoardPos(const Point& absPos);
	static Point getAbsPos(const BoardPos& boardPos);
	static bool isInsideBoard(const BoardPos& boardPos);
	static bool isInsideBoard(const Point& absPos);
};

#endif // !BOARD_UTILS_H

