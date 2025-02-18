#ifndef ENGINE_H
#define ENGINE_H

// The acutual Renderer

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Engine
{
private:
    GLFWwindow *window;
public:
    Engine();
    ~Engine();
    void draw();
    void update();

    friend class App;
};

#endif