#include "pinut.h"

class Sandbox : public Pinut::Application
{
public:
    Sandbox()
    {

    }
};

Pinut::Application* CreateApplication()
{
    return new Sandbox();
}