#pragma once

#include "platform/platform.h"
#include <windows.h>

namespace Pinut
{
    class WinPlatform : public Platform
    {
    private:
        HINSTANCE h_instance;
        HWND hwnd;
        // vksurface
        
    public:
        virtual bool startup (
            const char* name,
            i32 x,
            i32 y,
            i32 width,
            i32 height ) override;
        
        virtual void shutdown() override {};
        virtual bool pumpMessages() override { return true; };
    };
}