
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void main(){

  int sockfd;
  struct sockaddr_in si_me, si_other;
  socklen_t addr_size;

  //create socket
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  
  if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        //prints an error message
        puts("Socket creation failed. Error\n");
        return 1;
  }puts("Socket creation done\n");


  memset(&si_me, 0, sizeof(si_me));
  memset(&si_other, 0, sizeof(si_other));

  si_me.sin_family = AF_INET;
  si_me.sin_addr.s_addr = inet_addr("127.0.0.1");
  si_me.sin_port = htons( 8888 );

  //bind
  if ( bind (sockfd,(struct sockaddr *) &si_me , sizeof(si_me)) < 0){
        //prints an error message
        puts("Bind failed. Error\n");
        return 1;
  }
  puts("Bind done\n");

  //send and receive data
  int n, num1;
  
	n = recvfrom(sockfd, &num1, sizeof(num1), 0, (struct sockaddr*) &si_other, &addr_size);
	if (n < 0){
	  puts("Receiving failed");
	  return 1;
	}

	printf("[+]Data Received: %d\n", num1);

	n = sendto(sockfd, &num1, sizeof(num1), 0, (struct sockaddr*)&si_other, &addr_size);
	if (n < 0){
	  puts("Sending failed");
	  return 1;
	}

	printf("Data Sent\n");
  
}
