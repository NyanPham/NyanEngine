#include <Nyan.h>

class ExampleLayer : public Nyan::Layer
{
public:
    ExampleLayer()
        : Layer("Example")
    {
    }

    void OnUpdate() override
    {
        NYAN_INFO("ExampleLayer::Update");
    }

    void OnEvent(Nyan::Event &event) override
    {
        NYAN_TRACE("{0}", event);
    }
};

class Sandbox : public Nyan::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
        PushLayer(new Nyan::ImGuiLayer());
    }
    ~Sandbox()
    {
    }
};

Nyan::Application *Nyan::CreateApplication()
{
    return new Sandbox();
}