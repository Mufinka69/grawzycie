#include "main.h"

int main () {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "dd!");
    SetTargetFPS(20);

    Game game;
    Button button = Button(10,10,100,100);
    game.rand_space(2, 6);

    while (!WindowShouldClose()){

        // game.game_of_life();
        // game.larger_than_life(5, 34, 45, 33, 57); // rand = 2;
        game.larger_than_life(6, 52, 60, 57, 89); ///dla 2
        // game.day_and_night();  // rand = 2 działa
        // game.larger_than_life(1, 3, 3, 4, 10); ///dla 2      // coral     

        BeginDrawing();
            button.click();
            DrawTexture(game.get_texture(), 0, 0, WHITE);
            DrawTexturePro(
                game.get_texture(), Rectangle{0, 0, GAME_WIDTH, GAME_HEIGHT},
                Rectangle{0, 0, WINDOW_WIDTH, WINDOW_HEIGHT}, Vector2{0, 0}, 0.0f, WHITE);
            button.draw();
            ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();
}