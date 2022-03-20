#include<sys/socket.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

void str_cli(FILE *fp, int sockfd) {
	int bufsize = 1024, cont;
	char *buffer = malloc(bufsize);
	fputs("Me: ",stdout);
	while(fgets(buffer,bufsize,fp)!=NULL) {
		send(sockfd, buffer, bufsize,0);
		
		if((cont=recv(sockfd, buffer, bufsize,0))>0) {
			fputs("Server: ", stdout);
			fputs(buffer, stdout);
		}
		fputs("Me: ",stdout);
	}
	printf("EOF\n");
}

int main(int argc, char *argv[])
{
	int sockfd,fd;
	int busize = 1024;
	
	if((sockfd=socket(AF_INET, SOCK_STREAM, 0))>0)
		printf("socket created....\n");
	
	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_port = htons(15001);
	inet_pton(AF_INET, argv[1], &address.sin_addr);
	
	if(connect(sockfd, (struct sockaddr*)&address, sizeof(address))==0)
		printf("Connection successful...\n");
	
	str_cli(stdin, sockfd);
	
	return 0;
}
