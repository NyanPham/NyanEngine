#pragma once

#ifdef NYAN_PLATFORM_WINDOWS
#ifdef NYAN_BUILD_DLL
#define NYAN_API __declspec(dllexport)
#else
#define NYAN_API __declspec(dllimport)
#endif
#else
#error NyanEngine only supports Windows!
#endif

#ifdef NYAN_ENABLE_ASSERTS
#define NYAN_ASSERT(x, ...)                                   \
    {                                                         \
        if (!x)                                               \
        {                                                     \
            NYAN_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
            __debugbreak();                                   \
        }                                                     \
    }
#define NYAN_CORE_ASSERT(x, ...)                                   \
    {                                                              \
        if (!x)                                                    \
        {                                                          \
            NYAN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
            __debugbreak();                                        \
        }                                                          \
    }
#else
#define NYAN_ASSERT(x, ...)
#define NYAN_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)