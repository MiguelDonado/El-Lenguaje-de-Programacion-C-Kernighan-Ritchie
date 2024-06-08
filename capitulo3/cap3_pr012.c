#include <stdio.h>

#define MAXLINE 1000

int mygetline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "es";

void main()
{
	char line[MAXLINE];
    int num = 0; //variable that will hold the number of occurrences

	while (mygetline(line, MAXLINE) > 0) {
		if ((num=strindex(line, pattern))>0) {
			printf("o El patron '%s' ha sido encontrado %d veces en la linea:\n# %s",pattern,num, line);
		}
	}
}

/*mygetline: trae una linea y la pone en s, regresa su longitud*/
int mygetline(char s[], int lim)
{
	int c, i;
	i =0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/*strindex: regres el índice de t en s, -1 si no existe*/
int strindex(char s[], char t[]){
    int i,j,k;
    int n; //variable that will hold the nomber of ocurrences of the pattern in the string

    n=0;
    for (i = 0; s[i]!='\0'; i++){
		// k is to move through the pattern and j is to move through the string
        for(j=i,k=0;t[k]!='\0'&&s[j]==t[k];j++,k++)
        ;
        if(k>0&&t[k]=='\0')
            n++;
    }
    return n;
}