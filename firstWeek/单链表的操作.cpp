/*QG的第一次作业*/
/*单链表的有关操作      编写：仇无悔*/
/* 这里记首结点为第1个结点，首结点前为第0个结点*/
#include<stdio.h>
#include<stdlib.h>
#define SIZE sizeof(struct Node)

 
typedef struct Node
{
	int data;
	struct Node *next;
}Node, *ptr_Node;

typedef enum Status
{
	SUCCESS,ERROR
}Satuts;

		//函数声明 
ptr_Node creat(int *arr, int n);
void destroy(ptr_Node *head);
void print(ptr_Node head);
Status insert(ptr_Node *head, ptr_Node node, int index);
Status deleted(ptr_Node *head, int index, int *data);
int search(ptr_Node head, int data);
Status edit(ptr_Node head, int index,int *data);
Status sort(ptr_Node *head);
int get_int();	// 获取一个int型输入，剔除不正确的输入
void divide(void);	//分隔函数，使输出清晰

int main(void)	//主函数：测试部分 
{
	int num, len, flag=0;
	int a[100];
	ptr_Node listHead = NULL;
	int insertIndex, deletedData, deletedIndex;
	int editDate, editIndex, searchData, searchIndex;
	divide();
	printf("单链表的操作 版本2.0\n");
	printf("1---创建链表\n");
	printf("2---销毁链表\n");
	printf("3---输出链表\n");	
	printf("4---插入数据\n");
	printf("5---删除数据\n");
	printf("6---查询数据\n");
	printf("7---编辑数据\n");
	printf("8---链表排序(升序)\n");
	printf("0---退出程序\n");
	printf("温馨提示：1.创建链表时的长度不能超过100，之后可任意添加。\n");
	printf("          2.恰当选择功能3来查看链表输出是否符合所想。\n");
	printf("          3.该程序只能同时存在一个链表，创建新链表会覆盖原链表。\n");
	printf("          4.创建新链表应先销毁原链表。\n");
	printf("          5.有任何建议可发邮件至799952033@qq.com 。\n");
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
				ptr_Node pnode=(ptr_Node)malloc(SIZE);	//<-加花括号的原因 
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
			case 6 :printf("请输入你想要查询的数据： ");
				searchData = get_int();
				if((searchIndex=search(listHead, searchData))!=-1)
					printf("查找成功,位于第%d个结点后\n",searchIndex);
				else
					printf("链表为空或没有该数据！\n");
				break;
			case 7 :printf("请输入你要编辑的数据及位置\n");
				printf("编辑的数据： ");
				editDate = get_int();
				printf("编辑的位置： ");
				editIndex = get_int();
				if(edit(listHead, editIndex, &editDate)==SUCCESS)
					printf("编辑成功！原数据为%d\n",editDate);
				else
					printf("编辑失败，请重试\n");
				break;
			case 8 :if(sort(&listHead)==SUCCESS)
					printf("排序成功!\n");
				else
					printf("排序失败，请重试。\n");
				break;
			case 0 :flag = 1;
				break;
			default :printf("请选择相应功能所对应的数字 0~8 ！\n");
		}
		if(flag==0)
		{
			divide();
			printf("1---创建链表\n");
			printf("2---销毁链表\n");
			printf("3---输出链表\n");
			printf("4---插入数据\n");
			printf("5---删除数据\n");
			printf("6---查询数据\n");
			printf("7---编辑数据\n");
			printf("8---链表排序(升序)\n");
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

		//以下是函数定义 
ptr_Node creat(int *arr, int n)
{
	int i=0;
	ptr_Node p1, p2, head;
	if((p1=p2=head=(ptr_Node)malloc(SIZE))==NULL || arr==NULL)
	{
		printf("内存已满或数组为空！\n");
		return NULL;
	}
	while(i<n)
	{
		if(i==0)
			head->data=arr[i++];
		else
			p1->data=arr[i++];
		p2=p1;
		if((p1=(ptr_Node)malloc(SIZE))==NULL)
		{
			printf("内存已满！\n");
			return NULL;
		}
			p2->next=p1;
	}
	free(p1);
	p2->next=NULL;
	return head;
} 

void destroy(ptr_Node *head)
{
	if(*head==NULL)
	{	
		printf("链表为空！\n");	//已经是空表 
		return;
	}
	ptr_Node p=*head;
	while(*head!=NULL)
	{
		*head=(*head)->next;
		free(p);
		p=*head;
	}
	printf("已销毁!\n");
}

void print(ptr_Node head)
{
	int i=0;
	ptr_Node p=head;
	if(head==NULL)
	{
		printf("链表为空！\n");	//空表则输出出错并返回 
		return;
	}
	while(p!= NULL)
	{
		printf("%3d ",p->data);
		p=p->next;
		if(++i==10)
			putchar(10);		//每10个数换行
	}
	putchar(10);
}

Status insert(ptr_Node *head, ptr_Node node, int index)
{
	if(*head==NULL || node==NULL)
	{
		printf("链表或结点为空！\n");
		return ERROR;
	}
	if(index==0)		//node作为头指针时的情况
	{
		node->next=*head;
		*head=node;
		return SUCCESS; 
	} 
	else				//node不作为头指针时的情况 
	{
		ptr_Node p=*head;
		for(int i=0; i<index-1; i++) //循环到插入位置前
		{ 
			if(p==NULL)
				return ERROR;
			p=p->next;
		}
		if(p->next!=NULL)		//如果插入到最后则要改尾 
			node->next=p->next;
		else
			node->next=NULL;
		p->next=node;
		return SUCCESS;
	}
}

Status deleted(ptr_Node *head, int index, int *data)
{
	if(*head==NULL)
	{
		printf("链表或数据为空！\n");
		return ERROR;
	}
	if(index==0) 	//若删除的是头结点
	{
		*data=(*head)->data;
		*head=(*head)->next; 
		return SUCCESS;
	}
	else			//删除的不是头结点 
	{
		ptr_Node p1=*head,p2;
		for(int i=0; i<index; i++)
		{
			p2=p1;
			p1=p1->next;
		}
		*data=p1->data;
		if(p1->next!=NULL) 
			p2->next=p1->next;
		else
			p2->next=NULL;
		free(p1);
		return SUCCESS;
	}
}

int search(ptr_Node head, int data)
{
	if(head==NULL)
		return -1;
	int i=0;
	ptr_Node p=head;
	while(p!=NULL && p->data!=data)
	{
		p=p->next;
		i++;
	}
	if(p==NULL)		//p=NULL说明链表扫描到了最后也没找到，即不存在该data 
		return -1;
	else
		return i;
}

Status edit(ptr_Node head, int index,int *data)
{
	if(head==NULL || data==NULL)
	{
		printf("链表或数据为空！\n");	//空表则输出出错并返回 
		return ERROR;
	}
	ptr_Node p=head;
	for(int i=0; i<index; i++)	//扫描链表 
		p=p->next;	
	int t=p->data;	//找到后进行交换 
	p->data=*data;	//这里即使传入的index=0情况也相同，可以不分情况 
	*data=t;
	return SUCCESS;
}

Status sort(ptr_Node *head)
{
	if(*head==NULL)
		return ERROR;
	ptr_Node a[100];	//定义一个固定大小的指针数组来存放数据
	int i=0;
	ptr_Node p=*head;
	while(p!=NULL)
	{
		a[i]=p;
		p=p->next;
		i++;		//i也相当于统计了有几个结点 
	}
	for(int j=1;j<i;j++)
		for(int k=j;k>0&& a[k]->data < a[k-1]->data;k--)
		{//插入法对data比较大小进而对Node指针排序 
			ptr_Node t=a[k];
			a[k]=a[k-1];
			a[k-1]=t;
		}
	*head=a[0];
	for(int j=0;j<i-1;j++)	//把排序后的指针重新指定方向 
		a[j]->next=a[j+1];
	a[i-1]->next=NULL;		//处理尾部  
	return SUCCESS;			
							//排序时曾经有个数据排序后被篡改了 
}							//改变数组后又正常了 

void divide(void)
{
	printf("************************************************\n");
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













