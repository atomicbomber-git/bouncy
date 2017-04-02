CC = g++
CPPFLAGS = -I$(INCLUDE_DIR)
INCLUDE_DIR = ./headers
LIBS = -lsfml-system -lsfml-window -lsfml-graphics
OBJECTS = main.o Game.o Ball.o
PROGRAM_NAME = bounce

$(PROGRAM_NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(PROGRAM_NAME) $(LIBS)

clean:
	rm $(OBJECTS) $(PROGRAM_NAME)

rebuild:
	make clean || make $(PROGRAM_NAME)