/*

Task 2

1. Write a C program to do the following.
Open and read the “Input.txt” file into C. You can choose the method in which to
read the file.

2. Replace the target phrases in the table below with the corresponding output.
  
  Inferno -> Paradiso
  In dark woods -> Using Windows 8.1
  those woods -> Windows 8.1
  to enter -> to use 8.1
  crest -> screen
  Below a hill -> Before a monitor
  shoulders -> GUI
  planet -> UNIX
  dante -> Shakespeare
  
3. After having replaced all target phrases, write to file “Dante.txt” the changes.

4. Comment your code and make sure the code handles error conditions.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//method replaces a target phrase from a line of text with a desired phrase
char *replacement(const char *textLine, const char *target, const char *desired) {
    
	int i = 0; //set i to 0
    //initialize desired line with enough space allocated for large strings
	char *desiredLine = malloc(255);
    //while loop cycles through characters in the text line
	while (*textLine) {
   	 /*
   	 if the current index of textLine matches with the
   	 index of the occurrence of the target substring,
   	 the desired substring will be copied to the new line in place of the target
   	 */
    	if (strstr(textLine, target) == textLine) {
        	strcpy(&desiredLine[i],desired);
        	i +=strlen(desired);
        	textLine +=strlen(target);
    	}
   	 //otherwise the current character from the old line of text will be copied to the new line
    	else {
        	desiredLine[i++] = *textLine++;
    	}
	}
	//end the string
	desiredLine[i] = '\0';
    //return line of text with target replaced
	return desiredLine;
}

int main()
{

    	FILE *in_file = fopen ("Input.txt","r");
    	//parameter r for 'open for reading'

    	FILE *out_file = fopen ("Dante.txt","w");
    	//parameter w for 'open for writing'

   	 
    
    	//check if the file exist
    	if (in_file == NULL || out_file == NULL){
            	printf ("No such file");
            	exit (-1); //stdlib.h was used for this
    	}
   	 
    	char *textLine = malloc(255); //create string to hold file input
   	 
   	 //cycle through the input file until the fgets results in NULL value
    	while ((fgets(textLine,255,in_file)) != NULL) {
        	/*
   		 check if one of the specified phrases is in the current line of text
   		 and replace it with desired phrase if it is
   		 */
   		 if(strstr(textLine,"Inferno") !=NULL){
            	textLine = replacement(textLine, "Inferno", "Paradisio");
        	}
        	if(strstr(textLine,"In dark woods") !=NULL){
   		 	textLine = replacement(textLine, "In dark woods", "using Windows 8.1");
   		 }
   		 if(strstr(textLine,"those woods") !=NULL){
   			 textLine = replacement(textLine, "those woods", "Windows 8.1");
   		 }
   		 if(strstr(textLine,"to enter") !=NULL){
   			 textLine = replacement(textLine, "to enter", "to use 8.1");
   		 }
   		 if(strstr(textLine,"crest") !=NULL){
   			 textLine = replacement(textLine, "crest", "screen");
   		 }
   		 if(strstr(textLine,"Below a hill") !=NULL){
   			 textLine = replacement(textLine, "Below a hill", "Before a monitor");
   		 }
   		 if(strstr(textLine,"shoulders") !=NULL){
   			 textLine = replacement(textLine, "shoulders", "GUI");
   		 }
   		 if(strstr(textLine,"planet") !=NULL){
   			 textLine = replacement(textLine, "planet", "UNIX");
   		 }
   		 if(strstr(textLine,"dante") !=NULL){
   			 textLine = replacement(textLine, "dante", "Shakespeare");
   		 }
   		 
   		 //write the line in the output file
   		 fputs(textLine,out_file);
   		 
    	}
    	//free memory used by text line
   	 free(textLine);
   	 
   	 //let the user know that the program is finished
   	 printf("Finished writing to file \n");

   	 fclose(in_file); //close the Input.txt file
   	 fclose(out_file); //close the Dante.txt file
   	 return 0;
}
