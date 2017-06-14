Fire_Emblem: src/main.cpp src/graphics.cpp src/game.cpp src/input.cpp src/sprite.cpp src/animated_sprite.cpp src/player.cpp src/level.cpp src/tile.cpp
	g++ -std=c++11 -g -o fire_emblem src/main.cpp src/graphics.cpp src/game.cpp src/input.cpp src/sprite.cpp src/animated_sprite.cpp src/player.cpp src/level.cpp src/tile.cpp -lSDL2  -lSDL2_image -I header

