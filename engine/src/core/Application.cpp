#include "Application.h"

#include <iostream>
#include "memory/stackAllocator.h"
#include "maths.h"
#include "platform/platform_win32.h"

namespace Pinut
{
    Application::Application()
    {
        std::cout << "App constructor called!" << std::endl;
        m_Name = "Sandbox application.";
    }

    /**
     * Initialize all systems required in the application.
     */
    bool Application::init()
    {

        // Init allocator.
        std::cout << "Initializing the systems Allocator ...\n";
        m_systemsAllocator = std::make_shared<StackAllocator>();
        // Reserve blocks of 64 mb.
        u64 systemsAllocatorTotalSize = 64 * 1024 * 1024; // 64 MBs
        m_systemsAllocator->init( systemsAllocatorTotalSize, 1 );
        std::cout << "Systems allocator init with " << systemsAllocatorTotalSize / (1024 * 1024) << "Mbs.\n";

        // Init Subsystems
        // ---------------

        // Init event system

        // Memory System

        // Input System

        // Platform System

        std::cout << "Allocating memory for platform system ..." << std::endl;
        //m_state->platform_system_memory_requirement = sizeof(WinPlatform);
        std::cout << "Platform system requires " << sizeof(WinPlatform) << " Bytes of memory." << std::endl;
        m_state->platform_system = m_systemsAllocator->allocate(sizeof(WinPlatform));
        std::cout << "Initializing platform system ...\n";
        m_state->platform_system = new WinPlatform();
        if(!static_cast<WinPlatform*>(m_state->platform_system)->startup("Pinut Window", 100, 100, 500, 500)){
            std::cout << "Platform system failed to initialize!\n";
            return false;
        }
        std::cout << "Platform system initialized ...\n";

        // Render System

        return true;
    }

    /**
     * Run the application in a loop until it is required to stop.
     */
    bool Application::run()
    {
        m_isRunning = true;
        std::cout << "App running ..." << std::endl;

        while(m_isRunning)
        {
            if(!static_cast<WinPlatform*>(m_state->platform_system)->pumpMessages())
                m_isRunning = false;
        }
        return true;
    }
}