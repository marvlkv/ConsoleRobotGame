#pragma once
#include "ScreenBuffer.h"

struct TerminalDimentions {
	unsigned int width;
	unsigned int height;
};


class TerminalController {
public:
	TerminalDimentions GetTerminalDimentions();

	void ClearScreen();
	void WriteScreen(ScreenBuffer buffer);
};
