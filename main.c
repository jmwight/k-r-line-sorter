#include <stdlib.h>
#include <stdio.h>
#include "alloc/readwritelines.h"
#include <string.h>

#define MAXLINELEN	1024
#define MAXLINES	5120

char *lineptr[MAXLINES];

void qsortlines(char *v[], int left, int right);
void swap(char *v[], int i, int j);

/*
main()
{
	int i;
	char s[MAXLINELEN];
	getaline(s, MAXLINELEN);
	printf("\n%s\n", s);
}*/

int main(void)
{
	int nlines;  //number of input lines read 

	printf("Enter lines to sort below:\n");
	if((nlines = readlines(lineptr, MAXLINES, MAXLINELEN)) >= 0)
	{
		qsortlines(lineptr, 0, nlines - 1);
		printf("\n\nSorted lines:\n");
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
void qsortlines(char *v[], int left, int right)
{
	int i, last;
	
	if(left >= right) /* do nothing if array contains */
		return;   /* fewer than two elements */
	swap(v, left, (left+right)/2);
	last = left;
	for(i = left+1; i <= right; i++) // was i <= right
		if(strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsortlines(v, left, last-1);
	qsortlines(v, last+1, right);
}

/* swap: swaps v[i] and v[j] */
void swap(char *v[], int i, int j)
{
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
