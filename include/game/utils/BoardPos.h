#ifndef BOARD_POS_H
#define BOARD_POS_H

//C system includes

//C++ system includes
#include <cstdint>

//Thitrd-party includes

//Own includes

//Forward Declarations

struct BoardPos
{
	BoardPos() = default;
	BoardPos(int32_t inputRow, int32_t inputCol) :
		row(inputRow), col(inputCol) {}

	int32_t row{};
	int32_t col{};
};

#endif // !BOARD_POS_H

