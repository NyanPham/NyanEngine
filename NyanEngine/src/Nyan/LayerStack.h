#pragma once

#include "Nyan/Core.h"
#include "Layer.h"

#include <vector>

namespace Nyan
{
    class NYAN_API LayerStack
    {
    public:
        LayerStack();
        ~LayerStack();

        virtual void PushLayer(Layer *layer);
        virtual void PushOverlay(Layer *layer);
        virtual void PopLayer(Layer *layer);
        virtual void PopOverlay(Layer *layer);

        std::vector<Layer *>::iterator begin() { return m_Layers.begin(); }
        std::vector<Layer *>::iterator end() { return m_Layers.end(); }

    private:
        std::vector<Layer *> m_Layers;
        std::vector<Layer *>::iterator m_LayerInsert;
    };
}