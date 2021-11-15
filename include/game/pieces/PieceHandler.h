#ifndef PIECE_HANDLER_H
#define PIECE_HANDLER_H

//C system includes

//C++ system includes
#include <cstdint>
#include <vector>
#include <array>

//Thitrd-party includes

//Own includes
#include "game/pieces/types/ChessPiece.h"
#include "game/defines/ChessDefines.h"

//Forward Declarations
struct InputEvent;
struct GameBoardProxy;

class PieceHandler 
{
public:
	int32_t init(GameBoardProxy* gameBoardProxy, const int32_t whitePiecesRsrcId, const int32_t blackPiecesRsrcId);
	void draw() const;
	void handleEvent(const InputEvent& event);

private:
	void handlePieceGrabbedEvent(const InputEvent& event);
	void handlePieceUngrabbedEvent(const InputEvent& event);

	int32_t populateWhitePieces(const int32_t rsrcId);
	int32_t populateBlackPieces(const int32_t rsrcId);

	using PlayerPieces = std::vector<ChessPiece>;

	std::array<PlayerPieces, Defines::PLAYERS_COUNT> _pieces;
	int32_t _selectedPieceId = 0;
	int32_t _selectedPiecePlayerId = 0;
	bool _isPieceGrabbed = false;
	GameBoardProxy* _gameBoardProxy = nullptr;
};

#endif // !PIECE_HANDLER_H

