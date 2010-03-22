

test: kolejka-test

kolejka-test: kolejka.o test-kolejka.o
	gcc -o test-kolejka kolejka.o test-kolejka.o
	./test-kolejka
