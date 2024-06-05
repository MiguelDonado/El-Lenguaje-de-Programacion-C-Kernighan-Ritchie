#include <stdio.h>
#define MAXLINE 1000 //tamaño maximo de la linea

int getline2(char line[], int maxline);
void copy(char to[], char from[]);

void main(){
    int len; // longitud linea actual
    int max; // longitud linea mas larga
    char line[MAXLINE]; // linea actual
    char longest[MAXLINE]; // linea mas larga

    max=0;
    while((len=getline2(line, MAXLINE))>0){
        if (len>max){
            max=len;
            copy(longest, line);
        }
    }
    if (max>0){
        printf("%s",longest);
    }
}

int getline2(char s[], int lim){
    int c, i, nw;

    nw=0;
    while((c=getchar())==' '){
        ++nw;
    }
    if (c==EOF){
        return 0;
    }
    s[0]=c;

    for (i = 1; (i<lim-1)&&((c=getchar())!=EOF)&&(c!='\n'); i++)
    {
        s[i]=c;
    }
    if (c=='\n'){
        s[i]=c;
        i++;
    }
    s[i]='\0';
    return i;
}

void copy(char to[], char from[]){
    int i;

    while((to[i]=from[i])!='\0'){
        i++;
    }
}