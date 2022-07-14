#include "Scene1.h"
#include "Mtx44.h"
#define SR(x) glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);meshList[x]->Render();

class RenderMan
{
    Mtx44 rview;
    Mtx44 rprojection;
    Mtx44 &mvp;

    public:
    RenderMan(Mtx44 view, Mtx44 projection, Mtx44 &m);
    ~RenderMan();
    static Mtx44 GetIdentity();
    Mtx44 Scale(float x = 1.f,float y = 1.f, float z = 1.f);
    Mtx44 Rotate(float degrees, float x = 0, float y = 0, float z = 0);
    Mtx44 Translate(float x = 0, float y = 0, float z = 0);
    void MVP(Mtx44 model);
};

