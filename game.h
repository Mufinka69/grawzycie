#pragma once

#include "button.h"
#include "game_of_life.h"
#include "menu.h"

class Game{
    Game_of_life game_of_life;
    Game_state game_state;
    LifeRules rules;
    int scrollIndex;

public:
    Game();
    void draw();
    void update();
    void run();
};