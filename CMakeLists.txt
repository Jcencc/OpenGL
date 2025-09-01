cmake_minimum_required(VERSION 3.10)
project("OpenGL_3_3_Project")


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(/utf-8)

include("C:\\github\\vcpkg\\scripts\\buildsystems\\vcpkg.cmake")

file(GLOB SRC
        "src/*.cpp"
        "src/*.h"
)

add_executable(${PROJECT_NAME} ${SRC})


find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL glfw opengl32.lib glu32.lib)
