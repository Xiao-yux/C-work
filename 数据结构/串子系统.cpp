#include <stdio.h>
#define MAXSIZE 100  // 顺序串存储空间的总分配量

typedef struct {  // 串结构定义
   char ch[MAXSIZE];
   int Len;
} String;

int StrLength(String *S) {  // 求串长度函数
   int i;
   for (i = 0; S->ch[i] != '\0'; i++) {
   }
   return i;
}

void CreatStr(String *S) {  // 建立一个新串
   printf("请输入一个字符串：");
   scanf("%s", S->ch);
   S->Len = StrLength(S);
}

int SubString(String *S, String *Sub, int pos, int len) {  // 求子串函数
   if (pos < 1 || pos > S->Len || len < 1 || len > S->Len - pos + 1) {
       return 0;
   }
   for (int i = 0; i < len; i++) {
       Sub->ch[i] = S->ch[pos + i - 1];
   }
   Sub->ch[len] = '\0';
   return 1;
}

int StrDelete(String *S, int i, int l) {  // 在串s中删除从指定位置i开始连续的j个字符
   if (i + l - 1 > S->Len) {
       return 0;
   } else {
       for (int j = i; j < i + l; j++) {
           S->ch[j] = S->ch[j + l];
       }
       S->ch[i + l - 1] = '\0';
       S->Len -= l;
       return 1;
   }
}

int StrInsert(String *S, String *S1, int i) {  // 在串s中插入子串s1函数
   int j;
   if (i > S->Len + 1) {
       printf("插入位置错误！\n");
       return 0;
   } else if (S->Len + S1->Len > MAXSIZE) {
       printf("两串长度超过存储空间长度！\n");
       return 0;
   } else {
       S->Len += S1->Len;
       for (j = S1->Len - 1; j >= 0; j--) {
           S->ch[i + j] = S1->ch[j];
       }
       S->ch[i + S1->Len] = '\0';
       return 1;
   }
}

int StrIndex(String *S, String *T) {  // 串的定位函数
   int i, j;
   for (i = 0; i <= S->Len - T->Len; i++) {
       for (j = 0; j < T->Len; j++) {
           if (S->ch[i + j] != T->ch[j]) {
               break;
           }
       }
       if (j == T->Len) {
           return i;
       }
   }
   return -1;
}

int StrCompare(String *S1, String *S2) {  // 两个串判断是否相等
   if (S1->Len != S2->Len) {
       return 0;
   }
   for (int i = 0; i < S1->Len; i++) {
       if (S1->ch[i] != S2->ch[i]) {
           return S1->ch[i] - S2->ch[i];
       }
   }
   return 0;
}

int StrCat(String *S, String *T) {  // 串的连接函数
   int i, flag;  // 将串T连接在串S的后面
   if (S->Len + T->Len <= MAXSIZE) {
             for (i = 0; i < T->Len; i++) {
          S->ch[i + S->Len] = T->ch[i];
      }
      S->ch[S->Len + T->Len] = '\0';
      S->Len += T->Len;
      flag = 1;
  } else if (S->Len < MAXSIZE) {
      S->Len += T->Len;
      for (i = S->Len - 1; i > 0; i--) {
          S->ch[i] = S->ch[i - 1];
      }
      S->ch[0] = '\0';
      flag = 1;
  } else {
      flag = 0;
  }
  return flag;
}

void StrReplace(String *S, String *T, String *V) {  // 子串替换函数
  int i, m, n, p, q;
  n = S->Len;
  m = T->Len;
  q = V->Len;
  p = 1;
  do {
      i = StrIndex(S, T);   // 调用定位函数得到子串T在主串S的位置
      if (i != -1) {  // 当主串S中有该子串T时
          StrDelete(S, i, m);  // 调用删除子串函数删除该子串T
          StrInsert(S, V, i);  // 调用插入子串函数插入子串V
          p = i + q;
          S->Len = S->Len + q - m;  // 修改主串S的长度
          n = S->Len;
      }
  } while ((p <= n - m + 1) && (i != -1));
}

void  MenuString()                                    
{   // 显示菜单子函数
  printf("\n                     串子系统");
  printf("\n==================================================");  
  printf("\n|               1——建立新串并显示该串及长度    |");
  printf("\n|               2——求子串                      |");
  printf("\n|               3——删除子串                    |");
  printf("\n|               4——插入子串                    |");
  printf("\n|               5——查找子串                    |");
  printf("\n|               6——比较两个串大小              |");   
  printf("\n|               7——连接两个串                  |"); 
  printf("\n|               8——子串替换                    |");  
  printf("\n|               0——返回                        |");
  printf("\n===============刘演潮 202220105004=================="); 
  printf("\n请输入菜单号（0-8）:"); 	
}

int main()
{
  int i, len, flag;
  String  x, y, z;
  String *S=&x,*S1=&y,*S2=&z; 
  char  ch1,ch2,a;
  ch1='y';
  while(ch1=='y'||ch1=='Y') 
    {  
    MenuString();
    scanf("%c",&ch2);
    getchar();
        switch(ch2)
       {
           case '1':
               CreatStr(S);
               printf("新串为：%s，长度为：%d\n", S->ch, S->Len);
               break;
           case '2':
               printf("请输入子串的起始位置和长度：");
               scanf("%d%d", &i, &len);
               if (SubString(S, S1, i, len)) {
                   printf("子串为：%s\n", S1->ch);
               } else {
                   printf("输入位置或长度错误！\n");
               }
               break;
           case '3':
               printf("请输入要删除的子串的起始位置和长度：");
               scanf("%d%d", &i, &len);
               if (StrDelete(S, i, len)) {
                   printf("删除后的串为：%s\n", S->ch);
               } else {
                   printf("输入位置或长度错误！\n");
               }
               break;
           case '4':
               printf("请输入要插入的子串：");
               CreatStr(S1);
               printf("请输入插入的位置：");
               scanf("%d", &i);
               if (StrInsert(S, S1, i)) {
                   printf("插入后的串为：%s\n", S->ch);
               } else {
                   printf("插入失败！\n");
               }
               break;
           case '5':
               printf("请输入要查找的子串：");
               CreatStr(S1);
               i = StrIndex(S, S1);
               if (i != -1) {
                   printf("子串在主串中的位置为：%d\n", i + 1);
               } else {
                   printf("主串中没有该子串！\n");
               }
               break;
           case '6':
               printf("请输入要比较的另一个串：");
               CreatStr(S1);
               int result;
			   result = StrCompare(S, S1);
               if (result == 0) {
                   printf("两个串相等\n");
               } else if (result > 0) {
                   printf("第一个串大于第二个串\n");
               } else {
                   printf("第一个串小于第二个串\n");
               }
               break;
           case '7':
               printf("请输入要连接的另一个串：");
               CreatStr(S1);
               if (StrCat(S, S1)) {
                   printf("连接后的串为：%s\n", S->ch);
               } else {
                   printf("连接失败！\n");
               }
               break;
           case '8':
               printf("请输入要替换的子串：");
               CreatStr(S1);
               printf("请输入替换后的子串：");
               CreatStr(S2);
               StrReplace(S, S1, S2);
               printf("替换后的串为：%s\n", S->ch);
               break;
           case '0':
               return 0;
       }
        getchar();
        printf("\n是否继续（Y/N）?");
        scanf("%c",&ch1); 
        getchar();
    }
}
