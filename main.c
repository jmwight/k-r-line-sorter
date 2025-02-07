#include <stdlib.h>
#include <stdio.h>
#include "alloc/readwritelines.h"
#include <string.h>

#define MAXLINELEN	1024U
#define MAXLINES	5120U

char *lineptr[MAXLINES];

void qsortlines(char *v[], unsigned int left, unsigned int right);
void swap(char *v[], unsigned int i, unsigned int j);

/*
main()
{
	int i;
	char s[MAXLINELEN];
	getaline(s, MAXLINELEN);
	printf("\n%s\n", s);
}*/

main()
{
	unsigned int nlines;  //number of input lines read 

	if((nlines = readlines(lineptr, MAXLINES, MAXLINELEN)) >= 0)
	{
		qsortlines(lineptr, 0u, nlines - 1);
		writelines(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("error: input too big to sort\n");
		return 1;
	}
}

/* qsortlinesline: sorts array of line pointers based on strcmp lowest to highest */
void qsortlines(char *v[], unsigned int left, unsigned int right)
{
	unsigned int i, last;
	
	if(left >= right) /* do nothing if array contains */
		return;   /* fewer than two elements */
	swap(v, left, (left+right)/2);
	last = left;
	for(i = left+1; i <= right; i++)
		if(strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsortlines(v, left, last-1);
	qsortlines(v, last+1, right);
}

/* swap: swaps v[i] and v[j] */
void swap(char *v[], unsigned int i, unsigned int j)
{
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
