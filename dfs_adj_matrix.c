#include<stdio.h>
#include<malloc.h>
#include<string.h>
int *vis;
int cols=100;
void dfs(int (*)[100],int vertices,int start);
int main()
{
    int edges;
    int vertices;
    printf("Enter No of Vertices\n");
    scanf("%d",&vertices);
    printf("Enter No of Edges\n");
    scanf("%d",&edges);
    int mat[vertices][cols];
    memset(mat,0,vertices*cols*sizeof(int));
    char type[5];///directed or undirected
    printf("Enter \'dire\' for directed graph or \'undire\' for undirected graph\n");
    fflush(stdin);
    scanf("%s",type);
    for(int i=0;i<edges;i++)
    {
        int u,v;
        //Scanning the input
        scanf("%d %d",&u,&v);
        if(strcmp(type,"dire")==0 || strcmp(type,"Dire")==0)
        {
            printf("Directed Graph....\n");
            mat[u][v]+=1;
        }
        else if(strcmp(type,"undire")==0 || strcmp(type,"Undire")==0 || strcmp(type,"udire")==0 ||strcmp(type,"Udire")==0)
        {
            printf("Undirected Graph....\n");
            mat[u][v]+=1;
            mat[v][u]+=1;
        }
    }
    ///Adjacency Matrix
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    int start;
    printf("Give Starting Node\n");
    scanf("%d",&start);
    vis=(int*)malloc(vertices*sizeof(int));
    memset(vis,0,vertices*sizeof(int));
    printf("DFS RESULT\n");
    dfs(mat,vertices,start);
}
void dfs(int (*mat)[100],int vertices,int start)
{
    vis[start]=1;
    printf("%d\n",start);
    for(int i=0;i<vertices;i++)
    {
        if(mat[start][i]==1 && !vis[i])
        {
            dfs(mat,vertices,i);
        }
    }
}
