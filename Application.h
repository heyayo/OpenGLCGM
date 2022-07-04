
#ifndef APPLICATION_H
#define APPLICATION_H

#include "Common/timer.h"

#ifdef _WIN32
#define GLEW_STATIC
#pragma comment(lib, "OpenGL32.lib")

class Application
{
public:
	Application();
	~Application();
	void Init();
	void Run();
	void Exit();
	static bool IsKeyPressed(int key);

private:

	//Declare a window object
	StopWatch m_timer;
};

#elif __linux__

class Application
{
	public:
	Application();
	~Application();
	void Init();
	void Run();
	void Exit();
	static bool IsKeyPressed(int key);

	private:
	StopWatch m_timer;
};

#endif

#endif