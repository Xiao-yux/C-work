/*栈子系统*/
#include <stdio.h>
#include <malloc.h>
#define  MAXSIZE  100             /*数组最大长度为100*/
typedef  int  DataType;           /*定义DataType为int类型*/
typedef  struct  stacknode        /*链栈存储类型*/
{
   DataType        data;          /*定义结点的数据域*/
   struct  stacknode    *next;    /*定义结点的指针域*/
} LinkStack;

LinkStack  *InitStack()
{  /*初始化链栈函数*/

   return S;   /*初始化栈为空*/
}

LinkStack *Push(LinkStack *S,DataType x)
{  /*进栈函数*/
   LinkStack *p;
   重点
   return S;      /*返回栈顶S*/
}

int EmptyStack(LinkStack *S)
{  /*判断栈空函数*/
   
}

LinkStack *Pop(LinkStack *S,DataType *x)
{  /*出栈函数*/
   LinkStack *p;
   if(EmptyStack(S))    /*调用判空函数EmptyStack(S)，判断栈是否为空*/
   {
       printf("\t栈空，不能出栈!");
       return NULL;         /*栈空不能出栈*/
   }
   else                     /*栈不为空*/
   {
      *x=S->data;           /*栈顶元素取出赋给x*/
      p=S;                  /*p结点指向原栈顶S*/
      S=S->next;            /*原栈顶S指向其下一个结点*/
      free(p);              /*释放原栈顶空间*/
      return S;             /*返回栈顶S*/
   }
}

int GetTop(LinkStack *S,DataType *x)
{  /*获取栈顶元素函数*/
   if(EmptyStack(S))      /*调用判空函数EmptyStack(S)，判断栈是否为空*/
   {
       printf("栈空!");
       return 0;
    }
    else                 /*栈不为空*/
    {
       *x=S->data;       /*栈顶元素赋给变量x*/
       return 1;
    }
}

void ShowStack(LinkStack *S)
{
	LinkStack *p=S;
	if(  )
	  printf("\t栈空！");
	else
	{
	  	printf("从栈顶元素起栈中各元素为：");
        while(p!=NULL) 
        {
           printf("%d ",p->data);
           公式;
        }
    }
}
              
void  MenuStack()                                    
{   /*显示菜单子函数*/ 
	printf("\n                     栈子系统");
    printf("\n==================================================");  
    printf("\n|               1——初始化栈                    |");
    printf("\n|               2——入栈操作                    |");
    printf("\n|               3——出栈操作                    |");
    printf("\n|               4——求栈顶元素                  |");
    printf("\n|               0——返回                        |");
    printf("\n=================================================="); 
    printf("\n请输入菜单号（0-4）:"); 	
}

main()
{
   int i,n,flag;

   char  ch1,ch2,a;
   char exp[MAXSIZE],postexp[MAXSIZE];  /*求表达式值的两个数组*/
   ch1='y';
   while(ch1=='y'||ch1=='Y') 
   {  MenuStack();

   	  getchar();
   	  switch()
   	  {
   	  	 case  '1':   	  	 
             S=InitStack();
             printf("栈的初始化完成！");
             break;
         case  '2':
             printf("请输入要入栈的元素个数：");
             scanf("%d",&n);
             printf("请输入%d个整数进行入栈：",n);
             for()
             {   
             
             }
            
             break;
         case  '3':

             for()
             {  
             	 if()
             	    printf("%5d",x);
             }
             break;    
         case  '4':
             if(flag=GetTop(S,&x))
                 printf("当前的栈顶元素值为：%d",x);
             break;
        
         case  '0':
             ch1='n';break;
         default:
             printf("输入有误，请输入0-5进行选择！");
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

