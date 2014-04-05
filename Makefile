CC = g++
LD = g++

CFLAGS = -c -g -pedantic -std=c++11 -Wall
LFLAGS = -std=c++11 -pedantic -Wall

#Actual View files: UPDATE YOUR FILES HERE
VIEW_OBJ = terminal_view.o
VIEW_HDR = terminal_view.h
VIEW_CPP = terminal_view.cpp

#Object combination variable
GAME = tile.o board.o driver.o
MVC  = model.o controller.o view.o
OBJS = $(MVC) $(VIEW_OBJ) $(GAME)

#Program variable
PROG = 2048exe

default: $(PROG)

$(PROG): $(OBJS)
	$(LD) $(LFLAGS) $(OBJS) -o $(PROG)

driver.o: driver.cpp model.h
	$(CC) $(CFLAGS) driver.cpp

tile.o: tile.cpp tile.h
	$(CC) $(CFLAGS) tile.cpp

board.o: board.cpp board.h tile.h model.h
	$(CC) $(CFLAGS) board.cpp

model.o: model.cpp model.h view.h
	$(CC) $(CFLAGS) model.cpp

controller.o: controller.cpp controller.h command.h model.h view.h $(VIEW_HDR)
	$(CC) $(CFLAGS) controller.cpp

view.o: view.cpp view.h
	$(CC) $(CFLAGS) view.cpp

$(VIEW_OBJ): $(VIEW_CPP) $(VIEW_HDR)
	$(CC) $(CFLAGS) $(VIEW_CPP)

clean:
	rm -f *.o

real_clean:
	rm -f *.o
	rm -f *exe

