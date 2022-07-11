#include "Scene1.h"
#include "Mtx44.h"
#include "glfw/include/GLFW/glfw3.h"
#include "glew/include/GL/glew.h"

Mtx44 QuickScale(float x = 1.f,float y = 1.f, float z = 1.f);
Mtx44 QuickRotate(float degrees, float x = 0, float y = 0, float z = 0);
Mtx44 QuickTranslate(float x = 0, float y = 0, float z = 0);