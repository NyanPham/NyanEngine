#pragma once

extern Nyan::Application *Nyan::CreateApplication();

#ifdef NYAN_PLATFORM_WINDOWS
int main(int argc, char **argv)
{
    Nyan::Log::Init();
    NYAN_CORE_WARN("Initialized Log!");
    int a = 5;
    NYAN_INFO("Hello! Var={0}", a);

    auto app = Nyan::CreateApplication();
    app->Run();
    delete app;

    return 0;
}
#else
#error NyanEngine only supports Windows!
#endif