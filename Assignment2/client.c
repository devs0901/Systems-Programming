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

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main (int argc, char *argv[]){
    
    //initialize socket and portno and n
    int sock;
    struct sockaddr_in server;
    char buffer[256];
    
    //create socket 
    sock = socket(AF_INET , SOCK_STREAM , 0);
    
    //check if the socket has been created, if not:
    if (sock == -1){
        printf("Could not create socket");
    }
    puts("Socket created");
    
    //prepare the sockaddr_in structure
    server.sin_addr.s_addr = inet_addr("127.0.0.11"); 
    server.sin_family = AF_INET;
    server.sin_port = htons( 8888 );
    
    //Connect to remote server
    if (connect(sock , (struct sockaddr *)  &server , sizeof(server)) < 0){
        perror("Connect failed. Error");
        return 1;
    }
    puts("Connected\n");

    //Once connection is settled, the program is ready
    printf("Welcome to Calculator Model\nEnter values in this format <number> <operator> <number>\n\n");
    int n, num1, num2, ans;
    char operator;

         bzero(buffer, 256);
	 printf("Enter: ");
    	 n=read(sock, buffer ,255);
	 if (n<0){
	     perror("Socket connect failed. Error");
	     return 1;
	 }
    	 scanf("%d %c %d", &num1, &operator, &num2);
    	 write(sock, &num1, sizeof(num1));
	 write(sock, &operator, sizeof(operator));
    	 write(sock, &num2, sizeof(num1));
  
    read(sock,&ans,sizeof(int));
    printf("Answer: %d\n", ans);
 
    pclose;
    return 0;
}
