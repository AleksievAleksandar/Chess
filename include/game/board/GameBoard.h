#ifndef GAME_BOARD_H
#define GAME_BOARD_H

//C system includes

//C++ system includes
#include <cstdint>

//Thitrd-party includes

//Own includes
#include "manager_utils/drawing/Image.h"
#include "game/proxies/GameBoardProxy.h"
#include "manager_utils/time/TimerClient.h"

//Forward Declarations

class GameBoard : public GameBoardProxy,
				  public TimerClient
{
public:
	int32_t init(const int32_t boardRsrcId, int32_t targetRsrcId, int32_t blinkTimerId);
	void draw() const;

private:
	void onPieceGrabbed(const BoardPos& boardPos) override;
	void onPieceUngrabbed() override;
	void onTimeout(int32_t timerId) override;

	Image _boardImg;
	Image _targetImg;
	int32_t _blinkTimerId;
};


#endif // !GAME_BOARD_H

