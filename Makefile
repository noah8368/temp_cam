CC = g++
FLAGS = -g
OBJECTS = build/test.o
TARGET = build/temp_cam.exe

all : build $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(FLAGS)
build/%.o: src/%.cc
	$(CC) -c -o $@ $< $(FLAGS)

build :
	mkdir $@

.PHONY: clean
clean:
	Remove-Item .\build -Recurse