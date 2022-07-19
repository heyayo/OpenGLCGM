#include "Scene1.h"
#include "Mtx44.h"
#include "MatrixStack.h"
#define SR(x) glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);meshList[x]->Render();

class RenderMan
{
    Mtx44 rview;
    Mtx44 rprojection;
    Mtx44 &mvp;
    MS Stack;

    public:
    RenderMan(Mtx44 view, Mtx44 projection, Mtx44 &m);
    ~RenderMan();
    static Mtx44 GetIdentity();
    Mtx44 Scale(float x = 1.f,float y = 1.f, float z = 1.f);
    Mtx44 Rotate(float degrees, float x = 0, float y = 0, float z = 0);
    Mtx44 Translate(float x = 0, float y = 0, float z = 0);
    Mtx44 Top();
    void MVP(Mtx44 model);
    void SMVP(Mtx44 model);
    void PushM(Mtx44 model);
    void PushN(Mtx44 model);
    void Pop();
};
