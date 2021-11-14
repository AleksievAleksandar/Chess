#ifndef CHESS_DEFINES_H
#define CHESS_DEFINES_H

//C system includes

//C++ system includes
#include <cstdint>

//Thitrd-party includes

//Own includes

//Forward Declarations

enum PlayerId {
	WHITE_PLAYER_ID, 
	BLACK_PLAYER_ID,

	PLAYERS_COUNT
};

enum class PieceType : uint8_t {
	KING, 
	QUEEN, 
	BISHOP, 
	KNIGHT, 
	ROOK, 
	PAWN,

	UNKNOWN
};

#endif // !CHESS_DEFINES_H
