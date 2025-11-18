#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

class Pipeline
{
public:
    virtual ~Pipeline() = default;
    virtual void DrawVerticies() = 0;

    virtual void init(GLFWwindow* window) = 0;
    virtual void cleanup() = 0;
};

