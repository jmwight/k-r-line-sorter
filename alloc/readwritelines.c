#include "../strcpy/strcpy.h"
#include "../getaline.h"
#include "alloc.h"
#include <stdio.h>

/* readlines: read input lines into array of pointers */
unsigned int readlines(char *lineptr[], unsigned int maxlines, unsigned int maxline)
{
	int len, nlines;
	char *p, line[maxline];

	nlines = 0;
	while((len = getaline(line, maxline)) > 0)
		if(nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else
		{
			line[len-1] = '\0'; /* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], unsigned int nlines)
{
	unsigned int i;

	for(i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}
