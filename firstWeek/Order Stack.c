/*基于数组的顺序栈(Order Stack)
 *优点：查找排序与插入删除都很快
 *缺点：需要事先确定存储空间大小*/
#include<stdio.h>
#include<stdlib.h>

typedef int Elemtype;	//定义栈的存储数据类型

typedef struct SqStack
{
	Elemtype *elem;
	int top;
	int size;
}SqStack;

typedef enum Status
{
	OK,ERROR,OVERFLOW,TRUE,FALSE
}Status;

Status initStack(SqStack *s, int size);
Status push(SqStack *s, Elemtype e);
Status pop(SqStack *s, Elemtype *e);
Status getTop(SqStack *s, Elemtype *e);
Status isEmptyStack(SqStack *s);
Status destroyStack(SqStack *s);
int get_int(void);//获取一个整数
void divide(void);		//分隔函数


int main(void)
{
	int flag = 0, size, num;
	Elemtype e1, e2, e3;
	SqStack s;
	s.elem = NULL;
	divide();
	printf("基于数组的顺序栈\n"); 
	printf("请先初始化后再使用之后功能\n");
	printf("1---初始化一个栈\n");
	printf("2---压栈\n");
	printf("3---弹栈\n");	
	printf("4---获取栈顶\n");
	printf("5---判断是否为空栈\n");
	printf("6---销毁栈\n");
	printf("0---退出\n");
	divide();
	printf("请选择数字来获得你想要的功能： ");
	num = get_int();
	while(num != 0)
	{
		switch(num)
		{
			case 1 :printf("请输入你所需要的栈的大小：");
					size = get_int();
					if(initStack(&s, size) == OK)
						printf("初始化成功！\n");
					else
						printf("内存不足！\n");
					break;
			case 2 :printf("请输入你要压栈的数据：");
					e1 = get_int();
					if(push(&s, e1) == OK)
						printf("压栈成功！\n");
					else
						printf("栈未初始化或满栈\n");
					break;
			case 3 :if(pop(&s, &e2) == OK)
						printf("弹栈成功，栈顶元素为%d \n",e2);
					else
						printf("栈未初始化或栈为空!\n");
					break;
			case 4 :if(getTop(&s, &e3) == OK)
						printf("栈顶元素为%d \n",e3);
					else
						printf("栈未初始化或栈为空!\n");
					break;
			case 5 :if(isEmptyStack(&s) == TRUE)
						printf("栈已空！\n");
					else
						printf("不是空栈!\n");
					break;
			case 6 :if(destroyStack(&s) == OK)
						printf("销毁成功!\n");
					else
						printf("销毁失败!\n");
					break;
			case 0 :flag = 1;
					break;
			default :printf("请选择相应功能所对应的数字 0~6 ！\n");
		}
		if(flag==0)
		{	
			divide();
			printf("1---初始化一个栈\n");
			printf("2---压栈\n");
			printf("3---弹栈\n");	
			printf("4---获取栈顶\n");
			printf("5---判断是否为空栈\n");
			printf("6---销毁栈\n");
			printf("0---退出\n");
			printf("请选择数字来获得你想要的功能： ");
			num = get_int();
		}
		else
			break;
	}
	printf("已退出。\n");		
	return 0;			
}

Status initStack(SqStack *s, int size)	//初始化栈，size为栈的固定大小
{
	s->elem = (Elemtype *)malloc(size * sizeof(Elemtype));
	if(s->elem == NULL )
		return OVERFLOW;
	s->top = -1;
	s->size = size;
	return OK;
}

Status push(SqStack *s, Elemtype e)	//压栈
{
	if(s == NULL || s->top == s->size - 1)	//栈未初始化或满栈
		return ERROR;
	s->top++;			//栈顶指针加1
	s->elem[s->top] = e;	//将新插入元素赋值给栈顶空间
	return OK;
}

Status pop(SqStack *s, Elemtype *e)	//出栈
{
	if(s == NULL || s->top == -1)	//空栈或到栈底
		return ERROR;
	*e = s->elem[s->top];	//将要删除的栈顶元素赋值给e
	s->top--;			//将栈顶指针减1
	return OK;
}

Status getTop(SqStack *s, Elemtype *e)
{
	if(s == NULL || s->top == -1)
		return ERROR;
	else 
		*e = s->elem[s->top];
	return OK;
}

Status isEmptyStack(SqStack *s)
{
	return s->top == -1? TRUE: FALSE;
}

Status destroyStack(SqStack *s)
{
	if(s == NULL)
		return ERROR;
	free(s->elem);
	return OK;
}

int get_int()
{
	int input;
	char ch;
	
	while(scanf("%d",&input)!=1)
	{
		while((ch=getchar())!='\n')
			putchar(ch);			//删除错误的输入
		printf("不是一个整数.\n请输入一个整数值" 
		       "，比如 25,-178 或 3:");
	}
	return input;
}

void divide(void)
{
	printf("************************************************\n");
}






