#include "game_of_life.h"


Game::Game(){
    image = GenImageColor(GAME_WIDTH, GAME_HEIGHT, WHITE);
    texture = LoadTextureFromImage(image);
    pixels_copy = (Color*)malloc(GAME_WIDTH * GAME_HEIGHT * sizeof(Color));

    alive = (bool*)malloc(GAME_WIDTH * GAME_HEIGHT * sizeof(bool));
    alive_copy = (bool*)malloc(GAME_WIDTH * GAME_HEIGHT * sizeof(bool));

    Color *pixels = (Color*)image.data;
    for(int i = 0; i < GAME_HEIGHT; i++){
        for(int j = 0; j < GAME_WIDTH; j++){
            int pos = SPACE_AT(i, j);
            pixels[pos] = WHITE;
            alive[pos] = false;
        }
    }
    UpdateTexture(texture, image.data);
}

Texture2D Game::get_texture(){
    return texture;
}

void Game::rand_space(int x, int r){
    Color *pixels = (Color*)image.data;
    for(int i = r; i < GAME_HEIGHT - r; i++){
        for(int j = r; j < GAME_WIDTH - r; j++){
            int pos = SPACE_AT(i, j);
            int color = rand()%x;
            if (color == 0){
                alive[pos] = true;
                pixels[pos] = BLACK;
            }
            else{
                alive[pos] = false;
                pixels[pos] = WHITE;
            }
        }
    }
    UpdateTexture(texture, image.data);
}

void Game::copy_space(){
    memcpy(pixels_copy, (Color*)image.data, GAME_WIDTH * GAME_HEIGHT * sizeof(Color));
}


void Game::game_of_life(){
    Color *pixels = (Color*)image.data;
    int somsiedzi = 0;
    for(int i = 1; i < GAME_HEIGHT - 1 ;i++){
        for(int j = 1; j < GAME_WIDTH - 1; j++){
            int pos = SPACE_AT(i, j);
            somsiedzi = 0;
            for(int x = -1; x <= 1; x++){
                for(int y = -1; y <= 1; y++){
                    int n_pos = SPACE_AT(i + x, j + y);
                    if(alive[n_pos]){
                        somsiedzi++;
                    }
                }
            }
            if(alive[pos]){
                somsiedzi--;
            }
            if(somsiedzi == 3 || (alive[pos] && somsiedzi == 2)){
                pixels[pos] = BLACK;
                alive_copy[pos] = true;
            }else{
                pixels[pos] = RAYWHITE;
                alive_copy[pos] = false;
            }
        }
    }
    memcpy(alive, alive_copy, GAME_WIDTH * GAME_HEIGHT * sizeof(bool));
    UpdateTexture(texture, pixels);
}

void Game::day_and_night(){
    Color *pixels = (Color*)image.data;
    int somsiedzi = 0;
    for(int i = 1; i < GAME_HEIGHT - 1 ;i++){
        for(int j = 1; j < GAME_WIDTH - 1; j++){
            int pos = SPACE_AT(i, j);
            somsiedzi = 0;
            for(int x = -1; x <= 1; x++){
                for(int y = -1; y <= 1; y++){
                    int n_pos = SPACE_AT(i + x, j + y);
                    if(alive[n_pos]){
                        somsiedzi++;
                    }
                }
            }
            if(alive[pos]){
                somsiedzi--;
            }

            if(!alive[pos] && ((somsiedzi == 3 || somsiedzi == 6 || somsiedzi == 7 || somsiedzi == 8))){
                pixels[pos] = BLACK;
                alive_copy[pos] = true;
            }else if(alive[pos] && (somsiedzi == 3 || somsiedzi == 4 || somsiedzi == 6 || somsiedzi == 7 || somsiedzi == 8)){
                pixels[pos] = BLACK;
                alive_copy[pos] = true;
            }
            else{
                pixels[pos] = RAYWHITE;
                alive_copy[pos] = false;
            }
        }
    }
    memcpy(alive, alive_copy, GAME_WIDTH * GAME_HEIGHT * sizeof(bool));
    UpdateTexture(texture, pixels);
}

// 1, 3, 3, 2, 8
void Game::larger_than_life(int zasieg, int d_min_somsiadow, int d_max_somsiadow, int a_min_somsiadow, int a_max_somsiadow){
    Color *pixels = (Color*)image.data;
    int somsiedzi = 0;
    for(int i = zasieg; i < GAME_HEIGHT - zasieg ;i++){
        for(int j = zasieg; j < GAME_WIDTH - zasieg; j++){
            int pos = SPACE_AT(i, j);
            somsiedzi = 0;
            for(int x = -zasieg; x <= zasieg; x++){
                for(int y = -zasieg; y <= zasieg; y++){
                    int n_pos = SPACE_AT(i + x, j + y);
                    // if(alive[n_pos]){
                    //     somsiedzi++;
                    // }
                    somsiedzi += alive[n_pos];
                }
            }
            if(alive[pos]){
                somsiedzi--;
            }

            if(!alive[pos] && (somsiedzi >= d_min_somsiadow && somsiedzi <= d_max_somsiadow)){
                pixels[pos] = BLACK;
                alive_copy[pos] = true;
            }else if(alive[pos] && (somsiedzi >= a_min_somsiadow && somsiedzi <= a_max_somsiadow)){
                pixels[pos] = BLACK;
                alive_copy[pos] = true;
            }
            else{
                pixels[pos] = RAYWHITE;
                alive_copy[pos] = false;
            }
        }
    }
    memcpy(alive, alive_copy, GAME_WIDTH * GAME_HEIGHT * sizeof(bool));
    UpdateTexture(texture, pixels);
}