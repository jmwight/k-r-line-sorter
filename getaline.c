#include <stdio.h>

/* gets next line and returns it's length */
int getaline(char *s, int mxlen)
{
	int l;
	for(l = 0; l < mxlen && (*s = getchar()) != EOF && *s != '\n'; ++l, ++s)
		;
	if(*s == EOF)
		*s = '\0';
	else
	{
		*++s = '\0';
		++l;
	}

	/* we return -2 to indicate buffer overrun */
	if(l >= mxlen)
		return -2;
	else
		return l;
}
