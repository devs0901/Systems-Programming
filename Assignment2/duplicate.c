
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
