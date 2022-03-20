#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
	int sockfd, cont;
	char fname[255];
	int bufsize = 1024;
	char *buffer = malloc(bufsize);
	if((sockfd=socket(AF_INET, SOCK_STREAM, 0))>0)
		printf("socket created...\n");
		
	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_port = htons(15001);
	inet_pton(AF_INET, argv[1], &address.sin_addr);
	if(connect(sockfd, (struct sockaddr*)&address, sizeof(address)) == 0)
		printf("connected to server .....\n");
	
	printf("enter filename\n");
	scanf("%s",&fname);
	
	send(sockfd, fname, 255,0);
	
	while((cont = recv(sockfd, buffer, bufsize,0)) > 0)
	{
		write(1,buffer,bufsize);
	}
	printf("\nEOF\n");
	return close(sockfd);
}
