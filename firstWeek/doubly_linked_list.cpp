/*双向链表的相关操作        编写：仇无悔*/
/* 这里记首结点为第1个结点，首结点前为第0个结点*/
#include<stdio.h>
#include<stdlib.h>
#define SIZE sizeof(TNode)

typedef struct TNode
{
	int data;
	struct TNode *next;
	struct TNode *pre;
}TNode, *ptr_TNode;

typedef enum Status
{
	SUCCESS,ERROR
}Satuts;

ptr_TNode creat(int *arr, int n);
void print(ptr_TNode head);//同时会反向输出以检验逆序是否可行 
void destroy(ptr_TNode *head);
Status insert(ptr_TNode *head, ptr_TNode node, int index);
Status deleted(ptr_TNode *head, int index, int *data);
void reverse(ptr_TNode end);//反向输出 
void divide(void);	//分隔函数，使排版清晰 
int get_int();	// 获取一个int型输入，剔除不正确的输入

int main(void)
{
	int num, len, flag=0;
	int a[100];
	ptr_TNode listHead = NULL, listEnd = NULL;
	int insertIndex, deletedData, deletedIndex;
	divide();
	printf("双向链表的操作 版本2.0\n");
	printf("1---创建链表\n");
	printf("2---销毁链表\n");
	printf("3---输出链表\n");
	printf("4---插入数据\n");
	printf("5---删除数据\n");
	printf("0---退出程序\n");
	printf("温馨提示：1.创建链表时的长度不能超过100，之后可任意添加。\n");
	printf("          2.恰当选择功能3来查看链表输出是否符合所想。\n");
	printf("          *3.print()函数(功能3)同时会反向输出以检验逆序是否可行。\n");
	printf("          4.创建新链表应先销毁原链表。\n");
	printf("          5.该程序只能同时存在一个链表，创建新链表会覆盖原链表。\n"); 
	printf("          6.有任何建议可发邮件至799952033@qq.com 。\n");
	divide();
	printf("请选择数字来获得你想要的功能： ");
	num = get_int();
	while(num != 0)
	{
		switch(num)
		{
			case 1 :printf("请输入你所要输入的数据的个数： ");
				len = get_int();
				printf("请输入数据：");
				for(int i = 0; i < len; i++)
					a[i]=get_int();
				if((listHead=creat(a, len))!=NULL)
				{
					flag = 0;
					printf("创建成功！\n");
				}
				else
					printf("创建失败，请重试。\n");
				break;
			case 2 :destroy(&listHead);
				break;
			case 3 :print(listHead);
				break;
			case 4 :
			{//注意！！！此处的插入结点一定要用malloc ，否则再次插入时，同一地址会出错 
				printf("请输入你要插入的数据及位置\n");//debug了很久... 
				printf("插入的数据：");			 
				ptr_TNode pnode=(ptr_TNode)malloc(SIZE);	//<-加花括号的原因 
				pnode->data = get_int();		//局部变量只能在当前case中引用 
				printf("插入的位置: ");
				insertIndex = get_int();
				if(insert(&listHead, pnode, insertIndex)==SUCCESS)
					printf("插入成功！\n");
				else 
					printf("插入失败，请重试。\n");
				break;
			}
			case 5 :printf("请输入你想要删除的数据的位置： ");
				deletedIndex = get_int();
				if(deleted(&listHead, deletedIndex, &deletedData)==SUCCESS)
					printf("已删除第%d个结点后的数据，原数据为%d\n", deletedIndex, deletedData);
				else
					printf("删除失败，请重试。\n");
				break;
			case 0 :flag = 1;
				break;
			default :printf("请选择相应功能所对应的数字 0~8 ！\n");
		}
		if(flag==0)		//标志：若flag=1则退出循环
		{
			divide();
			printf("1---创建链表\n");
			printf("2---销毁链表\n");
			printf("3---输出链表\n");
			printf("4---插入数据\n");
			printf("5---删除数据\n");
			printf("0---退出程序\n");
			printf("请选择数字来获得你想要的功能：");
			num = get_int();
		}
		else
			break;
	}
	printf("已退出。\n");
	return 0;
}

