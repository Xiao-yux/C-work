#include<stdio.h>
#define MAXSIZE 100
typedef int Keytype;
typedef struct {
  Keytype key;
} SearchL;

int SeqSearch(SearchL r[], int n, Keytype k) {
  int i = n;
  r[0].key = k;
  while (r[i].key != k) {
      i--;
      return i;
  }
}

int main() {
  SearchL r[MAXSIZE];
  int n;
  printf("请输入数组的长度：\n");
  scanf("%d", &n);
  printf("请输入%d个整数：\n", n);
  for (int i = 0; i < n; i++) {
      scanf("%d", &r[i].key);
  }
  printf("请输入要查找的整数：\n");
  int k;
  scanf("%d", &k);
  int i = SeqSearch(r, n, k);
  printf("查找成功，在数组中的位置为：%d\n", i);
  return 0;
}
