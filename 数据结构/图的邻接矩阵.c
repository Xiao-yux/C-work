#include<stdio.h>
#define MAX 100
typedef struct 
{ int n,e;
  char vexs[MAX];
  int edges[MAX][MAX];
}MGraph;

void CreateMGraph(MGraph *G)
{
	int i,j,k;
    char ch1,ch2;
	printf("请输入顶点数和边数: ");
	scanf("%d",&G->n);
	printf("请输入顶点: ");
    scanf("%d",&G->e);
    printf("请输入各顶点信息（每个顶点以回车作为结束): \n");
	for(i=0;i<G->n;i++)
    {   getchar();
        printf("请输入第%d个顶点: ",i+1);
		scanf("%c",&(G->vexs[i]));
    }
	for(i=0;i<G->n;i++)
		for(j=0;j<G->n;j++)
			G->edges[i][j]=0;
	for(k=0;k<G->e;k++)
	{   getchar();
		printf("建立第%d条边(输入格式:顶点1，顶点2): ",k+1);
		scanf("%c,%c",&ch1,&ch2);
		for(i=0;i<G->n;i++)
          for (j=0;j<G->n;j++)
            if (ch1==G->vexs[i]&&ch2==G->vexs[j])
            {
                G->edges[i][j]=1;
                G->edges[j][i]=1;
            }
    }   
 }
void DispMGraph(MGraph G)
{
    int i,j;
    printf("\n图的邻接矩阵: \n");
    for(i=0;i<G.n;i++)
    {
        for(j=0;j<G.n;j++)
            printf("%5d",G.edges[i][j]);
        printf("\n");
    }
    printf("202220105004 刘演潮\n");
}
int main()
{
	MGraph G;
	CreateMGraph(&G);
	DispMGraph(G);
	return 0;
}
