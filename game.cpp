#include "main.h"
#include "game.h"

Game::Game(){
    game_state = MAIN_MENU;
    game_of_life.rand_space(2, 6);
    scrollIndex = 0;
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
                    //todo
                }
            }
            break;
        
        case OPTIONS_MENU: {
            float w = 50;
            float h = 50;
            float gap = 20;  
            float startX = GetScreenWidth() * 0.05f; 
            float startY = 100;

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
                if (GuiButton({x, y, w, h}, text)){
                    rules = r;
                }
            };

            DrawButton(100, 100, "xdd", CLASSIC);
            DrawButton(250, 100, "1231", CORAL);

            if(GuiButton((Rectangle){300, 300, 40, 40}, "Start")){
                game_state = GAME_PLAY;
            }

             
        }
            break;
        case GAME_PLAY:
            if(IsKeyPressed(KEY_ESCAPE)){
                game_state = GAME_PAUSE;
            }
            break;
        case GAME_PAUSE:
            if(IsKeyPressed(KEY_ESCAPE)){
                game_state = GAME_PLAY;
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
        if(rules == CORAL){
            game_of_life.day_and_night();
        }
    }
}

void Game::run(){
    draw();
    update();
}


