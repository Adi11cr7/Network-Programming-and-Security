#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<arpa/inet.h>

int main()
{
	int sockfd,new_socket, cont,fd;
	int bufsize = 1024;
	char *buffer = malloc(bufsize);
	char fname[255];
	struct sockaddr_in address, client;
	
	if((sockfd=socket(AF_INET, SOCK_STREAM,0))>0)
		printf("socket was created\n");
		
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = htonl(INADDR_ANY);
	address.sin_port = htons(15001);
	
	if(bind(sockfd, (struct sockaddr*)&address, sizeof(address))==0)
		printf("socket binded to address\n");
	
	listen(sockfd,3);
	int addrlen = sizeof(struct sockaddr_in);
	if((new_socket=accept(sockfd, (struct sockaddr*)&client, &addrlen))>0)
		printf("connection accepted by server\n");
	
	 recv(new_socket,fname,255,0);
	 printf("A request for filename %s received....\n",fname);
	 
	 if((fd=open(fname,O_RDONLY))<0) {
	 	perror("File open failed\n");
	 	exit(0);
	 }
	 
	 while((cont=read(fd, buffer, bufsize))>0) {
	 	send(new_socket, buffer, bufsize, 0);
	 }
	 printf("Request completed\n");
	 close(new_socket);
	 return close(sockfd);
	}
	 
