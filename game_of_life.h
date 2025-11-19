#pragma once

#include "main.h"

class Game_of_life{
private:
    Image image;
    Color *pixels_copy;
    Texture2D texture;
    
    bool *alive;
    bool *alive_copy;

public:
    Game_of_life();
    void draw();
    Texture2D get_texture();
    void rand_space(int x, int r);
    void copy_space();
    void game_of_life();
    void day_and_night();
    void larger_than_life(int zasieg, int d_min_somsiadow, int d_max_somsiadow, int a_min_somsiadow, int a_max_somsiadow);
};