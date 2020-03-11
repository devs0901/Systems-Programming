
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
