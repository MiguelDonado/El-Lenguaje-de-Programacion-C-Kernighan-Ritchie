#include <stdio.h>

int convert_fahr_to_celsius(int fahr);

int main(){
    float celsius, fahr;
    fahr = 64;
    printf("%d\n", fahr, convert_fahr_to_celsius(fahr));
    return 0;
}

int convert_fahr_to_celsius(int fahr){
    int celsius;
    celsius=(5.0/9.0)*(fahr-32.0);
    return celsius;
}