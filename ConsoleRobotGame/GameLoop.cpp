#include <windows.h>
#include "GameLoop.h"

void GameLoop::RegisterUpdate(void (*U)(GameLoop*)) {
	Update = U;
}

void GameLoop::Run(unsigned int fps) {
	while (true) {
		Update(this);
		Sleep((unsigned int)(1. / fps * 1000));
	}
}
