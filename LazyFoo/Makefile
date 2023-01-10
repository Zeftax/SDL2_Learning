# OBJS specifies which files to compile as part of the project
# Here we want to compile all the files in the src/ directory
OBJS = src/*.cpp

# CC specifies which compiler we're using
CC = g++

# CFLAGS specifies the additional compilation options we're using
# -std cpecifies the c++ standart we are targeting
# -Wall, -Wextra and -Wpedantic will show some extra warnings
# -Werror will treat all warnings as errors
CFLAGS = -std=c++14 -Wall -Wextra -Wpedantic

# LFLAGS specifies the libraries we're linking against
LFLAGS = -lSDL2main -lSDL2 -lSDL2_image

# OBJ_NAME specifies the name of our exectuable
OBJ_NAME = out

debug:
	g++ $(OBJS) $(CFLAGS) -g -o bin/debug/$(OBJ_NAME)
	bin/debug/$(OBJ_NAME)

release:
	g++ $(OBJS) $(CFLAGS) -O3 -o bin/release/$(OBJ_NAME)
	bin/release/$(OBJ_NAME)
