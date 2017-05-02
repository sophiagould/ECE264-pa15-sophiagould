CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -Wunreachable-code
#COVFLAGS = -fprofile-arcs -ftest-coverage
GCC = gcc $(CFLAGS) #$(COVFLAGS)
OBJ = pa15.o funcs.o huff.o
VALGRIND = valgrind --tool=memcheck --leak-check=yes 

all: pa15

funcs.o: funcs.c funcs.h
	$(GCC) -c funcs.c -o funcs.o

huff.o: huff.c huffman.h
	$(GCC) -c huff.c -o huff.o 

pa15.o: pa15.c huff.c funcs.c
	$(GCC) -c pa15.c -o pa15.o 

pa15: $(OBJ) huffman.h funcs.h huff.c funcs.c pa15.c
	$(GCC) $(OBJ) -o pa15 -lm

test: pa15
	./pa15 inputs/basic basic_sorted basic_huffman basic_header
	./pa15 inputs/gophers gophers_sorted gophers_huffman gophers_header
	./pa15 inputs/para para_sorted para_huffman para_header
	./pa15 inputs/prideandprejudice prideandprejudice_sorted prideandprejudice_huffman prideandprejudice_header
	./pa15 inputs/woods woods_sorted woods_huffman woods_header
	diff ./expected/basic_sorted basic_sorted
	diff ./expected/basic_huffman basic_huffman
#	diff ./expected/basic_header basic_header
	diff ./expected/gophers_sorted gophers_sorted
	diff ./expected/gophers_huffman gophers_huffman
#	diff ./expected/gophers_header gophers_header
	diff ./expected/para_sorted para_sorted
	diff ./expected/para_huffman para_huffman
#	diff ./expected/para_header para_header
	diff ./expected/prideandprejudice_sorted prideandprejudice_sorted
	diff ./expected/prideandprejudice_huffman prideandprejudice_huffman
#	diff ./expected/prideandprejudice_header prideandprejudice_header
	diff ./expected/woods_sorted woods_sorted
	diff ./expected/woods_huffman woods_huffman
#	diff ./expected/woods_header woods_header


#%.o: %.c
#	$(GCC) -c $<

memory: pa15
	valgrind --leak-check=full --show-reachable=yes -v ./pa15 inputs/basic basic_sorted basic_huffman basic_header
	valgrind --leak-check=full --show-reachable=yes -v ./pa15 inputs/gophers gophers_sorted gophers_huffman gophers_header
	valgrind --leak-check=full --show-reachable=yes -v ./pa15 para para_sorted para_huffman para_header
	valgrind --leak-check=full --show-reachable=yes -v ./pa15 prideandprejudice prideandprejudice_sorted prideandprejudice_huffman prideandprejudice_header
	valgrind --leak-check=full --show-reachable=yes -v ./pa15 woods woods_sorted woods_huffman woods_header


clean:
	rm -f *.o
	rm -f funcs.gcno
	rm -f funcs.gcda
	rm -f huff.gcno
	rm -f huff.gcda
	rm -f pa15.gcno
	rm -f pa15.gcda
	rm -f pa15
