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
