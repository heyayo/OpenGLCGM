#include "RenderMan.hpp"

// Class Constructor
// Take in the Static View and Projection Matrix
RenderMan::RenderMan(Mtx44 view, Mtx44 projection, Mtx44 &m)
: rview(view), rprojection(projection), mvp(m) {}

RenderMan::~RenderMan(){}

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

// Auto Calculate MVP using Auto Functions Above
void RenderMan::MVP(Mtx44 model)
{
    mvp = rprojection * rview * model;
}
