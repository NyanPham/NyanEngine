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