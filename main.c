#include "getaline.h"
#include <stdlib.h>
#include <stdio.h>
#include "alloc/alloc.h"
#include "strcpy/strcpy.h"
#include <unistd.h>

#define MAXLINELEN	1024

main()
{
	char *s = calloc(MAXLINELEN, sizeof(char));
	int i = 0;
	char *lineptrlist[25];
	int n = 0;
	while(i != EOF)
	{
		i = getaline(s, MAXLINELEN);
		char *p = alloc(i+1); /* i+1 because we need room for null termination character */
		strcpy(p, s);
		lineptrlist[n++] = p;
	}

	int x;
	for(x = 0; x < n; ++x)
	{
		printf("s%d = %s\n", x, lineptrlist[x]);
	}

	return 0;
}
