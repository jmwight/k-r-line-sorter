#ifndef READWRITELINES_H
#define READWRITELINES_H	1

int readlines(char **lineptr, int maxlines, int maxline, int *microseconds);
void writelines(char **lineptr, int nlines);

#endif
