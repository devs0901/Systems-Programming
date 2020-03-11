/*

Jane Coralde | 100660214

Client and Server using UDP Implementation

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
	gcc UDPClient.c - UDPClient
	./UDPClient

Note that the code is not finished and does not fully work

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void main(){

  int sockfd;
  struct sockaddr_in serverAddr;
  char buffer[1024];
  socklen_t addr_size;

  //create socket
  sockfd = socket(PF_INET, SOCK_DGRAM, 0);
  memset(&serverAddr, '\0', sizeof(serverAddr));

  //fill server info
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons( 8888 );
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  //send and receive data recvfrom() andd sendto()
  int num1, num2, ans;
  char operator;

  printf("Welcome to Calculator Model\nEnter values in this format <number> <operator> <number>\n");
  printf("Enter: ");
  scanf("%d %c %d\n", &num1, &operator, &num2);
  
  sendto(sockfd, num1, sizeof(num1), 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
  
  recvfrom(sockfd, &num1, sizeof(num1), 0, (struct sockaddr*) &serverAddr, &serverAddr);
  printf("Num 1 Sent: %d\n", num1);

  close(sockfd);
  return 0;

}
