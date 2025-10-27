#include<stdio.h>
#include<stdlib.h>

typedef int DataType;

typedef struct qnode
{
   DataType data;
   struct qnode *next;
} LinkListQ;

typedef struct
{
   LinkListQ *front,*rear;
} LinkQueue;

LinkQueue *InitQueue()
{
   LinkQueue *Q;
   LinkListQ *p;
   Q = (LinkQueue *)malloc(sizeof(LinkQueue));
   p = (LinkListQ *)malloc(sizeof(LinkListQ));
   Q->front = p;
   Q->rear = p;
   return Q;
}

int EmptyQueue(LinkQueue *Q)
{
   if(Q->front==Q->rear)
       return 1;
   else
       return 0;
}

void InQueue(LinkQueue *Q,DataType x)
{
   LinkListQ *p;
   p = (LinkListQ *)malloc(sizeof(LinkListQ));
   p->data = x;
   p->next = NULL;
   Q->rear->next = p;
   Q->rear = p;
}

int DeQueue(LinkQueue *Q,DataType *x)
{
   LinkListQ *p;
   if(EmptyQueue(Q))
   {
       printf("队空，不能让出元素!\n");
       return 0;
   }
   else
   {
       p = Q->front->next;
       *x = p->data;
       Q->front->next = p->next;
       if(p->next==NULL)
           Q->rear = Q->front;
       free(p);
       return 1;
   }
}

int GetFront(LinkQueue *Q,DataType *x)
{
   if(EmptyQueue(Q))
   {
       printf("队空，不能获得队头元素!\n");
       return 0;
   }
   else
   {
       *x = Q->front->next->data;
       return 1;
   }
}

int main()
{
   LinkListQ *p;
   LinkQueue *Q;
   DataType x;
   int ch;
   while(1)
   {
       printf("1.初始化队列\n");
       printf("2.入队列\n");
       printf("3.出队列\n");
       printf("4.获得队头元素\n");
       printf("5.判断队列是否为空\n");
       printf("6.退出\n");
       printf("刘演潮 202220105004\n");
       printf("请输入你的选择：\n");
       scanf("%d", &ch);
       switch(ch)
       {
           case 1:
               Q = InitQueue();
               break;
           case 2:
               printf("请输入一个数：\n");
               scanf("%d", &x);
               InQueue(Q, x);
               break;
           case 3:
               if(DeQueue(Q, &x))
                   printf("出队列的元素是：%d\n\n", x);
               break;
           case 4:
               if(GetFront(Q, &x))
                   printf("队头元素是：%d\n\n", x);
               break;
           case 5:
               if(EmptyQueue(Q))
                   printf("队列为空！\n");
               else
                   printf("队列不为空！\n");
               break;
           case 6:
               exit(0);
           default:
               printf("输入错误！\n");
               break;
       }
   }
   return 0;
}
