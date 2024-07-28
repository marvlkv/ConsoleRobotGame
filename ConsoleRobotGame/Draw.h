#pragma once
#include <string>
#include "ScreenBuffer.h"

class Draw {
private:
	ScreenBuffer* buffer;

public:
	Draw(ScreenBuffer &buf);

	void LineCharHorizontal(int x, int y, int len, char sym);
	void Text(std::string s, int x, int y);
	void TextBox(std::string s, int x, int y, int w, int h);
};
