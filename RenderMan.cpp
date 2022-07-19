#include "RenderMan.hpp"

// Class Constructor
// Take in the Static View and Projection Matrix
RenderMan::RenderMan(Mtx44 view, Mtx44 projection, Mtx44 &m)
: rview(view), rprojection(projection), mvp(m) {}

RenderMan::~RenderMan()
{
    Stack.Clear();
}

// Get An Identity Matrix
Mtx44 RenderMan::GetIdentity()
{
    Mtx44 matrix;
    matrix.SetToIdentity();
    return matrix;
}

// Auto Scale
Mtx44 RenderMan::Scale(float x,float y, float z)
{
    Mtx44 Scaler;
    Scaler.SetToIdentity();
    Scaler.SetToScale(x,y,z);
    return Scaler;
}

// Auto Rotate
Mtx44 RenderMan::Rotate(float degrees, float x, float y, float z)
{
    Mtx44 Rotater;
    Rotater.SetToIdentity();
    Rotater.SetToRotation(degrees, x, y, z);
    return Rotater;
}

// Auto Translate
Mtx44 RenderMan::Translate(float x, float y, float z)
{
    Mtx44 Translater;
    Translater.SetToIdentity();
    Translater.SetToTranslation(x,y,z);
    return Translater;
}

// Retrieve the Top Matrix in the Stack
Mtx44 RenderMan::Top()
{
    return Stack.Top();
}

// Auto Calculate MVP using Auto Functions Above
void RenderMan::MVP(Mtx44 model)
{
    mvp = rprojection * rview * model;
}

// Load Matrix into Stack with Inheritance
void RenderMan::PushM(Mtx44 model)
{
    Stack.PushMatrix();
    Stack.MultMatrix(model);
}

// Load Matrix into Stack without Inheritance
void RenderMan::PushN(Mtx44 model)
{
    Stack.PushMatrix();
    Stack.LoadMatrix(model);
}

// Pop Matrix (Remove the top Matrix)
void RenderMan::Pop()
{
    Stack.PopMatrix();
}

// Auto Calculate the MVP with Consideration of the Top Matrix in Stack
void RenderMan::SMVP(Mtx44 model)
{
    Stack.PushMatrix();
    Stack.MultMatrix(model);
    mvp = rprojection * rview * Stack.Top();
    Stack.PopMatrix();
}
