#ifndef GAME_BOARD_PROXY_H
#define GAME_BOARD_PROXY_H

//C system includes

//C++ system includes
#include <cstdint>

//Thitrd-party includes

//Own includes

//Forward Declarations
struct BoardPos;

class GameBoardProxy
{
public:
	virtual ~GameBoardProxy() = default;
	virtual void onPieceGrabbed(const BoardPos& boardPos) = 0;
	virtual void onPieceUngrabbed() = 0;
};

#endif // !GAME_BOARD_PROXY_H

