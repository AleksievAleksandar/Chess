#ifndef GAME_BOARD_H
#define GAME_BOARD_H

//C system includes

//C++ system includes
#include <cstdint>

//Thitrd-party includes

//Own includes
#include "manager_utils/drawing/Image.h"

//Forward Declarations

class GameBoard 
{
public:
	int32_t init(const int32_t boardRsrcId);
	void draw();

private:
	Image _boardImg;
};


#endif // !GAME_BOARD_H

