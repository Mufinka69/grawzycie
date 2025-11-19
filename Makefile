RAYLIB_PATH = C:/raylib/w64devkit
INCLUDE_PATH = $(RAYLIB_PATH)/w64devkit/include
LIB_PATH = $(RAYLIB_PATH)/w64devkit/lib
LIB_PATH2 = 


CC =$(RAYLIB_PATH)/w64devkit/bin/g++.exe
CC = C:/raylib/w64devkit/bin/g++.exe
CFLAGS = -I$(INCLUDE_PATH) -Wall -std=c++14
LDFLAGS = -L. -L$(LIB_PATH) -lraylib -lopengl32 -lgdi32 -lwinmm


SRC = main2.cpp game_of_life.cpp button.cpp game.cpp menu.cpp
OUT = main.exe

all:
	$(CC) $(SRC) -o $(OUT) $(CFLAGS) $(LDFLAGS)

clean:
	del $(OUT)