#include <stdlib.h>

#include "kolejka.h"

Kolejka* kolejka_new(int size)
{
	Kolejka *kolejka;
	
	kolejka = (Kolejka *)malloc(sizeof(Kolejka));
	kolejka->n = 0;
	kolejka->size = size;
	kolejka->buffer = (void **)malloc(sizeof(void *) * size);
	
	return kolejka;
}

void kolejka_push(Kolejka *kolejka, void *element)
{
	kolejka->buffer[kolejka->n] = element;
	kolejka->n = (kolejka->n + 1) % kolejka->size;
}

void *kolejka_pop(Kolejka *kolejka)
{
	if (kolejka->n == 0)
		kolejka->n = kolejka->size - 1;
	else
		kolejka->n--;
		
	return kolejka->buffer[kolejka->n];
}

