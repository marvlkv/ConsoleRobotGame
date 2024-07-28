#include "Draw.h"

Draw::Draw(ScreenBuffer& buf) {
	buffer = &buf;
}

void Draw::LineCharHorizontal(int x, int y, int len, char sym) {
	for (int i = 0; i < len; i++) {
		buffer->SetChar(x + i, y, sym);
	}
}

void Draw::Text(std::string s, int x, int y) {
	for (int i = 0; i < s.length(); i++) {
		buffer->SetChar(x + i, y, s[i]);
	}
}
