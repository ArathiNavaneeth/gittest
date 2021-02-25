#include<stdio.h>
#include<conio.h>

int i,j,g[9][9],n,ne=1,sv,dist[9]={0};

int minima(int a,int b)
{
  return (a<b)?a:b;
}

void dj(int g[9][9],int n,int sv)
{
  int selected[10],k,u,w;
  for(k=1;k<=n;k++)
  {
    selected[k]=0;
    dist[k]=g[sv][k];
  }
  selected[sv]=1;
  dist[sv]=0;
  for(k=1;k<=n;k++)
  {
    u=minnode(dist,n,selected);
    selected[u]=1;
    for(w=1;w<=n;w++)
    {
     if(selected[w]==0)
     {
      dist[w]=minima(dist[w],dist[u]+g[u][w]);
     }
    }
  }
}

int minnode(int dist[],int n,int selected[])
{
  int k,min=9999,index=0;
  for(k=1;k<=n;k++)

   if(dist[k]<min && selected[k]==0)
   {
     min=dist[k];
     index=k;
   }
   return index;

}

void main()
 {
 int w;
 //clrscr();
 printf("\tImplementation of Dijikstra algorithm\n");
 printf("\nEnter the no. of vertices:");
 scanf("%d",&n);
 printf("\nEnter the cost adjacency matrix:\n");
 for(i=1;i<=n;i++)
 {
 for(j=1;j<=n;j++)
 {
 scanf("%d",&g[i][j]);
 if(g[i][j]==0)
 {
  g[i][j]=9999;
 }
 }
 }
  printf("Enter source vertex::");
  scanf("%d",&sv);
  dj(g,n,sv);
  w=1;
  for(i=1;i<=n;i++)
  {
    printf("\n From node %d to %d :: %d",sv,w,dist[i]);
    w++;
  }
  getch();
}

