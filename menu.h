#pragma once

#include "main.h"

class Menu{
private:
    Button *buttons;
    bool is_visable;
public:
    Menu(Button *buttons);
    ~Menu();
    void menu_draw();
    int menu_click();
};