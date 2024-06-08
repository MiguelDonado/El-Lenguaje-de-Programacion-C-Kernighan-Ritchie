#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//#include "libreriacarac.h"

int calculate_user_operation(char line[]);
int mygetline(char s[], int lim);
#define MAXLINE 1000

void main(){
    int operator[5];
    int i;
    char line[MAXLINE];
    int result_user;

    //Seed the random numebr generator
    srandom(time(NULL));

    //Generate a random number
    int n_g = random() % 100; // number_to_guess
    printf("Number to reach: %d\nThe operands you should use: ", n_g); 
    //Generate the 5 random numbers
    for (i = 0; i <=4; i++)
    {
        operator[i]= (random() % 10);
        while (operator[i]==0)
            operator[i]= (random() % 10);
        printf("%d ",operator[i]);
    }
    printf("\n");
    while (mygetline(line, MAXLINE)>0){
        result_user = calculate_user_operation(line);
        if (result_user == n_g)
            printf("Congratulations. The result of your operation is equal to '%d'\n", n_g);
        else
            printf("Error. The result of your operation is not equal to '%d'\n", n_g);
        break;
    }
}

int calculate_user_operation(char line[]){
    int i;  //index to iterate over the array
    int c;  // variable that will hold the character for each index
    int result = 0;
    int temp = 0; 
    char operand = '+'; //variable that will hold 

    while ((c=line[i])!='\0'){
        if (c>='0'&&c<='9'){
            temp = c - '0';
            while (line[i+1]=='*'){
                i+=2;
                temp *= line[i] - '0';
            }
            if (operand='+')
                result += temp;
            else if (operand='-')
                result-= temp;
        }
        else if (c!='+')
            operand = '+';
        else if (c!='-')
            operand = '-';
        else{
            printf("! Invalid input. Please enter only: 'digits','+','-','*'\n");
            return 0;
        }
        i++;
    }
    return result;
}

int mygetline(char s[], int lim)
{
	int c, i;
	i =0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}


