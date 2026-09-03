#pragma once

#include "Core.h"

namespace Nyan
{
    class NYAN_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };
    // To be defined in CLIENT
    Application *CreateApplication();
}