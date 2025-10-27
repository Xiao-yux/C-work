#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100 // 栈的最大容量

typedef struct {
   int data[MAXSIZE]; // 栈的存储空间
   int top; // 栈顶指针
} SqStack;

// 初始化栈
void initStack(SqStack* S) {
   S->top = -1;
}

// 判断栈是否为空
int isEmpty(SqStack S) {
   return S.top == -1;
}

// 判断栈是否已满
int isFull(SqStack S) {
   return S.top == MAXSIZE - 1;
}

// 入栈
void push(SqStack* S, int elem) {
   if (isFull(*S)) {
       printf("栈已满,无法入栈\n");
       return;
   }
   S->data[++S->top] = elem;
}

// 出栈
int pop(SqStack* S) {
   if (isEmpty(*S)) {
       printf("栈为空,无法出栈\n");
       return -1;
   }
   return S->data[S->top--];
}

// 取栈顶元素
int getTop(SqStack S) {
   if (isEmpty(S)) {
       printf("栈为空,无法取栈顶元素\n");
       return -1;
   }
   return S.data[S.top];
}

int main() {
   SqStack S;
   initStack(&S);
   push(&S, 15);
   push(&S, 26);
   push(&S, 30);
   printf("栈顶元素为:%d\n", getTop(S));
   printf("出栈元素为:%d\n", pop(&S));
   printf("栈顶元素为:%d\n", getTop(S));
   return 0;
}
