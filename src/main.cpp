#include "app.h"
#include <iostream>
#include <stdexcept>

int main(int argc, char **argv) {
    try {
        App app;
        app.run();
    } catch(const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
}