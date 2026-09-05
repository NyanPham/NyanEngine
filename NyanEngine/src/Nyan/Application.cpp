#include "Application.h"

#include "Nyan/Events/ApplicationEvent.h"
#include "Nyan/Log.h"

namespace Nyan
{
    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        WindowResizeEvent e(1280, 720);
        if (e.IsInCategory(EventCategoryApplication))
        {
            NYAN_TRACE(e);
        }
        if (e.IsInCategory(EventCategoryInput))
        {
            NYAN_TRACE(e);
        }

        while (true)
            ;
    }
}