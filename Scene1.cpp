#include "Scene1.h"
#include "glew/include/GL/glew.h"
#include "glfw/include/GLFW/glfw3.h"

#include "shader.hpp"
#include "Application.h"
#include "Common/Mtx44.h"
#include "MeshBuilder.h"
#include "RenderMan.hpp"

Scene1::Scene1()
{
}

Scene1::~Scene1()
{
}

void Scene1::Init()
{
	// Set background color to dark blue
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	//Enable depth buffer and depth testing
	glEnable(GL_DEPTH_TEST);

	//Enable back face culling
	glEnable(GL_CULL_FACE);

	//Default to fill mode
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Generate a default VAO for now
	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);

	// Load the shader programs
	m_programID = LoadShaders("Shader//TransformVertexShader.vertexshader",
								"Shader//SimpleFragmentShader.fragmentshader");
	glUseProgram(m_programID);

	// Get a handle for our "MVP" uniform
	m_parameters[U_MVP] = glGetUniformLocation(m_programID, "MVP");
	

	// Initialise the camera
	camera.Init(Vector3(4, 3, 3), Vector3(0, 0, 0), Vector3(0, 1, 0));

	// Init VBO here
	for (int i = 0; i < NUM_GEOMETRY; ++i)
	{
		meshList[i] = nullptr;
	}

	meshList[GEO_AXES] = MeshBuilder::GenerateAxes("reference", 1000, 1000, 1000);
	meshList[GEO_QUAD] = MeshBuilder::GenerateQuad("Plane", Color(1,1,1));
}

void Scene1::Update(double dt)
{
	// Check for key press, you can add more for interaction
	HandleKeyPress();

	// Update the camera object
	camera.Update(dt);
}

void Scene1::Render()
{
	// Define the matrices to handle transformation
	Mtx44 view;
	Mtx44 projection;
	Mtx44 MVP;

	// Always set the model matrix to identity
	// i.e. placed at origin, scale 1 and rotation 0

	// Use the camera as the view matrix
	view.SetToLookAt(
		camera.position.x, camera.position.y, camera.position.z,
		camera.target.x, camera.target.y, camera.target.z,
		camera.up.x, camera.up.y, camera.up.z
	);

	// FOV, Aspect Ratio, Near plane, Far plane
	projection.SetToPerspective(45.0f, 4.0f / 3.0f, 0.1f, 1000.0f); 

	// Clear color buffer every frame
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	RenderMan r(view,projection,MVP);

	r.MVP(r.GetIdentity());
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

	// Render VBO here
	meshList[GEO_AXES]->Render();

	// EXAMPLE RENDER USING RENDERMAN
	r.MVP(r.Translate(1,1,1) * r.Rotate(45,0,1,0) * r.Scale(0.5,0.5,0.5)); // This sets the new MVP to use with the new object
	SR(GEO_QUAD) // This does the glUniformMatrix4fv thing and calls Render on the object

	// EXAMPLE RENDER USING WITH MATRIX STACKS
	RenderMan stackeg(view,projection,MVP);

	stackeg.PushN(stackeg.Scale(1.f,2.f)); // First Matrix to Scale by 2 on Y
	stackeg.SMVP(stackeg.Translate(1.f,1.f,1.f)); // Multiplies the first matrix and the new matrix given as parameters with the view and projection to get the MVP
	SR(GEO_QUAD) // Render
}

void Scene1::Exit()
{
	// Cleanup VBO here
	for (int i = 0; i < NUM_GEOMETRY; ++i)
	{
		if (meshList[i])
		{
			delete meshList[i];
		}
	}
	glDeleteVertexArrays(1, &m_vertexArrayID);
	glDeleteProgram(m_programID);
}

void Scene1::HandleKeyPress() 
{
	if (Application::IsKeyPressed(GLFW_KEY_1))
	{
		glEnable(GL_CULL_FACE);
	}
	if (Application::IsKeyPressed(GLFW_KEY_2))
	{
		glDisable(GL_CULL_FACE);
	}
	if (Application::IsKeyPressed(GLFW_KEY_3))
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	if (Application::IsKeyPressed(GLFW_KEY_4))
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
}
