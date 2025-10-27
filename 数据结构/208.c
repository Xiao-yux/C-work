#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int KeyType;
typedef struct {
	KeyType key;
	KeyType low;
	KeyType high;
} SearchL, Idxtype;

int SeqSearch(SearchL r[], int n, KeyType k) {
	int i = n;
	r[0].key = k;
	while (r[i].key != k) {
		i--;
		return (i);
	}
}

int BinSearch(SearchL r[], int n, KeyType k) {
	int low, high, mid;
	low = 1;
	high = n;
	while (low <= high) {
		mid = (low + high) / 2;
		if (k == r[mid].key)
			return (mid);
		else if (k < r[mid].key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return (0);
}
void CreatIdx(SearchL r[], Idxtype idx[], int m, int n) {
	int i, j, k = 0;
	KeyType max;
	for (i = 1; i < m; i += n) {
		max = r[i].key;
		for (j = i + 1; j <= i + n && j < m; j++)
			if (r[j].key > max) max = r[j].key;
		idx[k].key = max;
		idx[k].low = i;
		if (i + n - 1 < m - 1)
			idx[k].high = i + n - 1;
		else
			idx[k].high = m - 1;
		k++;
	}
}

int BlkSearch(SearchL r[], Idxtype idx[], int m, KeyType k) {
	int low, high, mid, i, j, find = 0;
	i = 0;
	while (idx[i].key < k)
		i++;
	low = idx[i].low;
	high = idx[i].high;
	while (low <= high && !find) {
		mid = (low + high) / 2;
		if (k < idx[mid].key)
			high = mid - 1;
		else if (k > idx[mid].key)
			low = mid + 1;
		else {
			find = 1;
			high = mid - 1;
		}
	}
	if (low < m) {
		i = idx[low].low;
		j = idx[low].high;
	}
	while (i < j && r[i].key != k)
		i++;
	if (i >= j) return (-1);
	else return (i);
}

typedef struct treenode {
	KeyType key;
	struct treenode *lchid, *rchild;
} BTNode;
BTNode *BSTInsert(BTNode *bt, KeyType k) {
	BTNode *f, *p = bt;
	while (p != NULL) {
		f = p;
		if (p->key > k)
			p = p->lchid;
		else
			p = p->rchild;
	}
	p = (BTNode *)malloc(sizeof(BTNode));
	p->key = k;
	p->lchid = NULL;
	p->rchild = NULL;
	if (bt == NULL)
		bt = p;
	else if (k < f->key)
		f->lchid = p;
	else
		f->rchild = p;
	return (bt);
}

BTNode *CreateBST(KeyType str[], int n) {
	int i = 0;
	BTNode *bt = NULL;
	while (i < n) {
		bt = BSTInsert(bt, str[i]);
		i++;
	}
	return (bt);
}

void DispBStree(BTNode *bt) {
	if (bt != NULL) {
		printf("%d ", bt->key);
		if (bt->lchid != NULL || bt->rchild != NULL) {
			printf("(");
			DispBStree(bt->lchid);
			if (bt->rchild != NULL)
				printf(",");
			DispBStree(bt->rchild);
			printf(")");
		}
	}
}

BTNode *BSTDelete(BTNode *bt, KeyType k) {
	BTNode *p, *f, *s, *q;
	p = bt;
	f = NULL;
	while (p) {
		if (p->key == k) break;
		f = p;
		if (p->key > k)
			p = p->lchid;
		else
			p = p->rchild;
	}
	if (p == NULL) return (bt);
	if (p->lchid == NULL) {
		if (f == NULL)
			bt = p->rchild;
		else if (f->lchid == p)
			f->lchid = p->rchild;
		else
			f->rchild = p->rchild;
		free(p);
	} else {
		q = p;
		s = p->lchid;
		while (s->rchild) {
			q = s;
			s = s->rchild;
		}
		if (q == p) q->rchild = s->lchid;
		else q->rchild = s->lchid;
		p->key = s->key;
		free(s);
	}
	return bt;
}

BTNode *BSTSearch(BTNode *bt, KeyType k) {
	if (bt == NULL) return NULL;
	else {
		if (k == bt->key)
			return (bt);
		else if (k < bt->key)
			return (BSTSearch(bt->lchid, k));
		else
			return (BSTSearch(bt->rchild, k));
	}
}
void MenuBTree() {
	printf("\n             二叉排序树");
	printf("\n=================================");
	printf("\n        1.建立二叉排序树       ");
	printf("\n        2.插入一个元素       ");
	printf("\n        3.删除一个元素       ");
	printf("\n        4.查找一个元素       ");
	printf("\n        5.返回       ");
	printf("\n======刘演潮 202220105004========");
	printf("\n=================================");
	printf("\n请输入序号（0-4）进行选择");
}

void BTFun() {
	KeyType str[100];
	BTNode *bt;
	int i, n, x, menux;
	MenuBTree();
	scanf("%d", &menux);
	do {
		switch (menux) {
			case 1:
				printf("请输入要生成二叉排序树的关键子的个数:");
				scanf("%d", &n);
				printf("请输入二叉排序树的各个关键字:");
				for (i = 0; i < n; i++)
					scanf("%d", &str[i]);
				bt = CreateBST(str, n);
				printf("建立的二叉排序树广义表示法为:");
				DispBStree(bt);
				break;
			case 2:
				printf("请输入要插入的元素值:");
				scanf("%d", &x);
				bt = BSTInsert(bt, x);
				printf("插入后的二叉排序树为：");
				DispBStree(bt);
				break;
			case 3:
				printf("请输入要删除的元素值:");
				scanf("%d", &x);
				bt = BSTDelete(bt, x);
				printf("删除元素%d后的二叉排序树为：", x);
				DispBStree(bt);
				break;
			case 4:
				printf("请输入要查找的元素值:");
				scanf("%d", &x);
				if (BSTSearch(bt, x) != NULL)
					printf("在二叉排序树中存在元素%d！", x);
				else
					printf("在二叉排序树中不存在元素%d！", x);
				break;
			case 0:
				printf("退出程序！");
				return;
				break;
			default:
				printf("输入错误请重新输入!");
		}
		MenuBTree();
		scanf("%d", &menux);
	} while (1);
}

void Menu() {
	printf("\n             查找子系统");
	printf("\n=================================");
	printf("\n        1.顺序查找       ");
	printf("\n        2.折半查找       ");
	printf("\n        3.分块查找       ");
	printf("\n        4.二叉排序树查找      ");
	printf("\n        0.返回       ");
	printf("\n======刘演潮 202220105004========");
	printf("\n=================================");
	printf("\n请输入序号（0-4）进行选择");
}

int main() {
	SearchL r[MAXSIZE];
	Idxtype idx[MAXSIZE];
	int i, m, n, x, address;
	char ch1, ch2, a;
	ch1 = 'y';
	while (ch1 == 'y' || ch1 == 'Y') {
		Menu();
		scanf("%c", &ch2);
		getchar();
		switch (ch2) {
			case '1':
				printf("请输入表的元素个数(0-%d)：", MAXSIZE - 1);
				scanf("%d", &n);
				printf("请输入%d个表中的关键字(整数):", n);
				for (i = 1; i <= n; i++)
					scanf("%d", &r[i].key);
				printf("请输入要查找的关键字：");
				scanf("%d", &x);
				if ((address = SeqSearch(r, n, x)) != 0)
					printf("查找成功，其地址为%d\n", address);
				else
					printf("该元素不在表中!");
				break;
			case '2':
				printf("请输入表的元素个数(0-%d)：", MAXSIZE - 1);
				scanf("%d", &n);
				printf("请按照从小到大的顺序输入%d个关键字(为整数):", n);
				for (i = 1; i <= n; i++)
					scanf("%d", &r[i].key);
				printf("请输入要查找的关键字：");
				scanf("%d", &x);
				if ((address = SeqSearch(r, n, x)) != 0)
					printf("查找成功，其地址为%d\n", address);
				else
					printf("该元素不在表中!");
				break;
			case '3':
				printf("请输入表的元素个数(0-%d)：", MAXSIZE - 1);
				scanf("%d", &m);
				printf("请输入表中的关键字(为整数)，要求块内无序,块间有序:\n");
				for (i = 1; i <= m; i++)
					scanf("%d", &r[i].key);
				printf("表输入索引表每块的大小:");
				scanf("%d", &n);
				CreatIdx(r, idx, m, n);
				printf("建立的顺序表为:\n");
				for (i = 1; i <= m; i++)
					printf("%6d ", r[i].key);
				printf("\n索引表信息如下:");
				printf("\n低地址\t高地址\t最大关键字\n");
				if (m % n == 0)
					for (i = 1; i <= m / n; i++)
						printf("%6d\t%6d\t%6d\n", idx[i].low, idx[i].high, idx[i].key);
				else
					for (i = 0; i <= m / n; i++)
						printf("%6d\t%6d\t%6d\n", idx[i].low, idx[i].high, idx[i].key);
				printf("请输入要查找的关键字：");
				scanf("%d", &x);
				if ((address = SeqSearch(r, n, x)) != 0)
					printf("查找成功，其地址为%d\n", address);
				else
					printf("该元素不在表中!");
				break;
			case '4':
				BTFun();
				break;
			case '0':
				ch1 = 'n';
				break;
			default:
				printf("输入错误，请重新输入！\n");
		}
		if (ch2 != '0') {
			printf("\n按回车键继续，按任意键返回主菜单!\n");
			a = getchar();
			if (a != '\xA') {
				getchar();
				ch1 = 'n';
			}
		}
	}
}
