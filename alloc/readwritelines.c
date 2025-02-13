#include "../strcpy/strcpy.h"
#include "../getaline.h"
#include "alloc.h"
#include <stdio.h>
/* time measuring */
#include <sys/time.h>

/* readlines: read input lines into array of pointers */
int readlines(char *lineptr[], int maxlines, int maxline, int *t)
{
	int len, nlines;
	char *p, line[maxline];
	/* time measuring variables */
	struct timeval t0, t1;

	nlines = 0;
	while((len = getaline(line, maxline)) > 0 && line[0] != '\n')
	{
		gettimeofday(&t0, NULL); // start time
		if(nlines >= maxlines || (p = alloc(len+1)) == NULL)
			return -1;
		else
		{
			if(line[len-1] == '\n')
				line[len-1] = '\0'; /* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
		gettimeofday(&t1, NULL); // stop time
		*t += (t1.tv_sec - t0.tv_sec) * 1E6 + t1.tv_usec - t0.tv_usec; // add operation time to total
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
