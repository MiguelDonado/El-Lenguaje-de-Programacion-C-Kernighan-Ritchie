#include <stdio.h>

int main(){
    int c, i, nwhite, nother, npunctuation;
    int ndigit[10];

    nwhite=nother=npunctuation=0;

    for ( i = 0; i < 10; i++)
    {
        ndigit[i]=0;    
    }

    while((c=getchar())!=EOF){
        if (c==' '||c=='\n'||c=='\t'){
            ++nwhite;
        }
        else if (c=='.'||c==','){
            ++npunctuation;
        }
        else if (c>='0'&&c<='9'){
            ++ndigit[c-'0'];
        }
        else {
            ++nother;
        }
    }
    printf("El número de espacios en blancos: %d\n", nwhite);
    printf("El número de puntos o comas: %d\n", npunctuation);
    printf("El número de dígitos es: ");
    for (i = 0; i < 10; i++)
    {
        printf("%d:%d ### ",i,ndigit[i]);
    }
    printf("\nEl número de otros caracteres: %d\n", nother);
}