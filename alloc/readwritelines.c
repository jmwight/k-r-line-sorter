#include "../strcpy/strcpy.h"
#include "../getaline.h"
#include "alloc.h"
#include <stdio.h>

/* readlines: read input lines into array of pointers */
int readlines(char *lineptr[], char *linemem, int linememsize, int maxlines, int maxline)
{
	int nlines, len, i;
	nlines = i = 0;
	while((len = getaline(linemem, maxline > linememsize ? linememsize : maxline)) > 0 && *linemem != '\n', nlines < maxline)
	{
		linememsize -= len + 1;
		lineptr[i++] = linemem; // set line pointer
		if(linemem[len - 1] == '\n') // remove \n if it has it and reduce length accordingly
			linemem[--len] = '\0';
		linemem += len + 1; // len + 1 because length of line doesn't include '\0' at the end 
		++nlines;
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
