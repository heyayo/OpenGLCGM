# DX1111-OpenGLFramework
This is the OpenGL Framework provided by the lecturer ported to Linux, using CMAKE to compile for both Windows and Linux.
Usage should be the same as in class
## Compile Instructions
This project is to be compiled using CMAKE instead of Visual Studio as Linux does not support Visual Studio
To Compile, install CMAKE and create a build folder somewhere, preferably in the git repo directory.
In CMD or Terminal, Go to the directory of the git repo folder and do
```
cmake [path/to/build/folder]
```
cmake will proceed to create build settings using whichever compiler your computer has.
When that is done, do
```
cmake --build [path/to/build/folder]
```
cmake will proceed to compile your program

If on Linux, after creating the build directory and running cmake [path/to/build/folder] in it, you can run the buildrun.sh script to automatically compile and run the program.

### Common Errors
```
Impossible to open
Shader//TransformVertexShader.vertexshader
Shader//SimpleFragmentShader.fragmentshader

This Error means that the executable file is not in the same folder as the Shaders folder from the github repo
```

```
Running on Linux and My Changes aren't reflected in the new build

If you are using the buildrun.sh script to compile and run, chances are the compile failed and you are running the last successful build
``
