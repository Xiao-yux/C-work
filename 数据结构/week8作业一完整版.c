/* 顺序栈操作 */
#include "stdio.h"
#define  MAXLEN  100             /*顺序栈存储空间的总分配量*/
typedef  int  DataType;          /*定义DataType为int类型*/ 
typedef  struct                  /*顺序栈存储类型*/
{   DataType   data[MAXLEN];     /*存放顺序栈的数组*/
    int  top;                    /*记录栈顶元素位置的变量*/
}SeqStack;

void  InitStack( SeqStack  *S )
{   /*初始化栈函数*/
    S->top=-1;               /*初始化的顺序栈为空*/
}

int EmptyStack(SeqStack *S)
{   /*判断栈空函数*/
    if(S->top==-1)               /*栈为空*/
        return 1;
    else
        return 0;
}

int FullStack(SeqStack *S)
{   /*判断栈满函数*/
    if(S->top==MAXLEN-1)               /*栈为满*/
        return 1;
    else
        return 0;
}

int Push(SeqStack *S,DataType x)
{   /*进栈操作函数*/
    if(FullStack(S))      /*调用判满函数FullStack(S)，判断栈是否为满*/
    {   printf("栈满，不能进栈!");
        return 0;                /*栈满不能进栈*/
    }
    else                          /*栈不为满*/
    {   S->top++;
        S->data[S->top]=x;
        return 1;
    }
}

int Pop(SeqStack *S,DataType *x)
{   /*出栈操作函数*/
    if(EmptyStack(S))     /*调用判空函数EmptyStack(S)，判断栈是否为空*/
    {   printf("栈空，不能出栈!");
        return 0;              /*栈空不能出栈*/
    }
    else                        /*栈不为空*/
    {   *x=S->data[S->top];
        S->top--;
        return 1;
    }
}

int GetTop(SeqStack *S,DataType *x)
{   /*取栈顶元素函数*/
    if(EmptyStack(S))    /*调用判空函数EmptyStack(S)，判断栈是否为空*/
    {   printf("栈空，取栈顶元素失败!");
        return 0;
    }
    else                   /*栈不为空*/
    {   *x=S->data[S->top];
        return 1;
    }
}

void  Menu()                                    
{   /*显示菜单子函数*/
	printf("\n                  顺序栈的各种操作");
    printf("\n==================================================");  
    printf("\n|               1——初始化栈                    |");
    printf("\n|               2——入栈操作                    |");
    printf("\n|               3——出栈操作                    |");
    printf("\n|               4——求栈顶元素                  |");
    printf("\n|               5——10进制数转换为2进制          |");
    printf("\n|               0——返回                        |");
    printf("\n================刘演潮 202220105004================"); 
    printf("\n请输入菜单号（0-4）:"); 	
}

void decimalToBinary(int num) {
   int temp = num;
   int result[100];
   int i = 0;
   while (temp > 0) {
       result[i++] = temp % 2;
       temp /= 2;
   }
   printf("%d的二进制表示为：", num);
   for (int j = i - 1; j >= 0; j--) {
       printf("%d", result[j]);
   }
   printf("\n");
}


int main()
{
   int i,n,flag;
   SeqStack S;
   DataType x;
   int aa;
   char  ch1,ch2,a;
   ch1='y';
   while(ch1=='y'||ch1=='Y') 
   {  Menu();
   	  scanf("%c",&ch2);
   	  getchar();
   	  switch(ch2)
   	  {
   	  	 case  '1':   	  	 
             InitStack(&S);
             printf("栈的初始化完成！");
             break;
         case  '2':
             printf("请输入要入栈的元素个数：");
             scanf("%d",&n);
             printf("请输入%d个入栈的整数：",n); 
             for(i=0;i<n;i++)
             {   
             	 scanf("%d",&x);
             	 flag=Push(&S,x);
             }
             if(flag==1)
                printf("入栈成功！");
             break;
         case  '3':
             printf("请输入要出栈的元素个数：");
             scanf("%d",&n);
             printf("出栈的元素为："); 
             for(i=0;i<n;i++)
             {   
             	 flag=Pop(&S,&x);
             	 printf("%5d",x);
             }
             if(flag==1)
                 printf("\n出栈成功!");
             else
                 printf("出栈失败！");
             break;
         case  '4':
             if(flag=GetTop(&S,&x))
                 printf("当前的栈顶元素值为：%d",x);
             break;
         case  '5':
             
             printf("请输入10进制数：");
             scanf("%d",&aa);
             decimalToBinary(aa);
            break;
         case  '0':
             ch1='n';break;
         default:
             printf("输入有误，请输入0-4进行选择！");
   	  }
   	  if(ch2!='0')
   	  {   printf("\n按回车键继续，按任意键返回主菜单！\n");
   	  	  a=getchar();
   	  	  if(a!='\xA')
   	  	  {
   	  	  	 getchar();ch1='n';
   	  	  }
   	  }
   }
}
