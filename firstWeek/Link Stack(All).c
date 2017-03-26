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


int main(void)
{
	int flag = 0, size, num, len;
	Elemtype e1, e2, e3;
	LinkStack s;
	divide();
	printf("基于链表的顺序栈\n"); 
	printf("请先初始化后再使用之后功能\n");
	printf("1---初始化一个栈\n");
	printf("2---压栈\n");
	printf("3---弹栈\n");	
	printf("4---获取栈顶\n");
	printf("5---判断是否为空栈\n");
	printf("6---销毁栈\n");
	printf("7---清空栈\n");
	printf("8---获取长度\n");
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
						printf("栈未初始化!\n");
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
			case 7 :if(cleanStack(&s) == OK)
						printf("清空成功!\n");
					else
						printf("清空失败!\n");
					break;
			case 8 :printf("链栈长度为%d",stackLength(&s));
					break;
			case 0 :flag = 1;
					break;
			default :printf("请选择相应功能所对应的数字 0~8 ！\n");
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
			printf("7---清空栈\n");
			printf("8---获取长度\n");
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
	LinkStack t;
	if((t = (LinkStackPtr) malloc(sizeof(StackNode))) == NULL)
		return ERROR;
	t->data = data;		//另起指针变量使其指向自己
	t->next = ls->top;	//即反向建单链表
	ls->top = t;
	return OK;
}

Status pop(LinkStack *ls, Elemtype *e)
{
	if(ls-top == NULL || ls->count == 0)	//count=0即空栈
		return ERROR;
	ls->count--;
	*e = ls->top->data;
	
	LinkStackPtr = t;
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
		LinkStackPtr = t;
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
		LinkStackPtr = t;
		t = ls->top;
		ls->top = ls->top->next;
		free(t);
	}
	//头结点的那一个数据不用动？？？
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


