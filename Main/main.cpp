#include "mainWindow.h"



int main()
{
    mainWindow app;
    if(app.init())
    {
        while (app.isRun())
        {
           app.broadcast();
        }
        
        

    }

    return 0;
}

