#include "../strcpy/strcpy.h"
#include "../getaline.h"
#include "alloc.h"
#include <stdio.h>

/* readlines: read input lines into array of pointers */
int readlines(char *lineptr[], int maxlines, int maxline)
{
	int len, nlines;
	char *p, line[maxline];

	nlines = 0;
	while((len = getaline(line, maxline)) > 0 && line[0] != '\n')
		if(nlines >= maxlines || (p = alloc(len+1)) == NULL)
			return -1;
		else
		{
			if(line[len-1] == '\n')
				line[len-1] = '\0'; /* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	int i;

	for(i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}
