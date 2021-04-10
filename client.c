#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include<netinet/in.h>

void chat_function(int network_socket) 
{ 
    char message[300]; 
    //int n; 
	//infinite for-loop
    for (int i=0;i>-1;i++) 
{ 
      //  bzero(buff, sizeof(buff)); 
        printf("Enter the message: "); 
       // n = 0; 
	int size=0;
        while ((message[size++] = getchar()) != '\n') 
             ; 
        write(network_socket,message, sizeof(message)); 
       // bzero(buff, sizeof(buff)); 
        read(network_socket, message, sizeof(message)); 
        printf("From Server : %s", message); 
        if ((strcmp(message, "close")) == 0) 
	{ 
            printf("Client has decided to exit\n"); 
            break; 
        }
    } 
} 
  
int main() 
{ 
    int network_socket, connection; 
    struct sockaddr_in servaddr, cli; 
  
    // Creating a socket
	int  network_socket;
	network_socket	= socket(AF_INET, SOCK_STREAM, 0); 
    if (network_socket == -1) { 
        printf("Socket could not be created\n"); 
        exit(0); 
    } 
    else
        printf("Socket has been created successfully\n"); 
   // bzero(&servaddr, sizeof(servaddr)); 
  
    // Assigning IP address and port number
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    servaddr.sin_port = htons(9000); 
  
    // Connection between client and server socket
int connection=connect(network_socket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
    if (connection != 0) { 
        printf("Server could not be connected\n"); 
        exit(0); 
    } 
    else
        printf("Client and server are connected\n"); 
  
    // function for chat between client and server
    chat_function(network_socket); 
  
    // Closing the socket
    close(network_socket); 
} 
