#include <stdio.h>
#define MAXLINE 1000 // tamaño máximo de la linea de entrada

int getline2(char line[],int maxline);
void copy(char to[], char from[]);

int main() {
    int len; // longitud de linea actual
    int max; // maxima longitud vista hasta la fecha
    char line[MAXLINE]; // linea actual
    char longest[MAXLINE]; // linea mas larga

    max = 0;
    while((len=getline2(line, MAXLINE))>0){
        if (len>max){
            max=len;
            copy(longest,line);
        }
    }
    if(max>0){
        printf("%s", longest);
    }
    return 0;
}

/*getline2: lee una linea en s, regresa su longitud*/
int getline2(char s[],int lim){
    int c,i;

    for(i=0;(i<lim-1)&&((c=getchar())!=EOF)&&(c!='\n');i++)
        s[i]=c;
    if(c=='\n'){
        s[i]=c;
        i++;
    }
    s[i]='\0';
    return i;
}

/*copy: copia from hacia to*/
void copy(char to[], char from[]){
    int i;

    i=0;
    while((to[i]=from[i])!='\0'){
        i++;
    }
}