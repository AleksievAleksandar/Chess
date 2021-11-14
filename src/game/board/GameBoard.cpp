//Coresponding header
#include "game/board/GameBoard.h"

//C system includes

//C++ system includes
#include <iostream>

//Thitrd-party includes

//Own includes

int32_t GameBoard::init(const int32_t boardRsrcId)
{
	this->_boardImg.create(boardRsrcId);

	return EXIT_SUCCESS;
}

void GameBoard::draw()
{
	this->_boardImg.draw();
}
