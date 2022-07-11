#include "RenderMan.hpp"

Mtx44 QuickScale(float x,float y, float z)
{
    Mtx44 Scaler;
    Scaler.SetToIdentity();
    Scaler.SetToScale(x,y,z);
    return Scaler;
}

Mtx44 QuickRotate(float degrees, float x, float y, float z)
{
    Mtx44 Rotater;
    Rotater.SetToIdentity();
    Rotater.SetToRotation(degrees, x, y, z);
    return Rotater;
}

Mtx44 QuickTranslate(float x, float y, float z)
{
    Mtx44 Translater;
    Translater.SetToIdentity();
    Translater.SetToTranslation(x,y,z);
    return Translater;
}
