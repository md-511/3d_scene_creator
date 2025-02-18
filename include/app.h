#ifndef APP_H
#define APP_H

// Encapsulates the actual Renderer
// Must handle user inputs etc...

#include "engine.h"

class App
{
private:
    Engine engine;
public:
    App();
    ~App();
    void run();
};

#endif