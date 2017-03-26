#include"LinkStack.c"

int main(void)
{
	int flag = 0, num, len;
	Elemtype e1, e2, e3;
	LinkStack s;
	s.count=0;
	divide();
	printf("基于链表的顺序栈\n"); 
	printf("请先初始化后再使用之后功能\n");
	printf("请务必先初始化后再使用，否则会出错！\n");
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
			case 1 :if(initStack(&s) == OK)
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
						printf("销毁失败,可能已经是空栈!\n");
					break;
			case 7 :if(cleanStack(&s) == OK)
						printf("清空成功!\n");
					else
						printf("清空失败,可能已经是空栈!\n");
					break;
			case 8 :printf("链栈长度为%d\n",stackLength(&s));
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