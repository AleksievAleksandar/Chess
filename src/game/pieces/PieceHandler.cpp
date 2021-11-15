//Coresponding header
#include "game/pieces/PieceHandler.h"

//C system includes

//C++ system includes
#include <iostream>

//Thitrd-party includes

//Own includes
#include "sdl_utils/InputEvent.h"
#include "game/utils/BoardUtils.h"
#include "game/proxies/GameBoardProxy.h"

namespace  
{
constexpr auto STARTING_PIECES_COUNT = 16;
constexpr auto PAWNS_COUNT = 8;

constexpr auto WHITE_PLAYER_START_PAWN_ROW = 6;
constexpr auto BLACK_PLAYER_START_PAWN_ROW = 1;
};

int32_t PieceHandler::init(GameBoardProxy* gameBoardProxy, const int32_t whitePiecesRsrcId, const int32_t blackPiecesRsrcId)
{
	if (gameBoardProxy == nullptr)
	{
		std::cerr << "ERROR -> init() failed with nullptr for gameBoardProxy." << std::endl;
		return EXIT_FAILURE;
	}
	this->_gameBoardProxy = gameBoardProxy;

	if (EXIT_SUCCESS != this->populateWhitePieces(whitePiecesRsrcId))
	{
		std::cerr << "ERROR -> populateWhitePieces() failed with rsrcId: " << whitePiecesRsrcId << std::endl;
		return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != this->populateBlackPieces(blackPiecesRsrcId))
	{
		std::cerr << "ERROR -> populateBlackPieces() failed with rsrcId: " << blackPiecesRsrcId << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

void PieceHandler::draw() const
{
	for (const auto& playerPieces : this->_pieces)
	{
		for (const auto& piece : playerPieces)
		{
			piece.draw();
		}
	}
}

void PieceHandler::handleEvent(const InputEvent& event)
{
	this->_isPieceGrabbed ? this->handlePieceGrabbedEvent(event) : this->handlePieceUngrabbedEvent(event);
}

void PieceHandler::handlePieceGrabbedEvent(const InputEvent& event)
{
	if (event.type != TouchEvent::TOUCH_RELEASE)
	{
		return;
	}

	if (!BoardUtils::isInsideBoard(event.pos))
	{
		return;
	}

	this->_isPieceGrabbed = false;

	const BoardPos boardPos = BoardUtils::getBoardPos(event.pos);
	this->_pieces[this->_selectedPiecePlayerId][this->_selectedPieceId].setBoardPos(boardPos);
	this->_gameBoardProxy->onPieceUngrabbed();
}

void PieceHandler::handlePieceUngrabbedEvent(const InputEvent& event)
{
	if (event.type != TouchEvent::TOUCH_RELEASE)
	{
		return;
	}

	int32_t currPlayerId = Defines::WHITE_PLAYER_ID;
	for (const auto& playerPieces : this->_pieces)
	{
		int32_t relativePieceId = 0;
		for (const auto& piece : playerPieces)
		{
			if (piece.containsEvent(event))
			{
				this->_selectedPieceId = relativePieceId;
				this->_selectedPiecePlayerId = currPlayerId;

				this->_isPieceGrabbed = true;
				this->_gameBoardProxy->onPieceGrabbed(BoardUtils::getBoardPos(event.pos));

				return;
			}

			++relativePieceId;
		}
		++currPlayerId;
	}
}

int32_t PieceHandler::populateWhitePieces(const int32_t rsrcId)
{
	auto& whites = this->_pieces[Defines::WHITE_PLAYER_ID];
	whites.resize(STARTING_PIECES_COUNT);

	ChessPieceCfg pieceCfg;
	pieceCfg.boardPos.row = WHITE_PLAYER_START_PAWN_ROW;
	pieceCfg.playerId = Defines::WHITE_PLAYER_ID;
	pieceCfg.rsrcId = rsrcId;
	pieceCfg.pieceType = PieceType::PAWN;

	for (auto i = 0; i < PAWNS_COUNT; ++i)
	{
		pieceCfg.boardPos.col = i;

		if (EXIT_SUCCESS != whites[i].init(pieceCfg))
		{
			std::cerr << "ERROR -> _piece.init() failed." << std::endl;
			return EXIT_FAILURE;
		}
	}

	constexpr auto nonPawnCount = PAWNS_COUNT;
	constexpr PieceType nonPawnTypes[nonPawnCount] = { PieceType::ROOK, PieceType::KNIGHT, PieceType::BISHOP, PieceType::QUEEN,
													   PieceType::KING, PieceType::BISHOP, PieceType::KNIGHT, PieceType::ROOK };

	pieceCfg.boardPos.row = WHITE_PLAYER_START_PAWN_ROW + 1;
	for (auto i = nonPawnCount; i < STARTING_PIECES_COUNT; ++i)
	{
		pieceCfg.boardPos.col = i - nonPawnCount;
		pieceCfg.pieceType = nonPawnTypes[i - nonPawnCount];

		if (EXIT_SUCCESS != whites[i].init(pieceCfg))
		{
			std::cerr << "ERROR -> _piece.init() failed." << std::endl;
			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;
}

int32_t PieceHandler::populateBlackPieces(const int32_t rsrcId)
{
	auto& blacks = this->_pieces[Defines::BLACK_PLAYER_ID];
	blacks.resize(STARTING_PIECES_COUNT);

	ChessPieceCfg pieceCfg;
	pieceCfg.boardPos.row = BLACK_PLAYER_START_PAWN_ROW;
	pieceCfg.playerId = Defines::BLACK_PLAYER_ID;
	pieceCfg.rsrcId = rsrcId;
	pieceCfg.pieceType = PieceType::PAWN;

	for (auto i = 0; i < PAWNS_COUNT; ++i)
	{
		pieceCfg.boardPos.col = i;

		if (EXIT_SUCCESS != blacks[i].init(pieceCfg))
		{
			std::cerr << "ERROR -> _piece.init() failed." << std::endl;
			return EXIT_FAILURE;
		}
	}

	constexpr auto nonPawnCount = PAWNS_COUNT;
	constexpr PieceType nonPawnTypes[nonPawnCount] = { PieceType::ROOK, PieceType::KNIGHT, PieceType::BISHOP, PieceType::QUEEN,
													   PieceType::KING, PieceType::BISHOP, PieceType::KNIGHT, PieceType::ROOK };

	pieceCfg.boardPos.row = BLACK_PLAYER_START_PAWN_ROW - 1;
	for (auto i = nonPawnCount; i < STARTING_PIECES_COUNT; ++i)
	{
		pieceCfg.boardPos.col = i - nonPawnCount;
		pieceCfg.pieceType = nonPawnTypes[i - nonPawnCount];

		if (EXIT_SUCCESS != blacks[i].init(pieceCfg))
		{
			std::cerr << "ERROR -> _piece.init() failed." << std::endl;
			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;
}
