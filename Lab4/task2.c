/*

Task 2

Write a C program to do the following.
1. Open and read the text file you created in Task 1.
2. Count all instances of a certain character inside the file, for example:
  ./Program Spam.txt a // This should count all instances of a in Text.txt
    aaa // Count of a should be 3
      aba // Count of a should be 2
  ./Program Spam.txt h // This should count all instances of h in Text.txt
3. Print to terminal the amount of characters that it counted.
4. Comment your code and execute.

*/

#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[]) {

    //Check if the user input 3 arguments
    //1st as program name
    //2nd as source file or in this case spam.txt
    //3rd as the character being counted
    if (argc != 3) {
   	 printf("Include 3 args \n");   	 
   	 exit (-1);
    }

    //Initialize sourcefile
    char *filename;

    //Read the user's second argument from input as the filename
    filename = argv[1];
    
    //Initialize file and open
    //Parameter r is used for reading
    FILE *f;
    f = fopen(filename , "r");

    //Initialize character being looked for
    //Argv[2][0] is used because it takes the 1st character of the 3rd argument
    unsigned char c = (char) argv[2][0];

    //Check if opening the file causes any error
    if (f == NULL){
            	printf ("File does not exist \n");
            	exit (-1);
    	}

    //Initialize counter and character
    long count = 0;
    char character;

        //Checks the file until the end
        //If text matches the character, adds 1 to count variable
    	while ((character = getc(f)) != EOF){
   	 if(character == c) {
   		 count++;
   	 }
    }
    
    //Close the file
    fclose(f);
    printf("Counted %lu characters \n", count);
    return 1;
}
