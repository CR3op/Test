#pragma once
#include <Windows.h>


class Window
{
    public: 
        Window();
        //start the window
        bool init();
        bool broadcast(); //shows the window to display
        //release the window, also might close the window.
        bool release();
        bool isRun();
        
        //Event method
        virtual void onCreate()=0;
        virtual void onUpdate()=0;
        virtual void onDestroy()=0;

        ~Window();
    protected:
        HWND m_hwnd;
        bool m_is_run;

};