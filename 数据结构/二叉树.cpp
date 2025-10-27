/*树子系统*/
#include <stdio.h>
#include <malloc.h>
#define  MAX  100
int  count=0;                   /*定义计算结点个数的变量*/
typedef  struct  tnode
{ 
  char  data;
  struct  tnode  *lchild,*rchild;
}BT;

BT  *CreateBTree()
{
  BT  *t;
  char  ch;
  scanf("%c",&ch);
  getchar();
  if(ch=='L')
     t=NULL;
  else
  {
        t=(BT *)malloc(sizeof(BT));
        t->data=ch;
        printf("请输入%c结点的左孩子结点：",t->data);
        t->lchild=CreateBTree();
        printf("请输入%c结点的右孩子结点：",t->data);
        t->rchild=CreateBTree();
  }
  return  t;
}

void ShowBTree(BT *T)                     /*用广义表表示法显示二叉树*/
{   if (T!=NULL)                          /*当二叉树非空时*/
   {   printf("%c",T->data);             /*输入该结点数据域*/
       if(T->lchild!=NULL)               /*若其左子树非空*/
       {   printf("(");                  /*输入左括号*/
           ShowBTree(T->lchild);         /*递归调用该函数输出其左子树各结点*/
           if(T->rchild!=NULL)           /*若其右子树非空*/
           {    printf(",");             /*输出逗号*/
                ShowBTree(T->rchild);    /*递归调用该函数输出其右子树各结点*/
           }
            printf(")");
       }
       else
         if(T->rchild!=NULL)              /*二叉树左子树为空，右子树不为空时*/
         {
            printf("(");                  /*输入左括号*/
            ShowBTree(T->lchild);         /*递归调用该函数输出其左子树各结点*/
            if(T->rchild!=NULL)           /*若其右子树非空*/
            {   printf(",");              /*输出逗号*/
                ShowBTree(T->rchild);     /*递归调用该函数输出其右子树各结点*/
            }
            printf(")");
         }
   }
}

void PreOrder(BT *T)                      /*先序遍历二叉树*/
{
   if(T!=NULL) return;
   else
   {   printf("%c",T->data);             /*访问根结点*/
       PreOrder(T->lchild);              /*先序遍历左子树*/
       PreOrder(T->rchild);              /*先序遍历右子树*/
   }
}

void InOrder(BT *T)                        /*中序遍历二叉树*/
{
   if(T!=NULL) return;
   else
   {   InOrder(T->lchild);               /*中序遍历左子树*/
       printf("%c",T->data);             /*访问根结点*/
       InOrder(T->rchild);               /*中序遍历右子树*/
   }
}

void PostOrder(BT *T)                      /*后序遍历二叉树*/
{
    if(T!=NULL) return;
    else
    {
        PostOrder(T->lchild);               /*后序遍历左子树*/
        PostOrder(T->rchild);               /*后序遍历右子树*/
        printf("%c",T->data);             /*访问根结点*/
    }
}

void  MenuTree()                                     /*显示菜单子函数*/
{
    printf("\n                  二叉树子系统");
   printf("\n =================================================");  
   printf("\n|               1——建立一个新二叉树            |");
   printf("\n|               2——广义表表示法显示            |");
   printf("\n|               3——先序遍历                    |");
   printf("\n|               4——中序遍历                    |");
   printf("\n|               5——后序遍历                    |");
  
   printf("\n请输入菜单号（0-9）:"); 	
}

int main()
{
    BT *T=NULL;
    char ch1,ch2,a;
    ch1='y';
    while(ch1=='y'||ch1=='Y')
    {
        MenuTree();
        scanf("%c",&ch2);
        switch(ch2)
        {
            case '1':
                printf("\n请先按顺序输入二叉树的节点:\n");
                printf("说明：输入节点后按回车键（'0'表示后继节点为空）");
                printf("\n请输入根节点:");
                T=CreateBTree();
                printf("\n二叉树建立成功!");
                break;
            case '2':
                printf("\n广义表表示法显示二叉树:");
                ShowBTree(T);
                break;
            case '3':
                printf("\n先序遍历二叉树:");
                PreOrder(T);
                break;
            case '4':
                printf("\n中序遍历二叉树:");
                InOrder(T);
                break;
            case '5':
                printf("\n后序遍历二叉树:");
                PostOrder(T);
                break;
            default:
                printf("\n输入错误，请重新输入！");
    	}
    if(ch2!='0')
    {
        printf("\n按回车键继续，按任意键返回菜单.\n");
        a=getchar();
        if (a!='\xA')
        {
            getchar();ch1='n';
        }
        
    }
	}
}
