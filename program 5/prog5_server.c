#include<sys/socket.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>

void str_echo(int connfd)
{
	int n;
	int bufsize = 1024;
	char *buffer = malloc(bufsize);
	
	while((n=recv(connfd, buffer, bufsize,0))>0) {
		fputs("Client: ", stdout);
		fputs(buffer, stdout);
		fputs("Me :", stdout);
		
		if(fgets(buffer, bufsize, stdin) != NULL) {
			send(connfd, buffer, bufsize,0);
		}
		bzero(buffer, bufsize);
	}
}

int main()
{
	int listenfd, connfd,addrlen,addrlen1,pid;
	struct sockaddr_in address, client;
	
	if((listenfd = socket(AF_INET, SOCK_STREAM, 0))>0)
		printf("Socket created....\n");
	
	address.sin_family = AF_INET;
	address.sin_port = htons(15001);
	address.sin_addr.s_addr = INADDR_ANY;
	
	if(bind(listenfd, (struct sockaddr*)&address, sizeof(address)) == 0)
		printf("Binding socket....\n");
	
	printf("The address after bind is %s....\n",inet_ntoa(address.sin_addr));
	
	listen(listenfd, 3);
	printf("Server is listening....\n");
	
	getsockname(listenfd, (struct sockaddr*)&address, &addrlen);
	printf("The server's local address is: %s and port: %d \n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
	

	for(;;) {
		connfd = accept(listenfd, (struct sockaddr*)&client, &addrlen1);
		getpeername(connfd, (struct sockaddr*)&client, &addrlen1);
		printf("Client address: %s and port %d..\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
		
		if((pid=fork())==0) {
			printf("inside child\n");
			close(listenfd);
			str_echo(connfd);
		}
		close(connfd);
	}
	return 0;
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
