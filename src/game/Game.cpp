//Coresponding header
#include "game/Game.h"

//C system includes

//C++ system includes
#include <iostream>

//Thitrd-party includes

//Own includes
#include "sdl_utils/InputEvent.h"
#include "game/defines/ChessDefines.h"

int32_t Game::init(const GameCfg& cfg)
{
	if (EXIT_SUCCESS != this->_gameBoard.init(cfg.chessBoardRsrcId, cfg.targetRsrcId, cfg.blinkTargetTimerId))
	{
		std::cerr << "ERROR -> _gameBoard.init() failed with chessBoardRsrcId: " << cfg.chessBoardRsrcId << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != this->_pieceHandler.init(&this->_gameBoard, cfg.whitePiecesRsrcId, cfg.blackPiecesRsrcId))
	{
		std::cerr << "ERROR -> _pieceHandler.init() failed with RsrcIds: " << cfg.whitePiecesRsrcId << " and " << cfg.blackPiecesRsrcId << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void Game::deInit()
{

}

void Game::draw() const
{
	this->_gameBoard.draw();
	this->_pieceHandler.draw();
}

void Game::handleEvent(const InputEvent& event)
{
	this->_pieceHandler.handleEvent(event);
}


