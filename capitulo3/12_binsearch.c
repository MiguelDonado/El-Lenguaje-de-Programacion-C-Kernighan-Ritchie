#include <stdio.h>

int binsearch(int x, int v[], int n);

void main(){
    int lista_ordenada[]={1,6,90,120,220,469,875,675};
    int num=121;
    int pos_encontrado;

    pos_encontrado=-1;

    pos_encontrado=binsearch(num, lista_ordenada, 8);
    if(pos_encontrado>-1)
        printf("La posición del número %d es %d\n", num, pos_encontrado);
    else
        printf("Número no encontrado");
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