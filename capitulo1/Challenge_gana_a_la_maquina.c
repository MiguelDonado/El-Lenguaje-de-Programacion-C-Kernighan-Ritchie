/*
    RETO 1. GANA A LA MAQUINA

        juego de turnos. usuario vs maquina. el que adivine antes gana

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(){
    srand(time(NULL));
    int rand_numb = (rand() % 26) + 65;
    char game_solution = rand_numb;
    int user_char, computer_try;
    char computer_try_char;
    while (1){
        user_char = toupper(getchar());
        if (user_char==EOF){
            break;
        }
        if (user_char!='\n'){
            if (user_char == game_solution){
                printf("Enhorabuena has acertado la letra: %c\n", game_solution);
                break;
            }
            else {
                printf("User: %c is not correct\n", toupper(user_char));
            }
            
            computer_try = (rand() % 26) + 65; 
            computer_try_char = computer_try;
            if (computer_try_char == game_solution){
                printf("La maquina ha ganado. La letra era: %c\n", game_solution);
                break;
            }
            else {
                printf("Computer: %c is not correct\n", toupper(computer_try_char));
            }
        }
    }
}
