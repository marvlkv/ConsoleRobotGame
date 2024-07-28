#pragma once
class ScreenBuffer {
private:
	char* buffer;
	unsigned int current_width;
	unsigned int current_height;

	void _SetChar(char* wb, unsigned int wb_width, unsigned int wb_height, unsigned int x, unsigned int y, char ch);
	char _GetChar(char* wb, unsigned int wb_width, unsigned int wb_height, unsigned int x, unsigned int y);

public:
	ScreenBuffer(unsigned int width, unsigned int height);

	// Обновить размер буфера, если изменились размеры терминала
	void UpdateBufferSize(unsigned int width, unsigned int height);

	void SetChar(unsigned int x, unsigned int y, char ch);
	char GetChar(unsigned int x, unsigned int y);

	void Clear();

	unsigned int GetBufferWidth();
	unsigned int GetBufferHeight();
};

