
main: main.o kolejka.o
	gcc -o wyrow main.o kolejka.o

test: test-kolejka 

test-kolejka: kolejka.o test-kolejka.o
	gcc -o test-kolejka kolejka.o test-kolejka.o
	./test-kolejka
