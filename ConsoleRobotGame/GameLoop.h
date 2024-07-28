#pragma once

class GameLoop {
private:
	void (*Update)(GameLoop*);

public:
	void RegisterUpdate(void (*U)(GameLoop*));

	void Run(unsigned int fps);
};

