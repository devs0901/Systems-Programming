
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

int main (int argc, char *argv[]){
    
    //initialize values
    int socket_desc , client_sock , c , read_size;
    struct sockaddr_in server , client;
    char buffer[256];
    
    //create socket 
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    
    //check if the socket has been created, if not:
    if (socket_desc == -1){
        printf("Could not create socket");
    }
    puts("Socket created");
    
    //prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8888 );
    
    //bind
    if ( bind (socket_desc,(struct sockaddr *) &server , sizeof(server)) < 0){
        //prints an error message
        perror("Bind Failed. Error");
        return 1;
    }
    puts("Bind done");
    
    //listen
    listen(socket_desc , 3);
    
    //accept and incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);
    
    //accept connection from an incoming client
    client_sock = accept(socket_desc, (struct sockaddr *) &client, (socklen_t*) &c);
    
    //check if the accept connection was accepted
    if (client_sock < 0){
        perror ("Accept failed");
        return 1;
    }
    puts("Connection accepted");

    int n, num1, num2, ans, choice;
    char operator;
        
    n=write(client_sock, "Enter nums: ", strlen("Enter nums"));
    if(n<0){
	puts("Error on writing to socket");
	return 1;
    }
    read(client_sock, &num1, sizeof(int));
    read(client_sock, &operator, sizeof(char));
    read(client_sock, &num2, sizeof(int));
    printf("Client - Entered values of nums are: %d %c %d\n", num1, operator, num2);
 
    if(operator == '+')
	ans = num1+num2;
    else if(operator == '-')
	ans = num1-num2;
    else if(operator == '*')
	ans = num1*num2;
    else if(operator == '/')
	ans = num1/num2;
    else
        printf("Not valid operator, cant calculate");

    printf("Answer is: %d\n", ans);

    write(client_sock, &ans, sizeof(int));

    if(read_size == 0){
        puts("Client disconnected");
        fflush(stdout);
    }
    
    else if (read_size == -1)
        perror("recv failed");
        
    return 0;
    
}
