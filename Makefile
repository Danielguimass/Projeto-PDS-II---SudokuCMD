CC = g++
CFLAGS = -std=c++11 -Wall -g
TARGET = programa

BUILD = ./build
SRC = ./src
INCLUDE = ./include

${TARGET}: ${BUILD}/historias.o ${BUILD}/sudoku.o ${BUILD}/main.o
	${CC} ${CFLAGS} ${BUILD}/historias.o ${BUILD}/sudoku.o ${BUILD}/main.o -o ${TARGET}

${BUILD}/historias.o: ${INCLUDE}/historias.hpp ${SRC}/historias.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/historias.cpp -o ${BUILD}/historias.o

${BUILD}/sudoku.o: ${INCLUDE}/sudoku.hpp ${SRC}/sudoku.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c ${SRC}/sudoku.cpp -o ${BUILD}/sudoku.o

${BUILD}/main.o: ${INCLUDE}/historias.hpp ${INCLUDE}/sudoku.hpp  main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE}/ -c main.cpp -o ${BUILD}/main.o