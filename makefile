CPP_STD=--std=c++11
C_STD=--std=c99
CPP_FLAGS = $(CPP_STD) -O0 -g -Wall -Werror
C_FLAGS = $(C_STD) -O0 -g -Wall -Werror

CPP_FILES=$(wildcard *.cpp)
CPP_O_FILES=$(subst .cpp,.o,$(CPP_FILES))

CC_FILES=$(wildcard *.cc)
CC_O_FILES=$(subst .cc,.o,$(CC_FILES))

C_FILES=$(wildcard *.c)
C_O_FILES=$(subst .cc,.o,$(C_FILES))

O_FILES = $(CPP_O_FILES) $(CC_O_FILES) $(C_O_FILES)
NAME=plagiarismCatcher

$(NAME) : $(O_FILES)
	g++ $(CPP_STD) -o $(NAME) $(O_FILES)

$(CPP_O_FILES) : %.o : %.cpp
	g++ $(CPP_FLAGS) -MD -o $*.o -c $*.cpp

$(CC_O_FILES) : %.o : %.cc
	g++ $(CPP_FLAGS) -MD -o $*.o -c $*.cc

$(C_O_FILES) : %.o : %.c
	g++ $(C_FLAGS) -MD -o $*.o -c $*.c

clean:
	rm -rf *.o $(NAME)
