#include <Nyan.h>

class Sandbox : public Nyan::Application
{
public:
    Sandbox()
    {
    }
    ~Sandbox()
    {
    }
};

Nyan::Application *Nyan::CreateApplication()
{
    return new Sandbox();
}