#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct EdgeNode {
    int adjvex;              
    struct EdgeNode *next;   
} EdgeNode;

typedef struct VHeadNode {
    char data;              
    EdgeNode *firstedge;    
} VHeadNode;

typedef struct {
    VHeadNode adjlist[MAX]; 
    int n, e;               
} AdjList;

void CreateAGraph(AdjList *g, int flag) {
    int i, j, k;
    EdgeNode *p;

    if (flag == 0)
        printf("\n将建立一个无向图。\n");
    else
        printf("\n将建立一个有向图。\n");

    printf("请输入图的顶点数：");
    scanf("%d", &g->n);

    printf("请输入图的边数：");
    scanf("%d", &g->e);

    printf("\n请输入图的各顶点信息：\n");
    for (i = 0; i < g->n; i++) {
        printf("第%d个顶点信息：", i + 1);
        scanf("\n%c", &(g->adjlist[i].data));
        g->adjlist[i].firstedge = NULL;
    }

    printf("\n请输入边的信息，输入格式为：序号1，序号2（序号依次为0、1、2...):\n");
    for (k = 0; k < g->e; k++) {
        printf("请输入第%d条边：", k);
        scanf("\n%d,%d", &i, &j);

        p = (EdgeNode *)malloc(sizeof(EdgeNode));
        p->adjvex = j;
        p->next = g->adjlist[i].firstedge;
        g->adjlist[i].firstedge = p;

        if (flag == 0) {
            p = (EdgeNode *)malloc(sizeof(EdgeNode));
            p->adjvex = i;
            p->next = g->adjlist[j].firstedge;
            g->adjlist[j].firstedge = p;
        }
    }
}

void PrintGraph(AdjList *g) {
    int i;
    EdgeNode *p;
    printf("\n邻接表内容如下：\n");
    for (i = 0; i < g->n; i++) {
        printf("%d(%c):", i, g->adjlist[i].data);

        p = g->adjlist[i].firstedge;
        while (p) {
            printf("->%d", p->adjvex);
            p = p->next;
        }

        printf("->NULL\n");
    }
}

int main() {
    AdjList G;
    int flag;
    printf("刘演潮 202220105004\n"); 
    printf("请输入图的类型，无向图输入0，有向图输入1：");
    scanf("%d", &flag);
    CreateAGraph(&G, flag);
    PrintGraph(&G);
    return 0;
}
