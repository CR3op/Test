#pragma once

#include "../Engine/Window.h"

class mainWindow: public Window
{
    public:
    mainWindow();

    ~mainWindow();

    //inherited the virtual voids from the Window
    virtual void onCreate() override;
    virtual void onUpdate() override;
    virtual void onDestroy() override;
};