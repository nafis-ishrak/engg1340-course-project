#creating a make file so that it is easy to compile and run the code

FLAGS = g++ -pedantic-errors -std=c++11

periodictable.o: periodictable.cpp periodictable.h
	$(FLAGS) -c periodictable.cpp

numbers.o: numbers.cpp numbers.h 
	$(FLAGS) -c numbers.cpp

main.o: main.cpp periodictable.h numbers.h
	$(FLAGS) -c main.cpp

game: main.o periodictable.o numbers.o
	$(FLAGS) main.o periodictable.o numbers.o -o game

clean:
	rm -rf game main.o periodictable.o numbers.o

.PHONY: clean
