#include "../strcpy/strcpy.h"
#include "../getaline.h"
#include "alloc.h"
#include <stdio.h>

/* readlines: read input lines into array of pointers */
int readlines(char *lineptr[], char *linemem, int linememsize, int maxlines, int maxline)
{
	int nlines, len;
	while((len = getaline(linemem, maxline > linememsize ? linememsize : maxline)) > 0 && *linemem != '\n', nlines < maxline)
	{
		linememsize -= len + 1;
		linemem += len + 1;
		++nlines;
	}
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
	int i;

	for(i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}
