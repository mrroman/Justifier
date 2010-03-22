#include <stdlib.h>

#include "kolejka.h"

Kolejka* kolejka_new(int size)
{
	Kolejka *kolejka;
	
	kolejka = (Kolejka *)malloc(sizeof(Kolejka));
	kolejka->n = 0;
	kolejka->m = 0;
	kolejka->size = size;
	kolejka->buffer = (void **)malloc(sizeof(void *) * size);
	
	return kolejka;
}

void kolejka_push(Kolejka *kolejka, void *element)
{
	kolejka->buffer[kolejka->m] = element;
	kolejka->m = (kolejka->m + 1) % kolejka->size;
}

void *kolejka_pop(Kolejka *kolejka)
{
	void *element = kolejka->buffer[kolejka->n];
	
	kolejka->n = (kolejka->n + 1) % kolejka->size;	
	return element;
}

