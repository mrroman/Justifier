#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "kolejka.h"

Kolejka *wyrazy;

int margines;
int dl_kolumny;

void spaces(int n)
{
	int i;
	
	for (i = 0; i < n; i++)
		putchar(' ');
}



int 
main (int argc, char *argv[])
{
	char wyraz[128];
	int spacje[128];
	int t;
	int w;
	int i,j;
	
	if (argc < 3)
	{
		fprintf(stderr, "Za malo argumentow");	
	}
	
	sranddev();
	
	margines = atoi(argv[1]);
	dl_kolumny = atoi(argv[2]);
	
	wyrazy = kolejka_new(dl_kolumny);
	
	t = 0;
	w = 0;
	while (scanf("%s",wyraz) != EOF) 
	{
		kolejka_push(wyrazy, strdup(wyraz));
		w++;
		t += strlen(wyraz);
		if (dl_kolumny < (t + w - 1))
		{
			int t2 = t - strlen(wyraz);
			int w2 = w - 1;
			
			int sp = (dl_kolumny - t2) / (w2 - 1);
			int sp2 = (dl_kolumny - t2) % (w2 - 1);
			
			spaces(margines);
	
			printf("%s", (char *)kolejka_pop(wyrazy));
			
			for (i = 0; i < (w2 - 1); i++)
			{
				spacje[i] = sp;
			}
			
			for (i = 0; i < sp2; )
			{
				int r = rand() % (w2 - 1);
			
				if (spacje[r] == sp)
				{
					spacje[r]++;
					i++;
				}
			}
			
			for (i = 1; i < w2; i++)
			{
				spaces(spacje[i-1]);
				printf("%s", (char *)kolejka_pop(wyrazy));
			}
			
			printf("\n");	
			t-=t2;
			w-=w2;
		}
	}
	
	return 0;
}


