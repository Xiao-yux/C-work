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
   if(ch=='0')
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

main()
{
   
   	  scanf("%c",&ch2);
   	  getchar();
   	  switch(ch2)
   	  {
   	  	 
         case  '4':
             printf("二叉树的中序遍历序列为：");
             InOrder(T);break;
         case  '5':
             printf("二叉树的后序遍历序列为：");
             PostOrder(T);break;
         case  '6':    
             printf("二叉树的层次遍历序列为：");
             LevelOrder(T);break;
         case  '7':
             count=0;Leafnum(T);
             printf("该二叉树有%d个叶子。",count);break;
         case  '8':
             count=0;Nodenum(T);
             printf("该二叉树共有%d个结点。",count);break; 
         case  '9':
             printf("该二叉树的深度是%d。",TreeDepth(T));break; 
         case  '0':
             ch1='n';break;
         default:
             printf("输入有误，请输入0-9进行选择！");
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
