debug:
	g++ src/*.cpp -std=c++14 -g -Wall -m64 -I include -o bin/debug/main -lSDL2main -lSDL2 -lSDL2_image
	bin/debug/main

release:
	g++ src/*.cpp -std=c++14 -O3 -Wall -m64 -I include -o bin/release/main -s -lSDL2main -lSDL2 -lSDL2_image
	bin/release/main
