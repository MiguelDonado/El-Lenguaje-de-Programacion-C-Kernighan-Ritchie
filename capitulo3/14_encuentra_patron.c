#include <stdio.h>

#define MAXLINE 1000

int mygetline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "es";

int main()
{
	char line[MAXLINE];
	int found = 0;

	while (mygetline(line, MAXLINE) > 0) {
		if (strindex(line, pattern)>=0) {
			printf("%s", line);
			found++;
		}
	}
	return found;
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

    for (i = 0; s[i]!='\0'; i++){
		// k is to move through the pattern and j is to move through the string
        for(j=i,k=0;t[k]!='\0'&&s[j]==t[k];j++,k++)
        ;
        if(k>0&&t[k]=='\0')
            return i;
    }
    return -1;
}