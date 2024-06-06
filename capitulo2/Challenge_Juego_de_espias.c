/*  
    SPY GAME. PROGRAMME THAT WAITS FOR USER INPUT TO KNOW
    IF IT HAS TO ENCODE OR DECODE, AND I'VE TO GIVE THE KEY  
*/

#include <stdio.h>
char ask_encode_decode();
int number_of_positions();

void main(){
    char operation;
    int key;

    operation = ask_encode_decode();
    if (operation == 'x')
        printf("Invalid input. Please enter only 'e' or 'd'.\n");
    else
        printf("You've chosen '%c'.\n", operation);
        key = number_of_positions();
        if (key)
            printf("You've selected the next key: %d\n", key);
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

int number_of_positions(){
    int key,c,sign;

    key = 0;
    sign = 1;

    printf("What is the key (number of positions)? [-26 to 26 excluding 0]: ");

    // Skip leading spaces
    while ((c=getchar())==' ');

    // Handle the negative sign
    if (c=='-'){
        sign = -1;
        c = getchar();
    }

    // Read the number
    while ((c>='0' && c<='9')){
        key = key * 10 + (c - '0');
        c=getchar();
    }

    key*=sign;

    // Check if the key is within the valid range
    if (key < -26 || key > 26 || key == 0){
        printf("Invalid key. Please enter a number between -26 and 26, excluding 0.\n");
        return 0;  //Return 0 to indicate an error
    }

    return key; // Return the key on success
}