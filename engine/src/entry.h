#pragma once

#include "core/Application.h"
#include <iostream>

extern Pinut::Application* CreateApplication();

int main()
{
    auto app = CreateApplication();

    if(!app->init()){
        std::cout << "Application could not initialize!" << std::endl;
        return -1;
    }

    if(!app->run()){
        std::cout << "Application could not run!" << std::endl;
        return -2;
    }

    delete app;

    return 0;
}