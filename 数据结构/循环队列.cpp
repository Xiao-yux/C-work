#include<stdio.h>
#define MAXSIZE 100
typedef int DataType;
typedef struct 
{
    DataType data[MAXSIZE];
    int front;
    int rear;  
}SeqQueue;

void InitQueue(SeqQueue *Q)
{
    Q->front=Q->rear=0;
}
int EmptyQueue(SeqQueue *Q)
{
    if (Q->front==Q->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int InQueue(SeqQueue *Q,DataType x)
{   /*入队函数*/
    if((Q->rear+1)%MAXSIZE==Q->front)
    {
        printf("队列满\n");
        return 0;
    }
    else
    {
        Q->data[Q->rear]=x;
        Q->rear=(Q->rear+1)%MAXSIZE;
        return 1;
    }
}

int DeQueue(SeqQueue *Q,DataType *x)
{   /*出队函数*/
    if(EmptyQueue(Q))
    {
        printf("队列空\n");
        return 0;
    }
    else
    {
        Q->front=(Q->front+1)%MAXSIZE;
        *x=Q->data[Q->front];
        return 1;
    }
}

int GetFront(SeqQueue *Q,DataType *x)
{   /*取队头元素*/
    if(EmptyQueue(Q))
    {
        printf("队列空\n");
        return 0;
    }
    else
    {
        *x=Q->data[(Q->front+1)%MAXSIZE];
        return 1;
    }
}

void ShowQueue(SeqQueue *Q)
{   /*显示队列*/
    int p=Q->front;
    if(p==Q->rear)
      printf("队列为空\n");
    else
    {
        printf("队列中的元素为：");
        while(p!=Q->rear)
        {
            printf("%5d  \n",Q->data[p]);
            p++;
        }
    }
}

int main()
{
    int i,n,flag;
    SeqQueue Q;
    DataType x;
    InitQueue(&Q);
    while (true)
    {
        printf("1.入队\n");
        printf("2.出队\n");
        printf("3.取队头元素\n");
        printf("4.显示队列\n");
        printf("5.退出\n");
        printf("\n\n\n刘演潮 202220105004\n");
        printf("请选择：");
        scanf("%d",&flag);
        switch (flag)
        {
        case 1:
            printf("请输入入队元素个数：");
            scanf("%d",&n);
            for (i=1;i<=n;i++)
            {
                printf("请输入第%d个元素：",i);
                scanf("%d",&x);
                InQueue(&Q,x);
            }
            break;
        case 2:
            DeQueue(&Q,&x);
            printf("出队元素为：%d\n",x);
            break;
        case 3:
            GetFront(&Q,&x);
            printf("队头元素为：%d\n",x);
            break;
        case 4:
            ShowQueue(&Q);
            break;
        case 5:
            return 0;
            break;
        default:
            printf("输入错误，请重新输入\n");
            break;
            
        }
    }
    
}
