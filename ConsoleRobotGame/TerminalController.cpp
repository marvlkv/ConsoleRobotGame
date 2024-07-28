#include "TerminalController.h"
#include <windows.h>
#include <iostream>

TerminalDimentions TerminalController::GetTerminalDimentions() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	unsigned int columns, rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	return { columns, rows };
}

void TerminalController::ClearScreen() {
	COORD tl = { 0,0 };
	CONSOLE_SCREEN_BUFFER_INFO s;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &s);
	DWORD written, cells = s.dwSize.X * s.dwSize.Y;
	FillConsoleOutputCharacter(console, ' ', cells, tl, &written);
	FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
	SetConsoleCursorPosition(console, tl);
}

void TerminalController::WriteScreen(ScreenBuffer buffer) {
	char* temp_buffer = new char[buffer.GetBufferWidth() + 1];
	temp_buffer[buffer.GetBufferWidth()] = '\0';

	for (int row = 0; row < buffer.GetBufferHeight(); row++) {
		for (int col = 0; col < buffer.GetBufferWidth(); col++) {
			char current_char = buffer.GetChar(col, row);
			
			if (current_char < 32 || current_char > 254)
				current_char = ' ';

			temp_buffer[col] = current_char;
		}

		std::cout << temp_buffer;
	}

	delete[] temp_buffer;
}
