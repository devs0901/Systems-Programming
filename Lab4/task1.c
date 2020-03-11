/*

Write a C program to do the following.
1. Using generator.c, utilize its generate() function to write random characters to a text file named Spam.txt.
2. Using <time.h>, time how long it takes for generate() to run.
3. When compiling the program, make sure the generator.c is also attached to the program or else the code won’t run.
4. Comment your code and execute.

*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "generator.h"

int main() {
    //Initialize file 
    FILE *f;
    //Open the file
    //Parameter w for writing
    f = fopen("Spam.txt", "w");

    //Initialize a clock as a time counter for system
    clock_t t;
    t = clock(); 
    //Call C file generate() on the file   
    generate(f);
    //Value of t is updated
    t = clock() - t;
    double time = ((double)t)/CLOCKS_PER_SEC; //in seconds
    printf("generate() took %f seconds to execute \n", time);    
    return 1;
}
