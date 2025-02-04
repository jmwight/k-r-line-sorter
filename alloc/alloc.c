#include "alloc.h"

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

/* alloc: allocate storage of n size and return pointer to it */
char *alloc(int n) /* return pointer to n characters */
{
	if(allocbuf + ALLOCSIZE - allocp >= n) /* it fits */
	{
		allocp += n;
		return allocp - n; /* old p */
	} 
	else
		return 0;
}

/* afree: free storage pointed to by p */
void afree(char *p)
{
	if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}
