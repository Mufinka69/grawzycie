#include "menu.h"

Menu::Menu(Button *buttons){
    this->buttons = buttons;
    //albo z memcpy?
}

Menu::~Menu(){
    free(buttons);
}

void Menu::menu_draw(){
    int n = sizeof(buttons)/sizeof(buttons[0]);
    for(int i = 0; i < n; i++){
        buttons[i].draw();
    }
}

int Menu::menu_click(){
    int n = sizeof(buttons)/sizeof(buttons[0]);
    for(int i = 0; i < n; i++){
        if (buttons[i].click()){
            return i;
        }
    }
    return -1;
}
