#pragma once

#include "defines.h"

namespace Pinut
{
    class Platform
    {
    public:

        virtual bool startup(
            const char* name,
            i32 x,
            i32 y,
            i32 width,
            i32 height
        ) = 0;
        
        virtual void shutdown() = 0;

        virtual bool pumpMessages() = 0;
    };
}