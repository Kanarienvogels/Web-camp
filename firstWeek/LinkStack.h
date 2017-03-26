//放一些函数声明与名称定义
#include<stdio.h>
#include<stdlib.h>

typedef int Elemtype;

typedef struct StackNode
{
	Elemtype data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;
	int count;
}LinkStack;

typedef enum Status
{
	OK,ERROR,OVERFLOW,TRUE,FALSE
}Status;


Status initStack(LinkStack *ls);
Status push(LinkStack *ls, Elemtype data);
Status pop(LinkStack *ls, Elemtype *e);
Status getTop(LinkStack *ls, Elemtype *e);
Status destroyStack(LinkStack *ls);
Status cleanStack(LinkStack *ls);
Status isEmptyStack(LinkStack *ls);
int stackLength(LinkStack *ls);

int get_int(void);//获取一个整数
void divide(void);		//分隔函数