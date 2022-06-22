#include "Camera.h"
#include "Application.h"

/******************************************************************************/
/*!
\brief
Default constructor
*/
/******************************************************************************/
Camera::Camera()
{
}

/******************************************************************************/
/*!
\brief
Destructor
*/
/******************************************************************************/
Camera::~Camera()
{
}

/******************************************************************************/
/*!
\brief
Initialize camera

\param pos - position of camera
\param target - where the camera is looking at
\param up - up vector of camera
*/
/******************************************************************************/
void Camera::Init(const Vector3& pos, const Vector3& target, const Vector3& up)
{
	this->position = pos;
	this->target = target;
	this->up = up;
}

/******************************************************************************/
/*!
\brief
Reset the camera settings
*/
/******************************************************************************/
void Camera::Reset()
{
}

/******************************************************************************/
/*!
\brief
To be called every frame. Camera will get user inputs and update its position and orientation

\param dt - frame time
*/
/******************************************************************************/
void Camera::Update(double dt)
{
	static const float CAMERA_SPEED = 10.f;
	#ifdef _WIN32
	if(Application::IsKeyPressed('W'))
		this->position.y += CAMERA_SPEED * static_cast<float>(dt); //move camera up
	if (Application::IsKeyPressed('A'))
		this->position.x -= CAMERA_SPEED * static_cast<float>(dt); //move camera left
	if (Application::IsKeyPressed('S'))
		this->position.y -= CAMERA_SPEED * static_cast<float>(dt); //move camera down
	if (Application::IsKeyPressed('D'))
		this->position.x += CAMERA_SPEED * static_cast<float>(dt); //move camera right
	#elif __linux__
	if(Application::IsKeyPressed(SDL_SCANCODE_W))
		this->position.y += CAMERA_SPEED * static_cast<float>(dt); //move camera up
	if (Application::IsKeyPressed(SDL_SCANCODE_A))
		this->position.x -= CAMERA_SPEED * static_cast<float>(dt); //move camera left
	if (Application::IsKeyPressed(SDL_SCANCODE_S))
		this->position.y -= CAMERA_SPEED * static_cast<float>(dt); //move camera down
	if (Application::IsKeyPressed(SDL_SCANCODE_D))
		this->position.x += CAMERA_SPEED * static_cast<float>(dt); //move camera right
	#endif
}