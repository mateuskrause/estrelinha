# CC and flags
CC = g++
CXXFLAGS = -std=c++11 -g -Wall
#CXXFLAGS = -std=c++11 -O3 -Wall

# folders
INCLUDE_FOLDER = ./include/
BIN_FOLDER = ./bin/
OBJ_FOLDER = ./obj/
SRC_FOLDER = ./src/

# all sources, objs, and header files
MAIN = main
TARGET = run.out
SRC = $(wildcard $(SRC_FOLDER)*.cpp)
OBJ = $(patsubst $(SRC_FOLDER)%.cpp, $(OBJ_FOLDER)%.o, $(SRC))

# compiling everything with memlog
$(OBJ_FOLDER)%.o: $(SRC_FOLDER)%.cpp
	gcc -pg -Wall -c -Iinclude -o ./obj/memlog.o ./src/memlog.c
	$(CC) $(CXXFLAGS) -c $< -o $@ -I$(INCLUDE_FOLDER)

all: $(OBJ)
	$(CC) $(CXXFLAGS) -o $(BIN_FOLDER)$(TARGET) ./obj/memlog.o $(OBJ) 

clean:
	@rm -rf $(OBJ_FOLDER)* $(BIN_FOLDER)*

run:
	@$(BIN_FOLDER)$(TARGET)
	@./generate.sh
