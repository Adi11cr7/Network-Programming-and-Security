#include<stdio.h>

int A[10][10],n,d[10],p[10];

void BellmanFord(int s) {
	int i,u,v;
	for(i=1;i<n;i++) {
		for(u=0; u<n; u++) {
			for(v=0; v<n; v++) {
				if(d[v] > d[u] + A[u][v]) {
					d[v] = d[u] + A[u][v];
					p[v] = u;
				}
			}
		}
	}
	
	for(u=0; u<n; u++) {
		for(v=0; v<n; v++) {
			if(d[v] > d[u] + A[u][v])
				printf("Negative cycle detected\n");
		}
	}
	
}

int main()
{
	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	
	printf("\nEnter the adjacency matrix\n");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&A[i][j]);
		
	for(int source=0; source<n; source++) {
		
		for(int i=0;i<n;i++) {
			d[i] = 999;
			p[i] = -1;
		}
		
		d[source] = 0;
		
		BellmanFord(source);
		printf("------Router %d--------\n",source);
		int j=0;
		for(int i = 0; i<n; i++) {
			if(i!=source) {
				j=i;
				while(p[j] != -1) {
					printf("%d<-", j);
					j = p[j];
				}
				
				printf("%d\t cost %d\n\n",source, d[i]); 
			}
		}
	}
		return 0;
}
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
					
		
				
