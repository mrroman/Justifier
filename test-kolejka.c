#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "kolejka.h"

void test_pop(Kolejka *kolejka, void *expected)
{
	void *element = kolejka_pop(kolejka);
	
	printf("Element: %s Expected: %s\n", (char *)element, (char *)expected);
	assert(element == expected);
}

int 
main (int argc, char *argv[])
{
	Kolejka *kolejka;
	
	kolejka = kolejka_new(3);
	
	kolejka_push(kolejka, "aaa");
	kolejka_push(kolejka, "bbb");
	kolejka_push(kolejka, "ccc");	
	
	test_pop(kolejka, "aaa");
	test_pop(kolejka, "bbb");
	test_pop(kolejka, "ccc");
	
	return 0;
}



