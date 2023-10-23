CC = g++
EXEC = prog

all : $(EXEC)

$(EXEC) : main.o Rubik.o Solve.o Solution.o Algs.o
	$(CC) -o $(EXEC)  main.o Rubik.o Solve.o Solution.o Algs.o 
	./prog

main.o : main.cpp
	$(CC) -o main.o -c main.cpp

Rubik.o : Rubik.cpp
	$(CC) -o Rubik.o -c Rubik.cpp

Solve.o : Solve.cpp
	$(CC) -o Solve.o -c Solve.cpp

Solution.o : Solution.cpp
	$(CC) -o Solution.o -c Solution.cpp

Algs.o : Algs.cpp
	$(CC) -o Algs.o -c Algs.cpp

clean:
	rm *.o 