CC = g++
CFLAGS = -g -Wall -Wextra
TARGET = stacker

default: $(TARGET)

$(TARGET): stacker.o main.o
	$(CC) $(CFLAGS) -o $(TARGET) stacker.o main.o

stacker.o: stacker.cpp stacker.h
	$(CC) $(CFLAGS) -c stacker.cpp

main.o: main.cpp stacker.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) $(TARGET) *.o *~
