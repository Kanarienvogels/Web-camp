/*QG�ĵ�һ����ҵ*/
/*��������йز���      ��д�����޻�*/
/* ������׽��Ϊ��1����㣬�׽��ǰΪ��0�����*/
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

		//�������� 
ptr_Node creat(int *arr, int n);
void destroy(ptr_Node *head);
void print(ptr_Node head);
Status insert(ptr_Node *head, ptr_Node node, int index);
Status deleted(ptr_Node *head, int index, int *data);
int search(ptr_Node head, int data);
Status edit(ptr_Node head, int index,int *data);
Status sort(ptr_Node *head);
int get_int();	// ��ȡһ��int�����룬�޳�����ȷ������
void divide(void);	//�ָ�������ʹ�������

int main(void)	//�����������Բ��� 
{
	int num, len, flag=0;
	int a[100];
	ptr_Node listHead = NULL;
	int insertIndex, deletedData, deletedIndex;
	int editDate, editIndex, searchData, searchIndex;
	divide();
	printf("������Ĳ��� �汾2.0\n");
	printf("1---��������\n");
	printf("2---��������\n");
	printf("3---�������\n");	
	printf("4---��������\n");
	printf("5---ɾ������\n");
	printf("6---��ѯ����\n");
	printf("7---�༭����\n");
	printf("8---��������(����)\n");
	printf("0---�˳�����\n");
	printf("��ܰ��ʾ��1.��������ʱ�ĳ��Ȳ��ܳ���100��֮���������ӡ�\n");
	printf("          2.ǡ��ѡ����3���鿴��������Ƿ�������롣\n");
	printf("          3.�ó���ֻ��ͬʱ����һ����������������Ḳ��ԭ����\n");
	printf("          4.����������Ӧ������ԭ����\n");
	printf("          5.���κν���ɷ��ʼ���799952033@qq.com ��\n");
	divide();
	printf("��ѡ���������������Ҫ�Ĺ��ܣ� ");
	num = get_int();
	while(num != 0)
	{
		switch(num)
		{
			case 1 :printf("����������Ҫ��������ݵĸ����� ");
				len = get_int();
				printf("���������ݣ�");
				for(int i = 0; i < len; i++)
					a[i]=get_int();
				if((listHead=creat(a, len))!=NULL)
				{
					flag = 0;
					printf("�����ɹ���\n");
				}
				else
					printf("����ʧ�ܣ������ԡ�\n");
				break;
			case 2 :destroy(&listHead);
				break;
			case 3 :print(listHead);
				break;
			case 4 :
			{//ע�⣡�����˴��Ĳ�����һ��Ҫ��malloc �������ٴβ���ʱ��ͬһ��ַ����� 
				printf("��������Ҫ��������ݼ�λ��\n");//debug�˺ܾ�... 
				printf("��������ݣ�");			 
				ptr_Node pnode=(ptr_Node)malloc(SIZE);	//<-�ӻ����ŵ�ԭ�� 
				pnode->data = get_int();		//�ֲ�����ֻ���ڵ�ǰcase������ 
				printf("�����λ��: ");
				insertIndex = get_int();
				if(insert(&listHead, pnode, insertIndex)==SUCCESS)
					printf("����ɹ���\n");
				else 
					printf("����ʧ�ܣ������ԡ�\n");
				break;
			}
			case 5 :printf("����������Ҫɾ�������ݵ�λ�ã� ");
				deletedIndex = get_int();
				if(deleted(&listHead, deletedIndex, &deletedData)==SUCCESS)
					printf("��ɾ����%d����������ݣ�ԭ����Ϊ%d\n", deletedIndex, deletedData);
				else
					printf("ɾ��ʧ�ܣ������ԡ�\n");
				break;
			case 6 :printf("����������Ҫ��ѯ�����ݣ� ");
				searchData = get_int();
				if((searchIndex=search(listHead, searchData))!=-1)
					printf("���ҳɹ�,λ�ڵ�%d������\n",searchIndex);
				else
					printf("����Ϊ�ջ�û�и����ݣ�\n");
				break;
			case 7 :printf("��������Ҫ�༭�����ݼ�λ��\n");
				printf("�༭�����ݣ� ");
				editDate = get_int();
				printf("�༭��λ�ã� ");
				editIndex = get_int();
				if(edit(listHead, editIndex, &editDate)==SUCCESS)
					printf("�༭�ɹ���ԭ����Ϊ%d\n",editDate);
				else
					printf("�༭ʧ�ܣ�������\n");
				break;
			case 8 :if(sort(&listHead)==SUCCESS)
					printf("����ɹ�!\n");
				else
					printf("����ʧ�ܣ������ԡ�\n");
				break;
			case 0 :flag = 1;
				break;
			default :printf("��ѡ����Ӧ��������Ӧ������ 0~8 ��\n");
		}
		if(flag==0)
		{
			divide();
			printf("1---��������\n");
			printf("2---��������\n");
			printf("3---�������\n");
			printf("4---��������\n");
			printf("5---ɾ������\n");
			printf("6---��ѯ����\n");
			printf("7---�༭����\n");
			printf("8---��������(����)\n");
			printf("0---�˳�����\n");
			printf("��ѡ���������������Ҫ�Ĺ��ܣ�");
			num = get_int();
		}
		else
			break;
	}
	printf("���˳���\n");
	return 0;
}

		//�����Ǻ������� 
