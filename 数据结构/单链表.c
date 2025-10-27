#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
typedef struct linknode
{
	DataType data;
	struct linknode *next;
}LinkList;

LinkList *InitList()
{ //初始化链表函数
	LinkList *head;
	head=(LinkList*)malloc(sizeof(LinkList));
	head->next=NULL;
	return head;
}

void CreateListH(LinkList *head,int n)
{/*	头插法建立链表函数*/
	LinkList *s;
	int i;
	printf("请输入%d个整数:",n);
	for(i=0;i<n;i++)
	{
		s=(LinkList *)malloc(sizeof(LinkList));
		scanf("%d",&s->data);
		s->next=head->next;
		head->next=s;
	}
	printf("建立链表操作成功!");
}

void CreateListL(LinkList *head,int n)
{/*	尾插法建立链表函数*/
	LinkList *s,*last;
	last=head;
	printf("请输入%d个整数:",n);
	for (int i = 0; i < n; i++)
	{
		s=(LinkList *)malloc(sizeof(LinkList));
		scanf("%d",&s->data);
		s->next=NULL;
		last->next=s;
		last=s;
	}
	printf("建立链表操作成功!");
}

int LengthList(LinkList *head)
{
	LinkList *p=head->next;
	int j=0;
	while(p!=NULL)
	{
		p=p->next;
		j++;
	}
	return j;
}

void Locate(LinkList *head,DataType x)
{//按值查找
	int j=1;
	LinkList *p;
	p=head->next;
	while(p!=NULL&&p->data!=x)
	{
		p=p->next;
		j++;
	}
	if(p!=NULL)
		printf("第%d个元素为%d",j,p->data);
	else
		printf("未找到该元素");
}

void SearchList(LinkList *head,int i)
{//按位置查找
	LinkList *p;
	int j=0;
	if(i>LengthList(head))
		printf("位置错误，链表中没有该位置.");
	while (p->next!=NULL&&j<i)
	{
		p=p->next;
		j++;
	}
	if(j==i)
		printf("在第%d位上的元素值为%d.",i,p->data);			
}

void InsList(LinkList *head,int i,DataType x)
{//按位置插入元素
	int j=0;
	LinkList *p,*s;
	p=head;
	while(p->next!=NULL&&j<i-1)
	{
		p=p->next;
		j++;
	}
	if(p!=NULL)
	{
		s=(LinkList *)malloc(sizeof(LinkList));
		s->data=x;
		s->next=p->next;
		p->next=s;
		printf("插入成功!");
	}
	else
		printf("插入位置错误!");
}

void DelList(LinkList *head,int i)
{
	int j=0;
	DataType x=0;
	LinkList *p=head,*s;
	while (p->next!=NULL&&j<i-1)
	{
		p=p->next;
		j++;
	}
	if(p->next!=NULL && j==i-1)
	{
		s=p->next;
		x=s->data;
		p->next=s->next;
		free(s);
		printf("删除成功!");
	}
	else
		printf("删除位置错误!");
}

void DispList(LinkList *head)
{
	LinkList *p;
	p=head->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}

void Menu()
{
    printf("********************************************\n");
    printf("|1.建立单链表							\n");
    printf("|2.插入元素								\n");
    printf("|3.删除元素								\n");
    printf("|4.按位置查找元素							 \n");
    printf("|5.按元素值查找其在表中的位置				  \n");
    printf("|6.求顺序表的长度							 \n");
    printf("|0.返回									\n");
    printf("|*******************************************\n");
    printf("|请输入菜单号(0-6):						\n");
    printf("********************************************\n");
    printf("*********** 刘演潮 202220105004 ************\n");
    printf("********************************************\n");
}

int main()
{
	LinkList head;
	int i,n;
	DataType x;
	InitList(&head);
	while(1)
	{
		Menu();
		scanf("%d",&i);
		switch(i)
		{
			case 1:printf("请输入表长:");
					scanf("%d",&n);
					CreateListH(&head,n);
					break;
			case 2:printf("请输入插入的元素和位置:");
					scanf("%d%d",&x,&i);
					InsList(&head,i,x);
					break;
			case 3:printf("请输入删除元素:");
					scanf("%d",&x);
					DelList(&head,x);
					break;
			case 4:printf("请输入查找元素:");
					scanf("%d",&x);
					SearchList(&head,x);
					break;
			case 5:printf("请输入要查找的值:");
					scanf("%d",&x);
					Locate(&head,x);
					break;
			case 6:printf("顺序表的长度为:");
					printf("%d\n",LengthList(&head));
					break;
			case 0:exit(0);
			default:printf("输入错误,请重新输入!\n");
        }
	}
}
