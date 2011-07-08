#Makefile for libmaw
#Chris Marsh 2011

#MATLAB setup
TMW_ROOT=/usr/local/Matlab2011a
Arch=glnxa64

CC=icpc 
CFLAGS=-O3 -openmp 

#brittle, fix
LDFLAGS=-L$(TMW_ROOT)/bin/$(Arch) -leng -lmx -L/usr/lib/liblapack -Wl,-rpath-link,$(TMW_ROOT)/bin/$(Arch)
INCLUDES=-I$(TMW_ROOT)/extern/include -I../armadillo-2.0.1/include

all: libmaw


libmaw: matlab_engine.o graphics.o
	ar rc libmaw.a matlab_engine.o graphics.o

matlab_engine.o: matlab_engine.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c matlab_engine.cpp
	
graphics.o: graphics.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c graphics.cpp
	
clean:
	rm -rf *o libmaw.a