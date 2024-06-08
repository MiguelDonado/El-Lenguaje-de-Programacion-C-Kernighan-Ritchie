#include <stdio.h>

int binsearch(int x, int v[], int n);

void main(){
    int lista_ordenada[]={1,6,90,120,220,469,875};
    int i;
    int pos_encontrado;

    for (i = 0; i < 7; i++)
    {
        pos_encontrado=binsearch(lista_ordenada[i], lista_ordenada, 7);
        if(pos_encontrado>-1)
            printf("La posición del número %d es %d\n", lista_ordenada[i], pos_encontrado);
        else
            printf("Número no encontrado");
    }
    pos_encontrado=-1;
}

int binsearch(int x, int v[], int n){
    int low, high, mid;

    low=0;
    high=n-1;
    while(low<=high){
        mid=(low+high)/2;
        if(x<v[mid]){
            high=mid-1;
        }
        else if(x>v[mid]){
            low=mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;
}