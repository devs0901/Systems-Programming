/*

Jane Coralde | 100660214

Client and Server using TCP Implementation

Write a program with two parts: 1) a client, and 2) an arithmetic server. The job of the
client is to accept input from the keyboard and translate strings that you type into requests to the
arithmetic server. In other words, the client should translate strings such as "3 + 4" into a
request to the arithmetic server.

The format of the request packet sent by the client to the server is follows. Each packet
consists of three fields:
	● a three-character string representing the operation to be performed, i.e. "add",
"sub","div", and "mul"
	● the first integer
	● the second integer

Note that the size of each request packet (in bytes) will depend upon the representation
of characters and integers in the language you're using for this assignment. In C, a character is
represented in one byte and an integer in four bytes.
	
The server should parse each packet, extract the parameters of the request, perform the
requested operation and transmit the results to the client, which then prints out the results on
the screen. The arithmetic server should implement the procedures add; subtract; multiply; and
divide. Each of these procedures should accept two integers as input and return an integer as a
result. In addition, the divide procedure must detect an attempted "divide by zero" and return an
error code.

Each result packet must consist of two fields. The first field is an integer that takes the
values 0 or 1, where 1 represents a successful operation whereas 0 represents an unsuccessful
operation (e.g. divide by 0). The second field is an integer corresponding to the result of the
arithmetic operation or an error code representing the reason for the error. (For example, you
can use the integer 1 to represent "divide by zero".)

Complile and execute using:
	gcc client.c - client
	./client

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
