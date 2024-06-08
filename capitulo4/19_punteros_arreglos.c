/*
    CURSO C LIBRO KERNIGHAN & RITCHIE
    uso de los punteros con los arreglos

    copia y comparación de dos arreglos de caracteres
    herramientas: funciones, for, arrays
*/
#include <stdio.h>
#define MAXLINE 1000 /*tamaño máximo de la línea*/

void mystrcpy(char *s, char *t);
int strcmp(char *s, char *t);

int main(){
    char origen[]="Paco tiene un coche azul\0";
    char copia[MAXLINE];

    mystrcpy(copia,origen);
    printf("%s\n",copia);
    printf("%d\n", strcmp(copia, origen));
    return 0;
}
void mystrcpy(char *s, char *t)
{
    int i;
    i=0;

    while ((*s=*t)!='\0')
    {
        s++;
        t++;
    }
    
}

// strcmp: return <0 if s<t, 9 if s==t, >0 if s>t
int strcmp(char *s, char *t){
    int i=0;

    for (; *s==*t; s++,t++)
        if(*s=='\0')
            return 0;
    return *s-*t;
}

