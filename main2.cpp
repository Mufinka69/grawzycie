#define RAYGUI_IMPLEMENTATION

#include "main.h"
#include "game.h"


int main () {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "dd!");
    SetTargetFPS(20);
    SetExitKey(KEY_NULL);
    Game game;
    while (!WindowShouldClose()){
        game.run();
    }

    CloseWindow();
}