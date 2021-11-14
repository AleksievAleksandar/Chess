#ifndef GAME_H
#define GAME_H

//C system includes

//C++ system includes
#include <cstdint>

//Thitrd-party includes

//Own includes
#include "manager_utils/drawing/Image.h"
#include "game/config/GameCfg.h"
#include "game/board/GameBoard.h"
#include "game/pieces/types/ChessPiece.h"

//Forward Declarations
struct InputEvent;

class Game
{
public:
	int32_t init(const GameCfg& cfg);
	void deInit();
	void draw();
	void handleEvent(const InputEvent& event);

private:
	GameBoard _gameBoard;

	ChessPiece _piece;
};

#endif // !GAME_H
