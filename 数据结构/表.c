#include<stdio.h>
#define MAXLEN 100
typedef int DataType;
typedef struct
{
    DataType data[MAXLEN];
    int length;
}SeqList;
SeqList L;

void InitList(SeqList *L)
{
    L->length=0;
}

void CreateList(SeqList *L,int n)
{
    int i;
    printf("请输入%d个整数:",n);   
    for(i=0;i<n;i++)
    {
        scanf("%d",&L->data[i]);
    }
    L->length=n;
}

int GetElem(SeqList *L, int i, DataType *x)
{
    if (i < 1 || i > L->length)
    {
        return 0;
    }
    else
    {
        *x = L->data[i - 1];
        return 1;
    }
}

int Locate(SeqList *L,DataType x)
{
    int i=0;
    while(i<L->length&&L->data[i]!=x)
        i++;
    if(i>=L->length)
        return 0;
    else
        return i+1;
}

int Insert(SeqList *L,int i,DataType x)
{
    int j;
    if(L->length==MAXLEN)
    {
        printf("表满");
        return -1;
    }
    if(i<1||i>L->length+1)
    {
        printf("位置不合法");
        return 0;
    }
    if(i==L->length+1)
    {
        L->data[i-1]=x;
        L->length++;
        return 1;
    }
    for(j=L->length-1;j>=i-1;j--)
    {
        L->data[j+1]=L->data[j];
        L->data[j]=x;
        L->length++;
        return 1;
    }
   return 0; 
}

int DelElem(SeqList *L,int i,DataType *x)
{
    int j;
    if(L->length==0)
    {
        printf("表空");
        return 0;
    }
    if(i<1||i>L->length)
    {
        printf("不存在第i个元素");
        return 0;
    }
    *x=L->data[i-1];
    for(j=i;j<L->length;j++)
        L->data[j-1]=L->data[j];
    L->length--;
    return 1;   
}

void Display(SeqList *L)
{
    int i;
    for(i=0;i<L->length;i++)
        printf("%5d ",L->data[i]);
    printf("\n");
}

void Menu()
{
    printf("********************************************\n");
    printf("1.建立顺序表\n");
    printf("2.插入元素\n");
    printf("3.删除元素\n");
    printf("4.按位置查找元素\n");
    printf("5.按元素值查找其在表中的位置\n");
    printf("6.求顺序表的长度\n");
    printf("0.返回\n");
    printf("********************************************\n");
    printf("\n请输入菜单号(0-6):");
    printf("********************************************\n");
    printf("*********** 刘演潮 202220105004 ************\n");
    printf("********************************************\n");
}

int main()
{
    SeqList L;
    DataType x;
    int i,loc,n;
    char ch1,ch2,a;
    ch1 = 'y';
    while (ch1=='y'||ch1=='Y')
    {
        Menu();
        scanf("%c",&ch2);
        getchar();
        switch(ch2)
        {
            case '1':
                InitList(&L);
                printf("请输入建立线性表的个数:");
                scanf("%d",&n);
                CreateList(&L,n);
                printf("建立的线性表为:");
                Display(&L);
                break;
            case '2':
                printf("请输入插入的位置:");
                scanf("%d",&i);
                printf("请输入插入的元素:");
                scanf("%d",&x);
                if(Insert(&L,i,x))
                {
                    printf("已成功在第%d的位置上插入%d,插入后的线性表为:\n",i,x);
                    Display(&L);
                }
                else
                    printf("输入插入的参数错误!\n");
                break;
        	case '3':
        		printf("请输入要删除的元素位置:");
        		scanf("%d",&i);
        		if(DelElem(&L,i,&x)){
					printf("已经成功在第%d的位置上删除%d,删除后的线性表为:\n",i,x);
					Display(&L);
				}
				else
					printf("\n输入删除的参数错误!");
				break;
			case '4':
				printf("请输入要查看表中元素的位置(从1开始):");
				scanf("%d",&i);
				if(GetElem(&L,i,&x))
					printf("当前线性表第%d个元素的值为:%d",i,x);
				else
					printf("输入的位置错误!");
				break;
			case '5':
				printf("请输入要查找的元素值为:");
				scanf("%d",&x);
				loc=Locate(&L,x);
				if(loc)
					printf("查找的元素值为%d的位置为:%d",x,loc);
				else
					printf("查无此元素!");
				break;
			case '6':
				printf("当前的线性表长度为:%d",L.length);
				break;
			case '0':
				ch1='n';break;
			default:
				printf("输入有误，请输入0~6进行选择");
				
		}
		if(ch2!=0){
			printf("\n按回车键继续,按任意键返回主菜单!\n");
			a=getchar();
			if(a!='\xA'){
				getchar();ch1='n';
			}
		}
    }
}
