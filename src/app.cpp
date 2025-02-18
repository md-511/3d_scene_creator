#include "app.h"
#include "settings.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

App::App() {
    
}

App::~App() {
    glfwTerminate();
}

void App::run() {
    while (!glfwWindowShouldClose(engine.window))
    {
        // Clear Screen
        glClear(GL_COLOR_BUFFER_BIT);
        
        // Draw Here
        engine.draw();

        // TODO: fps capping
        engine.update();

        // Swap Buffers
        glfwSwapBuffers(engine.window);

        // Poll Events
        glfwPollEvents();
    }
}