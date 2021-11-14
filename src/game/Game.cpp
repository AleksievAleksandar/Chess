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
	if (EXIT_SUCCESS != this->_gameBoard.init(cfg.chessBoardRsrcId))
	{
		std::cerr << "ERROR -> _gameBoard.init() failed with chessBoardRsrcId: " << cfg.chessBoardRsrcId << std::endl;
		return EXIT_FAILURE;
	}

	ChessPieceCfg pieceCfg;
	pieceCfg.boardPos.row = 7;
	pieceCfg.boardPos.col = 7;
	pieceCfg.playerId = BLACK_PLAYER_ID;
	pieceCfg.rsrcId = cfg.blackPiecesRsrcId;
	pieceCfg.pieceType = PieceType::ROOK;
	if (EXIT_SUCCESS != this->_piece.init(pieceCfg))
	{
		std::cerr << "ERROR -> _piece.init() failed." << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void Game::deInit()
{

}

void Game::draw()
{
	this->_gameBoard.draw();
	this->_piece.draw();
}

void Game::handleEvent([[maybe_unused]]const InputEvent& event)
{

}