ptr_Node creat(int *arr, int n)
{
	int i=0;
	ptr_Node p1, p2, head;
	if((p1=p2=head=(ptr_Node)malloc(SIZE))==NULL || arr==NULL)
	{
		printf("�ڴ�����������Ϊ�գ�\n");
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
			printf("�ڴ�������\n");
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
		printf("����Ϊ�գ�\n");	//�Ѿ��ǿձ� 
		return;
	}
	ptr_Node p=*head;
	while(*head!=NULL)
	{
		*head=(*head)->next;
		free(p);
		p=*head;
	}
	printf("������!\n");
}

void print(ptr_Node head)
{
	int i=0;
	ptr_Node p=head;
	if(head==NULL)
	{
		printf("����Ϊ�գ�\n");	//�ձ�������������� 
		return;
	}
	while(p!= NULL)
	{
		printf("%3d ",p->data);
		p=p->next;
		if(++i==10)
			putchar(10);		//ÿ10��������
	}
	putchar(10);
}

Status insert(ptr_Node *head, ptr_Node node, int index)
{
	if(*head==NULL || node==NULL)
	{
		printf("�������Ϊ�գ�\n");
		return ERROR;
	}
	if(index==0)		//node��Ϊͷָ��ʱ�����
	{
		node->next=*head;
		*head=node;
		return SUCCESS; 
	} 
	else				//node����Ϊͷָ��ʱ����� 
	{
		ptr_Node p=*head;
		for(int i=0; i<index-1; i++) //ѭ��������λ��ǰ
		{ 
			if(p==NULL)
				return ERROR;
			p=p->next;
		}
		if(p->next!=NULL)		//������뵽�����Ҫ��β 
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
		printf("���������Ϊ�գ�\n");
		return ERROR;
	}
	if(index==0) 	//��ɾ������ͷ���
	{
		*data=(*head)->data;
		*head=(*head)->next; 
		return SUCCESS;
	}
	else			//ɾ���Ĳ���ͷ��� 
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
	if(p==NULL)		//p=NULL˵������ɨ�赽�����Ҳû�ҵ����������ڸ�data 
		return -1;
	else
		return i;
}

Status edit(ptr_Node head, int index,int *data)
{
	if(head==NULL || data==NULL)
	{
		printf("���������Ϊ�գ�\n");	//�ձ�������������� 
		return ERROR;
	}
	ptr_Node p=head;
	for(int i=0; i<index; i++)	//ɨ������ 
		p=p->next;	
	int t=p->data;	//�ҵ�����н��� 
	p->data=*data;	//���Ｔʹ�����index=0���Ҳ��ͬ�����Բ������ 
	*data=t;
	return SUCCESS;
}

Status sort(ptr_Node *head)
{
	if(*head==NULL)
		return ERROR;
	ptr_Node a[100];	//����һ���̶���С��ָ���������������
	int i=0;
	ptr_Node p=*head;
	while(p!=NULL)
	{
		a[i]=p;
		p=p->next;
		i++;		//iҲ�൱��ͳ�����м������ 
	}
	for(int j=1;j<i;j++)
		for(int k=j;k>0&& a[k]->data < a[k-1]->data;k--)
		{//���뷨��data�Ƚϴ�С������Nodeָ������ 
			ptr_Node t=a[k];
			a[k]=a[k-1];
			a[k-1]=t;
		}
	*head=a[0];
	for(int j=0;j<i-1;j++)	//��������ָ������ָ������ 
		a[j]->next=a[j+1];
	a[i-1]->next=NULL;		//����β��  
	return SUCCESS;			
							//����ʱ�����и���������󱻴۸��� 
}							//�ı�������������� 

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
			putchar(ch);			//ɾ�����������
		printf("����һ��������\n������һ������ֵ" 
		       "���� 25,-178 ���� 3: ");
	}
return input;
}













