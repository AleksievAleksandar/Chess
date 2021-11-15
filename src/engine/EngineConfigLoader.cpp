//Coresponding header
#include "engine/EngineConfigLoader.h"

//C system includes

//C++ system includes
#include <array>
#include <string>

//Thitrd-party includes

//Own includes
#include "common/CommonDefines.h"
#include "sdl_utils/containers/ImageContainer.h"

namespace
{
	constexpr auto WINDOW_WIDTH = 900;
	constexpr auto WINDOW_HEIGHT = 900;
	constexpr auto WINDOW_NAME = "App_Engine";

	constexpr auto CHESS_PIECES_FRAMES = 6;
	constexpr auto CHESS_PIECES_IMG_WIDTH_HEIGHT = 96;

	constexpr auto CHESS_BOARD_IMG_WIDTH_HEIGHT = 900;

	constexpr auto TARGET_IMG_WIDTH_HEIGHT = 98;

	constexpr auto ANGELINE_VINTAGE_40_FONT_SIZE = 40;

	constexpr auto MAX_FRAMERATE = 60;
}

static std::string getFilePath(const std::string& relativePath)
{
#ifdef RELEASE_BUILD
	return relativePath;
#else
	return "../" + relativePath;
#endif
}

static void populateTextContainerConfig(TextContainerCfg& outCfg)
{
	FontCfg fontCfg;
	fontCfg.location = getFilePath("resources/f/AngelineVintage.ttf");
	fontCfg.fontSize = ANGELINE_VINTAGE_40_FONT_SIZE;
	outCfg.fontConfigs.insert(std::make_pair(FontId::ANGELINE_VINTAGE_40, fontCfg));
}

static void populateImageContainerConfig(ImageContainerCfg& outCfg)
{
	ImageCfg imageCfg;

	constexpr auto buttonsCnt = 2;
	const std::string buttonPaths[buttonsCnt] = { "resources/p/whitePieces.png" ,
												  "resources/p/blackPieces.png" };
	constexpr int32_t buttonRsrcIds[buttonsCnt] = { TextureId::WHITE_PIECES,
													TextureId::BLACK_PIECES };
	for (int32_t i = 0; i < buttonsCnt; ++i)
	{
		imageCfg.location = getFilePath(buttonPaths[i]);
		for (auto frameId = 0; frameId < CHESS_PIECES_FRAMES; ++frameId)
		{
			imageCfg.frames.emplace_back(frameId * CHESS_PIECES_IMG_WIDTH_HEIGHT, //x
										 0,										  //y
										 CHESS_PIECES_IMG_WIDTH_HEIGHT,			  //w
										 CHESS_PIECES_IMG_WIDTH_HEIGHT);		  //h
		}
		outCfg.imageConfigs.emplace(buttonRsrcIds[i], imageCfg);
		imageCfg.frames.clear();
	}

	imageCfg.location = getFilePath("resources/p/chessBoard.jpg");
	imageCfg.frames.emplace_back(
								 0,								//x
								 0,								//y
								 CHESS_BOARD_IMG_WIDTH_HEIGHT,	//w
								 CHESS_BOARD_IMG_WIDTH_HEIGHT);	//h

	outCfg.imageConfigs.emplace(TextureId::CHESS_BOARD, imageCfg);
	imageCfg.frames.clear();

	imageCfg.location = getFilePath("resources/p/target.png");
	imageCfg.frames.emplace_back(
								 0,							 //x
								 0,							 //y
								 TARGET_IMG_WIDTH_HEIGHT,	 //w
								 TARGET_IMG_WIDTH_HEIGHT);	 //h

	outCfg.imageConfigs.emplace(TextureId::TARGET, imageCfg);
	imageCfg.frames.clear();
}

static void populateMonitorConfig(MonitorWindowCfg& outCfg)
{
	outCfg.windowName = WINDOW_NAME;
	outCfg.windowWidth = WINDOW_WIDTH;
	outCfg.windowHeight = WINDOW_HEIGHT;
	outCfg.windowFlags = WINDOW_SHOWN;
}

static void populateRsrcMgrConfig(RsrcMgrCfg& outCfg)
{
	populateImageContainerConfig(outCfg.imageContainerCfg);
	populateTextContainerConfig(outCfg.textContainerCfg);
}

static void populateDrawMgrConfig(DrawMgrCfg& outCfg)
{
	populateMonitorConfig(outCfg.windowCfg);
	outCfg.maxFrameRate = MAX_FRAMERATE;
}

static void populateManagerHandlerCfg(ManagerHandlerCfg& outCfg)
{
	populateDrawMgrConfig(outCfg.drawMgrCfg);
	populateRsrcMgrConfig(outCfg.rsrcMgrCfg);
}

static void populateGameConfig(GameCfg& outCfg)
{
	outCfg.blackPiecesRsrcId = TextureId::BLACK_PIECES;
	outCfg.chessBoardRsrcId = TextureId::CHESS_BOARD;
	outCfg.targetRsrcId = TextureId::TARGET;
	outCfg.whitePiecesRsrcId = TextureId::WHITE_PIECES;
	outCfg.blinkTargetTimerId = TimerId::BLINK_TARGET_TIMER_ID;
}

EngineConfig EngineConfigLoader::loadConfig()
{
	EngineConfig cfg;

	populateManagerHandlerCfg(cfg.managerHandlerCfg);
	populateGameConfig(cfg.gameCfg);

	return cfg;
}
