#pragma once
#include "main.h"

class Button{
private:
    int x;
    int y;
    int w;
    int h;
public:
    Button();
    Button(int x, int y, int w, int h);
    bool click();
    void draw();
};