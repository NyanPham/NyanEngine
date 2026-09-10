#include "nyanpch.h"
#include "Layer.h"

namespace Nyan
{
    Layer::Layer(const std::string &name)
    {
        m_DebugName = name;
    }

    Layer::~Layer()
    {
    }
}