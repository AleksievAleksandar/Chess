#ifndef COMMON_DEFINES_H
#define COMMON_DEFINES_H

//C system includes

//C++ system includes
#include <cstdint>

//Thitrd-party includes

//Own includes

//Forward Declarations


namespace TextureId
{
	enum ResourceId
	{ 
		CHESS_BOARD,
		TARGET,
		WHITE_PIECES,
		BLACK_PIECES
	};
} //namespace TextureId

namespace FontId
{
	enum FontIdKeys
	{
		ANGELINE_VINTAGE_40
	};
} //namespace FontId

namespace TimerId
{
	enum Keys
	{
		BLINK_TARGET_TIMER_ID
	};
} //namespace TimerId


#endif // !COMMON_DEFINES_H