ptr_TNode creat(int *arr, int n)
{
	int i=0;
	ptr_TNode head,p1,p2;
	if((p1=p2=head=(ptr_TNode)malloc(SIZE))==NULL || arr==NULL)
	{
		printf("内存已满或数组为空！\n");
		return NULL;
	}
	while(i<=n)
	{
		if(i==0)
			head->data=arr[i++];
		else
			p1->data=arr[i++];
		p2=p1;
		if((p1=(ptr_TNode)malloc(SIZE))==NULL)
		{
			printf("内存已满！\n");
			return NULL;
		}
		else
		{
			p2->next=p1;
			p1->pre=p2;
		}
	}
	head->pre=NULL;	//补头补尾 
	p2->next=NULL;
	return head;
}

void print(ptr_TNode head)
{
	int i=0;
	ptr_TNode p=head;
	if(head==NULL)
	{
		printf("链表为空！\n");	//空表则输出出错并返回 
		return;
	}
	while(p->next != NULL)
	{
		printf("%3d ",p->data);
		p=p->next;
		if(++i==6)
			putchar(10);		//每10个数换行
	}
	putchar(10);//换行
	putchar(10); 
	p=p->pre;
	reverse(p); 
}

Status insert(ptr_TNode *head, ptr_TNode node, int index)
{
	if(*head==NULL || node==NULL)
	{
		printf("链表或结点为空！\n");
		return ERROR;
	}
	if(index==0)		//node作为头指针时的情况
	{
		node->next=*head;
		(*head)->pre=node; 
		*head=node;
		(*head)->pre=NULL;
		return SUCCESS; 
	} 
	else				//node不作为头指针时的情况 
	{
		ptr_TNode p=*head;
		for(int i=0; i<index-1; i++) //循环到插入位置前 
			p=p->next;
		node->pre=p;
		node->next=p->next;
		p->next=node;
		node->next->pre=node; 
		return SUCCESS;
	}
}

Status deleted(ptr_TNode *head, int index, int *data)
{
	if(*head==NULL)
	{
		printf("链表或数据为空！\n");
		return ERROR;
	}
	ptr_TNode p1=*head,p2;
	if(index==0) 	//若删除的是头结点
	{
		*data=(*head)->data;
		*head=(*head)->next;
		(*head)->pre=NULL; 
		free(p1);
		return SUCCESS;
	}
	else			//删除的不是头结点
	{
		for(int i=0; i<index; i++)
		{
			p2=p1;
			p1=p1->next;
		}
		*data=p1->data;
		if(p1->next!=NULL) 
		{
			p2->next=p1->next;
			p1->next->pre=p2;
		}
		else
			p2->next=NULL;
		//p1->next->pre=p2;
		free(p1);
		return SUCCESS;
	}
}

void divide(void)
{
	printf("**************************************\n");
}
 
void reverse(ptr_TNode end)
{
	int i=0; 
	while(end!=NULL)
	{
		printf("%3d ",end->data);
		end=end->pre;
		if(++i==6)
			putchar(10);		//每10个数换行
	}
	putchar(10);
}

void destroy(ptr_TNode *head)
{
	if(*head==NULL)
	{	
		printf("链表为空！\n");	//已经是空表 
		return;
	}
	ptr_TNode p=*head;
	while(*head!=NULL)
	{
		*head=(*head)->next;
		free(p);
		p=*head;
	}
	printf("已销毁!\n");
}

int get_int()
{
	int input;
	char ch;
	
	while(scanf("%d",&input)!=1)
	{
		while((ch=getchar())!='\n')
			putchar(ch);			//删除错误的输入
		printf("不是一个整数。\n请输入一个整数值" 
		       "比如 25,-178 或者 3: ");
	}
	return input;
}

 
 
 