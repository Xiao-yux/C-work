/*栈子系统*/
#include <stdio.h>
#include <malloc.h>
#define  MAXSIZE  100             /*数组最大长度为100*/
typedef  int  DataType;           /*定义DataType为int类型*/
typedef  struct  qnode        /*链栈存储类型*/
{
   DataType data;          /*定义结点的数据域*/
   struct  qnode    *next;    /*定义结点的指针域*/
} LinkListQ;

typedef struct linkstack
{
    /* data */
};


LinkStack  *InitStack()
{  /*初始化链栈函数*/
   LinkStack *S;
   S=NULL;
   return S;   /*初始化栈为空*/
}

int EmptyStack(LinkStack *S)
{  /*判断栈空函数*/
   if(S==NULL)           /*栈为空*/
      return 1;
   else
      return 0;
}

LinkStack *Push(LinkStack *S,DataType x)
{  /*进栈函数*/
   LinkStack *p;
   p=(LinkStack *)malloc(sizeof(LinkStack));/*生成新结点*/
   p->data=x;     /*将x放入新结点的数据域*/
   p->next=S;     /*将新结点插入链表表头之前*/
   S=p;           /*新结点作为栈顶*/
   return S;      /*返回栈顶S*/
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
	if(p==NULL)
	  printf("\t栈空！");
	else
	{
	  	printf("从栈顶元素起栈中各元素为：");
        while(p!=NULL) 
        {
           printf("%d ",p->data);
           p=p->next;
        }
    }
}

void D_B(LinkStack *S,DataType x)
{
  while(x)
  {
    S=Push(S,x%2);      /*余数入栈*/
    x/=2;             /*被除数data整除以2，得到新的被除数*/
  }
  printf("转换后的二进制为：");
  while (!EmptyStack(S))
  {                     
        S=Pop(S,&x);      /*依次从栈中弹出每一个余数并输出*/
        printf("%d",x);
  }
}

void trans(char *exp,char *postexp)
{   /*将中缀表达式转换成后缀表达式函数*/
    struct
    {
        char data[MAXSIZE];
        int top;
    } op;    /*运算符栈*/
    int i=0;
    op.top=-1;
    while(*exp!='#')   /*当表达式没结束时*/
    {
        switch(*exp)    /*判断表达式的每个字符*/
        {
            case '(':   /*当字符为'('时*/
                op.top++;op.data[op.top]=*exp;   /*栈顶指针增1，运算符入栈*/
                exp++;   /*中缀表达式指针增1*/
                break;
            case ')':   /*当字符为')'时*/
                while(op.data[op.top]!='(')   /*只要运算符栈顶元素不是'('时*/
                {
                    postexp[i++]=op.data[op.top];  /*将栈顶运算符写入后缀表达式数组中*/
                    op.top--;   /*栈顶指针减1*/
                }            
                op.top--;exp++; /*栈顶指针减1，表达式指针加1*/
                break;    
            case '+':
            case '-':
                while(op.top!=-1&&op.data[op.top]!='(')  /*运算符栈不为空且栈顶元素不为'('时*/
                {
                    postexp[i++]=op.data[op.top];  /*将栈顶运算符写入后缀表达式数组中*/
                    op.top--;   /*运算符栈顶指针减1*/
                }        
                op.top++;  /*运算符栈顶指针加1*/
                op.data[op.top]=*exp;  /*将中缀表达式元素入符号栈*/
                exp++; /*中缀表达式指针加1*/
                break;
            case '*':
            case '/':
                while(op.data[op.top]=='*'||op.data[op.top]=='/') /*当栈顶元素不是'*'和'/'时*/
                {
                    postexp[i++]=op.data[op.top];  /*栈顶运算符写到后缀表达式数组中*/
                    op.top--;   /*栈顶指针减1*/
                } 
                op.top++;/*栈顶指针加1*/
                op.data[op.top]=*exp; /*中缀表达式的元素入栈*/
                exp++; /*表达式指针加1*/
                break;
            case ' ':break;
            default:
                while(*exp>='0'&&*exp<='9') /*当表达式对象是数字时*/
                {
                    postexp[i++]=*exp;   /*将数字写到后缀表达式数组中*/
                    exp++;  /*中缀指针加1*/
                }     
                postexp[i++]='#';  /*将每个操作数之间增加分隔符'#'*/
        }    
    }   
    while(op.top!=-1)  /*当运算符栈不为空时*/
    {
        postexp[i++]=op.data[op.top];  /*将栈顶运算符写入后缀表达式数组中*/
        op.top--;    /*栈顶指针减1*/
    }   
    postexp[i]='\0';  /*为后缀表达式加一个结束标志*/
}   

