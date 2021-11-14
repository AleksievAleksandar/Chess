#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

//C system includes

//C++ system includes
#include <cstdint>

//Thitrd-party includes

//Own includes
#include "game/utils/BoardPos.h"
#include "game/defines/ChessDefines.h"
#include "manager_utils/drawing/Image.h"

//Forward Declarations
struct InputEvent;

struct ChessPieceCfg
{
	BoardPos boardPos{};
	int32_t playerId{};
	int32_t rsrcId = INVALID_RSRC_ID;
	PieceType pieceType = PieceType::UNKNOWN;
};

class ChessPiece 
{
public:
	int32_t init(const ChessPieceCfg& cfg);
	void draw();
	void handleEvent(const InputEvent& event);

private:
	Image _pieceImg;
	BoardPos _boardPos;
	int32_t _playerId;
	PieceType _pieceType;
};

#endif // !CHESS_PIECE_H

