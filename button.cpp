#include "button.h"

Button::Button(){}

Button::Button(int x, int y, int w, int h){
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

bool Button::click(){
    Vector2 mouse_pos = GetMousePosition();
    if(x < mouse_pos.x && x + w > x && y < mouse_pos.y && y + h > y){
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            // std::cout<<"xdd\n";
            return true;
        }
    }
    return false;
}

void Button::draw(){
    DrawRectangle(x, y, w, h, RED);
}





