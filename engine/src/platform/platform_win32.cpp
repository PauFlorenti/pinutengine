#include "platform_win32.h"

namespace Pinut
{

    LRESULT CALLBACK win32_process_message(HWND hwnd, u32 msg, WPARAM w_param, LPARAM l_param);

    bool WinPlatform::startup(
        const char* name,
        i32 x,
        i32 y,
        i32 width,
        i32 height
    )
    {
        h_instance = GetModuleHandleA(0);

        // Setup and register window class.
        HICON icon = 0;
        WNDCLASSA wc;
        memset(&wc, 0, sizeof(wc));
        wc.style = CS_DBLCLKS;
        wc.lpfnWndProc = win32_process_message;
        wc.cbClsExtra = 0;
        wc.cbWndExtra = 0;
        wc.hInstance = h_instance;
        wc.hIcon = icon;
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hbrBackground = NULL;
        wc.lpszClassName = "pinut_window_class";

        if(!RegisterClassA(&wc)){
            MessageBoxA(0, "Window registration failed", "Error", MB_ICONEXCLAMATION | MB_OK);
            return false;
        }

        u32 client_x = x;
        u32 client_y = y;
        u32 client_width = width;
        u32 client_height = height;

        u32 window_x = client_x;
        u32 window_y = client_y;
        u32 window_width = client_width;
        u32 window_height = client_height;

        u32 windowStyle = WS_OVERLAPPED | WS_SYSMENU | WS_CAPTION;
        u32 windowExStyle = WS_EX_APPWINDOW;

        windowStyle |= WS_MAXIMIZEBOX;
        windowStyle |= WS_MINIMIZEBOX;
        windowStyle |= WS_THICKFRAME;

        RECT borderRect = {0,0,0,0};
        AdjustWindowRectEx(&borderRect, windowStyle, 0, windowExStyle);

        window_x += borderRect.left;
        window_y += borderRect.top; 
        window_width += borderRect.right - borderRect.left;
        window_height += borderRect.bottom - borderRect.top;

        HWND handle = CreateWindowExA(
            windowExStyle, "pinut_window_class", name, windowStyle,
            window_x, window_y, window_width, window_height,
            0, 0, h_instance, 0);

        if(!handle){
            MessageBoxA(NULL, "Window creation failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
            return false;
        } else {
            hwnd = handle;
        }

        ShowWindow(hwnd, SW_SHOW);

        return true;
    }

    LRESULT CALLBACK win32_process_message(HWND hwnd, u32 msg, WPARAM w_param, LPARAM l_param)
    {
        switch (msg)
        {
        case WM_CLOSE:
            // TODO: Event message to close application
            break;
        
        default:
            break;
        }
        return DefWindowProcA(hwnd, msg, w_param, l_param);
    }
}