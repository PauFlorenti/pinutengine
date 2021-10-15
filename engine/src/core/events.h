#pragma once

namespace Pinut
{
    class EventManager
    {
    public:
        init();
        shutdown();

        bool eventRegister(u16 code, void* listener);
        bool eventUnregister(u16 code, void* listener);
        bool eventFire(u16 code, void* sender );
    }
}