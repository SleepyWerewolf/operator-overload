#   Makefile for intarray lab.
#   cs320 Fall 2009
#   Patty Kraft

ALL = iadrv intarray.o 

CC = g++
CCFLAGS = -g -O2 -Wall -Wpointer-arith -Wcast-qual -Wwrite-strings

iadrv:		iadrv.cpp iadrv.h IntArray.o 
	${CC} -o iadrv iadrv.cpp IntArray.o 
    
IntArray.o:	IntArray.cpp IntArray.h
	${CC} ${CCFLAGS} -c IntArray.cpp  

clean:
	'rm' -f ${ALL}
