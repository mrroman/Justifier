#ifndef __KOLEJKA_H__
#define __KOLEJKA_H__

typedef struct
{
	int n;
	int size;
	void **buffer;
} Kolejka;

Kolejka* kolejka_new(int size);
void kolejka_push(Kolejka *kolejka, void *element);
void *kolejka_pop(Kolejka *kolejka);

#endif /* __KOLEJKA_H__ */

