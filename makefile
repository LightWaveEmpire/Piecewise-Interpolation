
CPPFLAGS=-g -std=c++11

CFLAGS=-g

TARGET=leastSquares

SRC=$(wildcard *.cpp)

OBJS=$(SRC:.cpp=.o)

LINK=g++ $(CPPFLAGS)

#LFLAGS=-lm /Users/ambers/OneDrive/Documents/ODU/2018-2019/Fall' 2018'/CS330/Assignment' 1'/registration_llist/Leak-Tracer/LeakTracer.o

.SUFFIXES:
.SUFFIXES: .d .o .h .c .cc .C .cpp
.c.o: ; $(CC) $(CFLAGS) -MMD -c $*.c
.cc.o: ; $(CPP) $(CPPFLAGS) -MMD -c $*.cc 
.C.o: ; $(CPP) $(CPPFLAGS) -MMD -c $*.C
.cpp.o: ; $(CPP) $(CPPFLAGS) -MMD -c $*.cpp

CC=gcc
CPP=g++

%.d: %.c
	touch $@
%.d: %.cc
	touch $@
%.d: %.C
	touch $@
%.d: %.cpp
	touch $@

DEPENDENCIES = $(OBJS:.o=.d)

# 
# Targets:
# 
all: $(TARGET)

$(TARGET): $(OBJS)
	$(LINK) $(FLAGS) -o $(TARGET) $(OBJS) $(LFLAGS)

clean:
	-rm -f $(TARGET) $(OBJS) $(DEPENDENCIES) make.dep


make.dep: $(DEPENDENCIES)
	-cat $(DEPENDENCIES) > make.dep

include make.dep


