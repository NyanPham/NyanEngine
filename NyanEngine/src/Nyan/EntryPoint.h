#pragma once

extern Nyan::Application *Nyan::CreateApplication();

#ifdef NYAN_PLATFORM_WINDOWS
int main(int argc, char **argv)
{
    printf("Nyan Engine starts\n");
    auto app = Nyan::CreateApplication();
    app->Run();
    delete app;

    return 0;
}
#else
#error NyanEngine only supports Windows!
#endif