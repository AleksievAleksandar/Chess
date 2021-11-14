//Coresponding header
#include "game/pieces/types/ChessPiece.h"

//C system includes

//C++ system includes
#include <iostream>

//Thitrd-party includes

//Own includes
#include "game/utils/BoardUtils.h"

int32_t ChessPiece::init(const ChessPieceCfg& cfg)
{
	if (cfg.pieceType == PieceType::UNKNOWN)
	{
		std::cerr << "ERROR -> ChessPiece::init() failed. REASON: Unknown PieceType provided." << std::endl;
		return EXIT_FAILURE;
	}

	if (cfg.rsrcId == INVALID_RSRC_ID)
	{
		std::cerr << "ERROR -> ChessPiece::init() failed. REASON: INVALID_RSRC_ID provided." << std::endl;
		return EXIT_FAILURE;
	}

	this->_boardPos = cfg.boardPos;
	this->_playerId = cfg.playerId;
	this->_pieceType = cfg.pieceType;

	this->_pieceImg.create(cfg.rsrcId, BoardUtils::getAbsPos(this->_boardPos));
	this->_pieceImg.setFrame(static_cast<int32_t>(this->_pieceType));

	return EXIT_SUCCESS;
}

void ChessPiece::draw()
{
	this->_pieceImg.draw();
}

void ChessPiece::handleEvent([[maybe_unused]]const InputEvent& event)
{
}
