#include<stdio.h>

unsigned fields[10];

unsigned short checksum()
{
	int sum=0;
	
	printf("enter 16 bit IP header\n");
	for(int i=0; i<4; i++) {
		scanf("%x",&fields[i]);
		sum += (unsigned short)fields[i];
	}
	while(sum >> 16)
		sum = (sum&0xFFFF) + (sum>>16);
	
	sum = ~sum;
	return (unsigned short)sum;
}

int main()
{
	unsigned short result1, result2;
	
	result1 = checksum();
	
	printf("checksum recieved\n");
	printf("%x\n",result1);
	
	result2 = checksum();
	printf("computed checksum at receiver\n");
	printf("%x\n",result2);
	
	if(result1 == result2) printf("No error\n");
	else printf("Error in data recieved\n");
	
	return 0;
}
	
