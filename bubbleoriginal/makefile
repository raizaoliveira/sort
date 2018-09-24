	
all:
	gcc -c load_array.c -Wall -Wextra -pedantic
	ar rcs libload_array.a *.o
	gcc -o bubbleori bubbleori.c -L. -lload_array -Wall -Wextra -pedantic
