#pragma once

#include "..\defines.h"
#include <string>
#include <memory>

class StackAllocator;

namespace Pinut
{

    /**
     * Contains the systems of the application in a 
     * state structure.
     */
    struct ApplicationState
    {
        u64     event_system_memory_requirement;
        void*   event_system;

        u64     memory_system_memory_requirement;
        void*   memory_system;

        u64     logging_system_memory_requirement;
        void*   logging_system;

        u64     input_system_memory_requirement;
        void*   input_system;

        u64     platform_system_memory_requirement;
        void*   platform_system;

        u64     render_system_memory_requirement;
        void*   render_system;
    };

    class PNT Application
    {
    public:
        ApplicationState* m_state{};
    private:
        std::string                     m_Name{};
        bool                            m_isRunning{false};
        i16                             m_width;
        i16                             m_height;
        std::shared_ptr<StackAllocator> m_systemsAllocator;
    public:
        Application();
        ~Application(){}

        bool init();
        bool run();
    };

    Application* CreateApplication();
}