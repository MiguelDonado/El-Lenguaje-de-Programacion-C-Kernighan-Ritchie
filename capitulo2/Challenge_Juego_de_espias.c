/*  
    SPY GAME. PROGRAMME THAT WAITS FOR USER INPUT TO KNOW
    IF IT HAS TO ENCODE OR DECODE, AND I'VE TO GIVE THE KEY  
*/

#include <stdio.h>
#define MAXLINE 1000

char ask_encode_decode();
int number_of_positions();
void get_message(char s[], int lim);

int main(){
    char operation; // Variable to store the type of operation (encode or decode)
    int key;  // Variable to store the number of positions to shift when encoding / decoding
    char message_before[MAXLINE]; // Variable to store the message before being encoded / decoded
    char message_after[MAXLINE]; // Variable to store the message after being encoded / decoded

    // prompt the user to choose between encode or decode
    operation = ask_encode_decode();
    
    // if there is an error on the user input when selecting between encode or decode
    if (operation == 'x'){
        printf("! Invalid input. Please enter only 'e' or 'd'.\n");
        return 1;
    }

    printf("o You've chosen '%c'.\n", operation);
    
    // get the key that'll be used to encode / decode
    key = number_of_positions();

    // if there is an error on the user input when choosing the key
    if (!key){
        return 1;
    }

    // if the user has selected to encode
    if (operation='e'){
        printf("o You've selected the next key to encode your message: %d\n", key);
        get_message(message_before, MAXLINE);
        printf("###############\no A key of %d positions is being used to encode the following message:\n%s", key, message_before);
    }

    //if the user has selected to decode
    else if (operation='d'){
        printf("o You've selected the next key to decode your message: %d\n", key);
        get_message(message_before, MAXLINE);
        printf("###############\no A key of %d positions is being used to encode the following message:\n%s", key, message_before);
    }
}


char ask_encode_decode(){
    int c, choice_made;
    char choice = 'x'; // Initialize to 'x' for failure

    choice_made=0;

    printf("? Do you want to encode or decode a message [e/d]: ");
    
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

    printf("? What is the key (number of positions)? [-26 to 26 excluding 0]: ");

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

void get_message(char s[], int lim){
    int c, i;

    printf("? Introduce the message you want to work with: \n###############\n");

    for (i = 0; (i<lim-1) && ((c=getchar())!=EOF); i++)
    {
        s[i] = c;
    }
    s[i]='\0';
}

