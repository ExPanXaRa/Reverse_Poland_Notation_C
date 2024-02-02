CC = gcc
FLAGS = -Wall -Wextra -Werror -c -lm


all: translate.o graph.o calculate.o print_graph.o stack.o
	$(CC) translate.o graph.o print_graph.o calculate.o stack.o -o ../build/graph 

print_graph.o: print_graph.c print_graph.h
	$(CC) $(FLAGS) print_graph.c

graph.o: graph.c
	$(CC) $(FLAGS) graph.c

calculate.o: calculate.c calculate.h
	$(CC) $(FLAGS) calculate.c

translate.o: translate.c translate.h
	$(CC) $(FLAGS) translate.c

stack.o: stack.c stack.h
	$(CC) $(FLAGS) stack.c

clean: 
	rm -rf ../build/graph
	rm -rf *.o

rebuild: clean all
