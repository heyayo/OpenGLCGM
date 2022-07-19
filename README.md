# DX1111-OpenGLFramework
This is the OpenGL Framework provided by the lecturer ported to Linux

Usage should be the same as in class

## IMPORTANT NOTES
Bundled with this Version is the RenderMan Class which helps with managing Matrix Stacks and Object Transforms

This version also uses GLFW Keycodes instead of Windows Virtual Keycodes for obvious reasons.

GLFW Key Codes follow the format
```
GLFW_KEY_

EXAMPLE: A Key
GLFW_KEY_A
```

## Compile Instructions
If on Linux, compile using CMake and the provided CMakeLists.txt

If on Windows, either continue with CMake or import the files onto Visual Studio

### Common Errors
```
Impossible to open
Shader//TransformVertexShader.vertexshader
Shader//SimpleFragmentShader.fragmentshader

This Error means that the executable file is not in the same folder as the Shaders folder from the github repo
```
