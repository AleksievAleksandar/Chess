//Coresponding header
#include "game/board/GameBoard.h"

//C system includes

//C++ system includes
#include <iostream>

//Thitrd-party includes

//Own includes
#include "game/utils/BoardUtils.h"

int32_t GameBoard::init(const int32_t boardRsrcId, int32_t targetRsrcId, int32_t blinkTimerId)
{
	this->_boardImg.create(boardRsrcId);
	this->_targetImg.create(targetRsrcId);
	this->_targetImg.hide();
	this->_blinkTimerId = blinkTimerId;

	return EXIT_SUCCESS;
}

void GameBoard::draw() const
{
	this->_boardImg.draw();
	this->_targetImg.draw();
}

void GameBoard::onPieceGrabbed(const BoardPos& boardPos)
{
	this->_targetImg.setPossition(BoardUtils::getAbsPos(boardPos));
	this->_targetImg.show();

	this->startTimer(1000, this->_blinkTimerId, TimerType::PULSE);
}

void GameBoard::onPieceUngrabbed()
{
	this->_targetImg.hide();

	if (this->isActiveTimerId(this->_blinkTimerId))
	{
		this->stopTimer(this->_blinkTimerId);
	}
}

void GameBoard::onTimeout(int32_t timerId)
{
	if (this->_blinkTimerId == timerId)
	{
		if (this->_targetImg.isVisible())
		{
			this->_targetImg.hide();
		}
		else
		{
			this->_targetImg.show();
		}
	}
	else
	{
		std::cerr << "ERROR -> received unsupported timerId: " << timerId << std::endl;
	}
}