float compvalue(char *postexp)
{   /*根据后缀表达式求值函数*/
    struct
    {
        float data[MAXSIZE];
        int top;
    } st; /*数栈结点类型*/
    float a,b,c,d;
    st.top=-1;   /*栈顶指针赋初值-1*/
    while(*postexp!='\0')  /*当后缀表达式没结束时*/
    {
        switch(*postexp) 
        {
            case '+':
                a=st.data[st.top]; /*数栈顶元素赋给变量a*/
                st.top--;          /*栈顶指针减1*/
                b=st.data[st.top]; /*数栈顶元素赋给变量b*/
                st.top--;          /*栈顶指针减1*/
                c=b+a;             /*将a加b的结果存入变量c*/
                st.top++;          /*栈顶指针加1*/
                st.data[st.top]=c; /*将变量c入栈*/
                break;
            case '-':
                a=st.data[st.top]; 
                st.top--;
                b=st.data[st.top];
                st.top--;
                c=b-a;
                st.top++;
                st.data[st.top]=c;
                break;
            case '*':
                a=st.data[st.top];
                st.top--;
                b=st.data[st.top];
                st.top--;
                c=b*a;
                st.top++;
                st.data[st.top]=c;
                break;
            case '/':
                a=st.data[st.top];
                st.top--;
                b=st.data[st.top];
                st.top--;
                if(a!=0)
                {
                    c=b/a;
                    st.top++;
                    st.data[st.top]=c;
                }    
                else
                    printf("\n\t除零错误!\n");

                break;
            default: /*后缀表达式的字符是数字字符时，将其转换为整数*/
                d=0;
                while(*postexp>='0'&&*postexp<='9')
                {
                    d=10*d+*postexp-'0';
                    postexp++;
                }    
                st.top++;
                st.data[st.top]=d;  /*将转换之后的整数入栈*/
                break;
        }    
        postexp++;
    }    
    return st.data[st.top];   /*返回数栈的栈顶元素即为所求的结果*/
}   
              
void  MenuStack()                                    
{   /*显示菜单子函数*/ 
	printf("\n                     栈子系统");
    printf("\n==================================================");  
    printf("\n|               1——初始化栈                    |");
    printf("\n|               2——入栈操作                    |");
    printf("\n|               3——出栈操作                    |");
    printf("\n|               4——求栈顶元素                  |");
    printf("\n|               5——显示栈中元素                |");
    printf("\n|               6——十、二进制数转换            |");
    printf("\n|               7——表达式转换并求值            |");
    printf("\n|               0——返回                        |");
    printf("\n=================================================="); 
    printf("\n请输入菜单号（0-7）:"); 	
}

main()
{
   int i,n,flag;
   LinkStack *S;
   DataType x;
   char  ch1,ch2,a;
   char exp[MAXSIZE],postexp[MAXSIZE];  /*求表达式值的两个数组*/
   ch1='y';
   while(ch1=='y'||ch1=='Y') 
   {  MenuStack();
   	  scanf("%c",&ch2);
   	  getchar();
   	  switch(ch2)
   	  {
   	  	 case  '1':   	  	 
             S=InitStack();
             printf("栈的初始化完成！");
             break;
         case  '2':
             printf("请输入要入栈的元素个数：");
             scanf("%d",&n);
             printf("请输入%d个整数进行入栈：",n);
             for(i=0;i<n;i++)
             {   
             	 scanf("%d",&x);
             	 S=Push(S,x);
             }
             printf("入栈成功！");
             break;
         case  '3':
             printf("请输入要出栈的元素个数：");
             scanf("%d",&n);
             printf("出栈的元素为："); 
             for(i=0;i<n;i++)
             {   
             	 S=Pop(S,&x);
             	 if(S!=NULL)
             	    printf("%5d",x);
             }
             break;    
         case  '4':
             if(flag=GetTop(S,&x))
                 printf("当前的栈顶元素值为：%d",x);
             break;
         case  '5':
             ShowStack(S);
             break;    
         case  '6':
             S=InitStack();
             printf("请输入十进制正整数为:");
             scanf("%d",&x);     /*输入十进制正整数*/ 
             D_B(S,x);          /*调用进制转换函数*/
             break;
         case  '7':
             printf("请输入算术表达式（只有+、-、*、/四种运算符），以'#'结束：");
             scanf("%s",&exp);
             trans(exp,postexp);
             printf("则该表达式的中缀表达式为：%s\n",exp);
             printf("转换之后的后缀表达式为（每个操作数用“#”分隔）：%s\n",postexp);
             printf("表达式的值为:%.2f\n",compvalue(postexp));
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


