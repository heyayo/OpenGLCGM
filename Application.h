
#ifndef APPLICATION_H
#define APPLICATION_H

#include "Common/timer.h"

#ifdef _WIN32

class Application
{
public:
	Application();
	~Application();
	void Init();
	void Run();
	void Exit();
	static bool IsKeyPressed(unsigned short key);

private:

	//Declare a window object
	StopWatch m_timer;
};

#elif __linux__

#include <SDL2/SDL_scancode.h>

class Application
{
	public:
	Application();
	~Application();
	void Init();
	void Run();
	void Exit();
	static bool IsKeyPressed(SDL_Scancode key);

	private:
	StopWatch m_timer;
	static const Uint8* state;
};

#endif

#endif