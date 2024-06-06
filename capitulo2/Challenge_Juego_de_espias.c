/*  
    SPY GAME. PROGRAMME THAT WAITS FOR USER INPUT TO KNOW
    IF IT HAS TO ENCODE OR DECODE, AND I'VE TO GIVE THE KEY  
*/

#include <stdio.h>
char ask_encode_decode();


void main(){
    char operation;
    
    operation = ask_encode_decode();
    if (operation == 'x')
        printf("Invalid input. Please enter only 'e' or 'd'.\n");
    else
        printf("You've chosen '%c'.\n", operation);
}


char ask_encode_decode(){
    int c, choice_made;
    char choice = 'x'; // Initialize to 'x' for failure

    choice_made=0;

    printf("Do you want to encode or decode a message [e/d]: ");
    
    while ((c=getchar())!='\n' && c!=EOF){
        // Ignore spaces
        if (c==' ')
            continue;

        // If a choice has already been made, print an error message
        if (choice_made){
            return 'x';
        }

        //Handle the user's choice
        if (c == 'e' || c == 'd'){
            choice_made = 1;
            choice = c;
        }
        else
            return 'x';
    }
    
    // If no choice was made, print an error message
    if(!choice_made) 
        return 'x';
    else
        return choice;
}