#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Nyan
{
    class NYAN_API Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// Core log macros
#define NYAN_CORE_ERROR(...) ::Nyan::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NYAN_CORE_WARN(...) ::Nyan::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NYAN_CORE_INFO(...) ::Nyan::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NYAN_CORE_TRACE(...) ::Nyan::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NYAN_CORE_FATAL(...) ::Nyan::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Clien log macros
#define NYAN_ERROR(...) ::Nyan::Log::GetClientLogger()->error(__VA_ARGS__)
#define NYAN_WARN(...) ::Nyan::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NYAN_INFO(...) ::Nyan::Log::GetClientLogger()->info(__VA_ARGS__)
#define NYAN_TRACE(...) ::Nyan::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NYAN_FATAL(...) ::Nyan::Log::GetClientLogger()->fatal(__VA_ARGS__)