#include "Window.h"

Window* window = nullptr;
Window::Window()
{

}
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch(msg)
    {
        case WM_CREATE:
        {
            //event shows when the window is created 
            window->onCreate();
            break;
        }
        case WM_DESTROY:
        {   
            //event shows when the window will be destroyed
            window->onDestroy();
            ::PostQuitMessage(0);
            break;
        }
        default:
            return ::DefWindowProc(hwnd, msg, wparam, lparam);
    }
    return NULL;

}

bool Window::init()
{
    WNDCLASSEX wc;
    wc.cbClsExtra = NULL;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.hbrBackground=(HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wc.hInstance = NULL;
    wc.lpszClassName = "MyWindowClass";
    wc.lpszMenuName = "";
    wc.style = NULL;
    wc.lpfnWndProc = &WndProc;

    if (!::RegisterClassEx(&wc))//in case the registration of class will fail, the function will return false
    {
        return false;
    }
    
    if(!window)
    {
        window = this;
    }
    //set
    //create a winsdow
    m_hwnd = ::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW,"MyWindowClass", "DirectX Application",WS_OVERLAPPED,CW_USEDEFAULT,CW_USEDEFAULT,1024,768,NULL,NULL,NULL,NULL);
    if(!m_hwnd) // if window isn't found then will return false, and would avoid from any corruption to the computer.
    {
        return false;
    }
    //show the window
    ::ShowWindow(m_hwnd, SW_SHOW);
    ::UpdateWindow(m_hwnd);
    
    //the flag to true to indicate that the window is initialized and running
    m_is_run = true;

    return true;
}

bool Window::release()
{
    //Destroy the window
    if(!::DestroyWindow(m_hwnd))
    {
        return false;

    }
    return true;
}


bool Window::broadcast()
{
    MSG msg;

    while(::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)> 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    window->onUpdate();

    Sleep(0);


    return true;
}

bool Window::isRun()
{
    return m_is_run;
}
void Window::onDestroy()
{
    m_is_run = false;
}
Window::~Window()
{

}


