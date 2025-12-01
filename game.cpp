#include "main.h"
#include "game.h"

Game::Game(){
    game_state = MAIN_MENU;
    game_of_life.rand_space(2, 6);
    is_running = true;
}

void Game::draw(){
    BeginDrawing();    
        ClearBackground(BLACK);
        //================
        if(game_state == GAME_PLAY){
            game_of_life.draw();
        }


        switch (game_state)
        {
        case MAIN_MENU: {
                float w = (float)GetScreenWidth() * 0.7;
                float h = (float)GetScreenHeight() * 0.1;
                float x = (float)GetScreenWidth()/2 - w/2;
                if(GuiButton((Rectangle){x, 100, w, h}, "Start")){
                    game_state = OPTIONS_MENU;
                }
                if(GuiButton((Rectangle){x, 300, w, h}, "Quit")){
                    is_running = false;
                }
            }
            break;
        
        case OPTIONS_MENU: {
            // float w = GetScreenWidth()*0.2;
            float h = GetScreenHeight()*0.2;


            float x = GetScreenWidth()*0.1;
            float y = GetScreenHeight()*0.1;

            float bw = GetScreenWidth()*0.8*0.25;
            float bh = GetScreenHeight()*0.8 * 0.25;
            float space_w = ((GetScreenWidth()*0.8) - (bw*3))/3;
            // w = space_w;

            auto DrawButton = [&](float x, float y, const char* text, LifeRules r){
                if(rules == r){
                    GuiSetStyle(BUTTON, TEXT_COLOR_NORMAL, ColorToInt(GREEN));
                    GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(DARKGREEN));
                    GuiSetStyle(BUTTON, BORDER_COLOR_NORMAL, ColorToInt(LIME));
                }else{
                    GuiSetStyle(BUTTON, TEXT_COLOR_NORMAL, ColorToInt(DARKGRAY));
                    GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(LIGHTGRAY));
                    GuiSetStyle(BUTTON, BORDER_COLOR_NORMAL, ColorToInt(GRAY));
                }
                if (GuiButton({x, y, bw, h}, text)){
                    rules = r;
                }
            };

            DrawButton(x + space_w, y, "Classic", CLASSIC);
            DrawButton(x + bw + space_w*2, y, "Hight Life", HIGH_LIFE);
            DrawButton(x + 2*bw + space_w*3, y, "Day & Night", DAY_NIGHT);
            DrawButton(x + space_w, y + bh + 20, "Coral", CORAL);
            DrawButton(x + bw + space_w*2, y + bh + 20, "Robaczki", ROBACZKI);
            DrawButton(x + 2*bw + space_w*3, y + bh + 20, "Custom", CUSTOM);

            GuiSetStyle(BUTTON, TEXT_COLOR_NORMAL, ColorToInt(DARKGRAY));
            GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(LIGHTGRAY));
            GuiSetStyle(BUTTON, BORDER_COLOR_NORMAL, ColorToInt(GRAY));

            if(GuiButton((Rectangle){x + space_w, y + bh * 2 + 40, bw, h}, "Start")){
                game_of_life.rand_space(2, 6);
                game_state = GAME_PLAY;
            }
            if(GuiButton((Rectangle){x + bw + space_w*2, y + bh * 2 + 40, bw, h}, "Main menu")){
                game_state = MAIN_MENU;
            }

        }
            break;
        case GAME_PLAY:
            if(IsKeyPressed(KEY_ESCAPE)){
                game_state = GAME_PAUSE;
            }
            break;
        case GAME_PAUSE: {
            game_of_life.draw();
            if(IsKeyPressed(KEY_ESCAPE)){
                game_state = GAME_PLAY;
            }
            int w = GetScreenWidth()* 0.5;
            if(GuiButton((Rectangle){GetScreenWidth()/2.0 - w/2.0, GetScreenHeight()/3.0, w, 100.0}, "Back to menu")){
                game_state = MAIN_MENU;
            }
        }
            break;
        default:
            break;
        }
        //================
    EndDrawing();
}


void Game::update(){
    if(game_state == GAME_PLAY){
        if(rules == CLASSIC){
            game_of_life.game_of_life();
        }
        if(rules == HIGH_LIFE){
            game_of_life.larger_than_life(6, 52, 60, 57, 89);
        }
        if(rules == CORAL){
            game_of_life.larger_than_life(1, 3, 3, 4, 10);
        }
        if(rules == DAY_NIGHT){
            game_of_life.day_and_night();
        }
        if(rules == ROBACZKI){
            game_of_life.larger_than_life(5, 34, 45, 33, 57);
        }
    }
}

void Game::run(){
    draw();
    update();
}


