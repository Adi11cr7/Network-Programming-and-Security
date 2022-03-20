#include<stdio.h>

int main()
{
	int a[4],b[4],r[3],c[7],s[3];
	
	printf("Enter 4 bit word\n");
	for(int i=3;i>=0;i--)
		scanf("%d",&a[i]);
	
	r[0] = (a[0] + a[1] + a[3])%2;
	r[1] = (a[0] + a[2] + a[3])%2;
	r[2] = (a[1] + a[2] + a[3])%2;
	
	printf("7 bit hamming code:\n");
	printf("%d %d %d %d %d %d %d \n",a[3],a[2],a[1],r[2],a[0],r[1],r[0]);
	
	printf("Enter 7 bit recieved code word\n");
	for(int i=7; i>0; i--)
		scanf("%d",&c[i]);
		
	b[3] = c[7];
	b[2] = c[6];
	b[1] = c[5];
	b[0] = c[3];
	
	r[2] = c[4];
	r[1] = c[2];
	r[0] = c[1];
		
	s[0] = (b[3] + b[1] + b[0] + r[0])%2;
	s[1] = (b[0] + b[2] + b[3] + r[1])%2;
	s[2] = (b[1] + b[2] + b[3] + r[2])%2;
	
	printf("Syndrome is:\n");
	printf("%d%d%d\n",s[2],s[1],s[0]);
	
	int pos = s[0] + s[1]*2 + s[2]*4;
	
	if(pos == 0)
		printf("No error\n");
	
	else {
		printf("Error detected at bit %d\n",pos);
		
		c[pos] = !c[pos];
		printf("corrected message is:\n");
		for(int i=7; i>0; i--)
			printf("%d ",c[i]);
		printf("\n");
	}
	
	return 0;
}
	
