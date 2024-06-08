/*
    CURSO C LIBRO KERNIGHAN & RITCHIE
    conversor de char[] a numero

    a partir de un array de caracteres convertiremos a un doble
    herramientas: funciones, arreglos de cadenas
*/

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

int mygetline(char line[], int max);
double atof(char s[]);
char ask_user_decimal_sep();

char decimal_separator;


int main()
{
	decimal_separator = ask_user_decimal_sep();
	if (decimal_separator=='x'){
        printf("! Invalid input. Please enter only '.' or ','.\n");
		return 1;	
	}
	char line[MAXLINE];
	int found = 0;
	while (mygetline(line, MAXLINE) > 0) {
		printf("\t %6.3f\n",atof(line));
	}
	return 0;
}

char ask_user_decimal_sep(){
	int c, choice_made;
	char choice='x'; // Initialize to 'x' for failure
	
	choice_made=0;

	printf("What decimal separator do you wanna use [./,]? ");
	
	while((c=getchar())!='\n' && c!=EOF){
		if (c==' ')
			continue;
		
		// If a choice has already been made, return failure
		if (choice_made){
			return 'x';
		}
		// Handle the user's choice
		if (c=='.' || c==','){
			choice_made=1;
			choice=c;
		}
		else{
			return 'x';
		}
	// If no choice has been made
	if (!choice_made){
		return 'x';
	}
	else
		c=getchar();
		return choice;
	}
}

/*mygetline: trae una linea y la pone en s, regresa su longitud*/
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

double atof(char s[])
{
	double val, power;
	int i, sign; //Indice del arreglo de caracteres

	for (i = 0; isspace(s[i]); i++) //Elimina los espacios en blanco
		;

	sign = (s[i] == '-') ? -1 : 1; //Signo negativo
	if (s[i] == '+' || s[i] == '-') //Saltamos caracter + o -
		i++;

	for (val = 0.0; isdigit(s[i]); i++) //Transforma a numero la parte entera
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == decimal_separator) //Saltar al decimal
		i++;

	for (power = 1.0; isdigit(s[i]); i++) { //Transforma a numero la parte decimal
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	return sign*val/power;

}