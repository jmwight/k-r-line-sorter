#include "getaline.h"
#include <stdlib.h>
#include <stdio.h>

#define MAXLINELEN	1024

main()
{
	char *s = calloc(MAXLINELEN, sizeof(char));
	int i = 0;
	while(i != EOF)
	{
		i = getaline(s, MAXLINELEN);
		printf("%s\n", s);
	}
	return 0;
}
