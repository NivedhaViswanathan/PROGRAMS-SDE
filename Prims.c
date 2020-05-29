#include<stdio.h>
#include<stdlib.h>
int a,b,n,i,j,ne=1,min,mincost=0;
int visited[10]={0},cost[10][10];
void main(){
	printf("Number of Nodes:");
	scanf("%d",&n);
	printf("\nAdjacency Matrix:");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}
	visited[1]=1;
	printf("\n");
	while(ne<n){
		for(i=1,min=999;i<=n;i++)
			for(j=1;j<=n;j++)
				if(cost[i][j]<min){
					min=cost[i][j];
					a=i;
					b=j;
				}
				if(visited[a]==0 ||visited[b]==0){
					printf("\nEdge %d:(%d %d)cost: %d",ne++,a,b,min);
					mincost+=min;
					visited[b]=1;
				}
				cost[a][b]=cost[b][a]=999;
		}
		printf("\nMinimum Cost=%d",mincost);
	}
