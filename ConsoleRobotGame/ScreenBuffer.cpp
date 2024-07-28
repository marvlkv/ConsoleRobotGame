#include "ScreenBuffer.h"

void ScreenBuffer::_SetChar(char* wb, unsigned int wb_width, unsigned int wb_height, unsigned int x, unsigned int y, char ch) {
	if (wb == nullptr) return;
	if (x >= wb_width || y >= wb_height) return;

	wb[y * wb_width + x] = ch;
}

char ScreenBuffer::_GetChar(char* wb, unsigned int wb_width, unsigned int wb_height, unsigned int x, unsigned int y) {
	if (wb == nullptr) return 0;
	if (x >= wb_width || y >= wb_height) return 0;

	return wb[y * wb_width + x];
}

void ScreenBuffer::SetChar(unsigned int x, unsigned int y, char ch) {
	_SetChar(buffer, current_width, current_height, x, y, ch);
}

char ScreenBuffer::GetChar(unsigned int x, unsigned int y) {
	return _GetChar(buffer, current_width, current_height, x, y);
}

ScreenBuffer::ScreenBuffer(unsigned int width, unsigned int height) {
	buffer = nullptr;

	UpdateBufferSize(width, height);
}

void ScreenBuffer::UpdateBufferSize(unsigned int width, unsigned int height) {
	auto old_buffer = buffer;
	auto old_width = current_width;
	auto old_height = current_height;

	buffer = new char[width * height];
	current_width = width;
	current_height = height;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			SetChar(col, row, _GetChar(old_buffer, old_width, old_height, col, row));
		}
	}

	if (old_buffer != nullptr) {
		delete[] old_buffer;
	}
}

void ScreenBuffer::Clear() {
	for (int row = 0; row < current_height; row++) {
		for (int col = 0; col < current_width; col++) {
			SetChar(col, row, 0);
		}
	}
}

unsigned int ScreenBuffer::GetBufferWidth() {
	return current_width;
}

unsigned int ScreenBuffer::GetBufferHeight() {
	return current_height;
}
