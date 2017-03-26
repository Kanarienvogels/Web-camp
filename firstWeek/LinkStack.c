#include"LinkStack.h"

Status initStack(LinkStack *ls)
{
	ls->count = 0;
	if((ls->top = (LinkStackPtr) malloc(sizeof(StackNode))) == NULL)
		return OVERFLOW;
	ls->top->next = NULL;
	return OK;
}

Status push(LinkStack *ls, Elemtype data)
{
	if(ls == NULL)	//对比知不会出现满栈的情况
		return ERROR;	
	ls->count++;		

	
	/*  由于我事先定义好ls，传递的是地址，除非内存不够
		不然绝不会出现ls=NULL的情况 */
	
	
	
	//卡壳点
	LinkStackPtr t;
	if((t = (LinkStackPtr) malloc(sizeof(StackNode))) == NULL)
		return ERROR;
	t->data = data;		//另起指针变量使其指向自己
	t->next = ls->top;	//即反向建单链表,首结点指向自己，后结点指向前结点
	ls->top = t;
	return OK;
}

Status pop(LinkStack *ls, Elemtype *e)
{
	if(ls->top == NULL || ls->count == 0)	//count=0即空栈
		return ERROR;
	ls->count--;
	*e = ls->top->data;
	
	LinkStackPtr t;
	t = ls->top;
	ls->top = ls->top->next;
	free(t);
	return OK;
}

Status getTop(LinkStack *ls, Elemtype *e)
{
	if(ls->top == NULL || ls->count == 0)	
		return ERROR;
	*e = ls->top->data;
	return OK;
}

Status isEmptyStack(LinkStack *ls)
{
	return ls->count == 0? TRUE: FALSE;
}

Status destroyStack(LinkStack *ls)
{
	if(ls->top == NULL || ls->count == 0)	
		return ERROR;
	while(ls->top->next != NULL)
	{
		ls->count--;
		LinkStackPtr t;
		t = ls->top;
		ls->top = ls->top->next;
		free(t);
	}
	free(ls->top);
	ls->top = NULL;	//把头指针也销毁   这是与clean的区别？？
	return OK;
}

Status cleanStack(LinkStack *ls)	
{
	if(ls->top == NULL || ls->count == 0)	
		return ERROR;
	while(ls->top->next != NULL)
	{
		ls->count--;
		LinkStackPtr t;
		t = ls->top;
		ls->top = ls->top->next;
		free(t);
	}
	return OK;
}


int stackLength(LinkStack *ls)
{
		return ls->count;
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


