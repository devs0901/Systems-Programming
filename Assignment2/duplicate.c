/*

Jane Coralde | 100660214

Write a C program called duplicate which simply copies a file from one place to another. The
program will be invoked as follows: 
	duplicate SourceFile TargetFile

duplicate must create an exact duplicate of SourceFile under the new name TargetFile .
Upon successful completion, duplicate should report the total number of bytes copied and exit
with result zero. For example: 
	duplicate: Copied 38475 bytes from file foobar to bizbaz.

Where ” SourceFile ” is foobar and “ TargetFile ” is bizbaz
If the duplicate takes longer than one second, then every second the program will emit a short
message: 
	duplicate: still duplicateing...
	duplicate: still duplicateing...
	duplicate: still duplicateing…
	
If duplicate encounters any kind of error or user mistake, it must immediately stop and emit a
message that states the program name, the failing operation, and the reason for the failure, and
then exit with result 1. For example:
	duplicate: Couldn't open file foobar: Permission Denied.
	duplicate: Couldn't write to file bizbaz: Disk Full.

If the program is invoked incorrectly, then it should immediately exit with a helpful message:
duplicate: Too many arguments!
usage: 
	duplicate <sourcefile> <targetfile>

Compile and execute using:
	gcc duplicate.c -o duplicate
	./duplicate <sourcefile> <targetfile>	
	
*/

#include <stdio.h> #include <stdlib.h>
#include <unistd.h>
#include <time.h>
int main(int argc, char *argv[])
{
	//initialize the time it takes 
	clock_t start, end, total;
	start = clock();
	
	//check if the user input 3 arguments, program will exit if not
	if (argc != 3){
		if (argc > 3){
			printf("duplicate: Not enough arguments!\n");
			printf("usage: duplicate <sourcefile> <targetfile>\n");
		}
		else{
			printf("duplicate: Too many arguments!\n");
			printf("usage: duplicate <sourcefile> <targetfile>\n");
		}
	}
	
	//initialize sourceFile
	char *sourceFile;
	sourceFile = argv[1];
	
	//open file for reading
	FILE *source = fopen(sourceFile, "r");
	
	//initialize targetFile
	char *targetFile;
	targetFile = argv[2];
	
	//open file for writing
	FILE *target = fopen(targetFile, "w");
	
	//check if files actually exists
	if ((source == NULL) || (target == NULL)){
		printf("No such file\n");
		exit(-1);
	}
	
	//initialize character to be copied
	char c;	

	//use while loop in order to copy each character from source to target
	while ((c=getc(source))!=EOF){

		fputc(c, target);

		end = clock();
		int total = (int)(end-start)/CLOCKS_PER_SEC;
	
		//if running time is more than 1 sec, then the program will print message
		if(total >= 1){
			printf("\n\nduplicate: still duplicating...");
			sleep(1);
		}
	}

	//initialize size of file and print message
	long int size = ftell(source);
	printf("\n\nCopied %lu bytes to %s from %s\n", size, argv[2], argv[1]);

	return 0;
}
