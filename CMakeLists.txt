cmake_minimum_required(VERSION 3.0.0)
project(OpenGLFramework VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXE_LINKER_FLAGS "-lGL -lGLU -lX11 -lXxf86vm -lXrandr -lpthread -lXi")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

file(GLOB COMMON Common/*.cpp)
file(GLOB STATICLIB ${CMAKE_SOURCE_DIR}/lib/*.a)
set(SOURCE Application.cpp Camera.cpp Mesh.cpp MeshBuilder.cpp Scene1.cpp shader.cpp)

add_library(CommonLib ${COMMON})
add_executable(RunFile main.cpp ${SOURCE})

target_include_directories(CommonLib PUBLIC ${CMAKE_SOURCE_DIR}/Common)
target_include_directories(RunFile PUBLIC ${CMAKE_SOURCE_DIR}/Common)
target_include_directories(RunFile PUBLIC ${CMAKE_SOURCE_DIR})
target_link_libraries(RunFile PUBLIC CommonLib)
target_link_libraries(CommonLib PUBLIC ${STATICLIB})
target_link_libraries(RunFile PUBLIC ${STATICLIB})
