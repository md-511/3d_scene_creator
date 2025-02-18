#include "engine.h"
#include "settings.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <iostream>

Engine::Engine() {
    if (!glfwInit()) {
        throw std::runtime_error("Couldn't Initialize GLFW!");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(Settings::WIDTH, Settings::HEIGHT, Settings::TITLE, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        throw std::runtime_error("Failed to Create GLFW Window!");
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::runtime_error("Failed to initialize GLAD!");
    }
}

Engine::~Engine() {

}

void Engine::draw() {
    std::cout << "Draw Called!" << std::endl;
}

void Engine::update() {
    std::cout << "Update Called!" << std::endl;
}