#include <iostream>
#include "TerminalController.h"
#include "ScreenBuffer.h"
#include "Draw.h"
#include "GameLoop.h"

void ScreenUpdate(GameLoop *loop) {
    // ...
}

int main() {
    TerminalController controller;
    TerminalDimentions dimentions = controller.GetTerminalDimentions();

    ScreenBuffer buffer(dimentions.width, dimentions.height);
    buffer.Clear();

    Draw draw(buffer);
    draw.Text("Hello world!", 27, 5);

    controller.ClearScreen();
    controller.WriteScreen(buffer);

    GameLoop loop;
    loop.RegisterUpdate(&ScreenUpdate);
    loop.Run(4);
}
