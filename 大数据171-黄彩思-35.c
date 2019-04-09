/*
    **                                                                  **
    **               ���ߣ��Ʋ�˼                                       **
    **               �༶��������171                                    **
    **               ϵͳ���ƣ�ҽԺ��������ϵͳ2.0                      **
    **               �汾��Ϣ��5.0                                      **
    **               ����ʱ�䣺2019-03-22                               **
    **
*/



#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef int elemtype;
typedef struct SequenQueue		                                    //˳����е����Ͷ���
{
	elemtype data[MAXSIZE];
	int front;
	int rear;
}SequenQueue;

SequenQueue * Init_SequenQueue()	                                //��ʼ������
{
	SequenQueue * Q;
	Q=(SequenQueue *)malloc(sizeof(SequenQueue));
	if(Q!=NULL)
	{
		Q->front=0;
		Q->rear=0;
	}
	return Q;
}

int SequenQueue_Empty(SequenQueue * Q)	                            //�����п�
{
	if(Q->front==Q->rear)	return 1;
	else			return 0;
}

int SequenQueue_Full(SequenQueue * Q)	                            //��������
{
	if((Q->rear+1)%MAXSIZE==Q->front)	return 1;
	else				return 0;
}

int SequenQueue_Length(SequenQueue * Q)	                            //���г���
{
	return((Q->rear-Q->front+MAXSIZE)%MAXSIZE);
}

int Enter_SequenQueue(SequenQueue * Q,elemtype x)                   	//���
{
	if(SequenQueue_Full(Q))	return 0;
	Q->data[Q->rear]=x;
	Q->rear=(Q->rear+1)%MAXSIZE;
	return 1;
}

int Delete_SequenQueue(SequenQueue * Q,elemtype * x)	                //����
{
	if(Q->front==Q->rear)	return 0;
	else
	{
		*x=Q->data[Q->front];
		Q->front=(Q->front+1)%MAXSIZE;
		return 1;
	}
}

int GetFront_SequenQueue(SequenQueue * Q,elemtype *x)                       	//ȡ��ͷԪ��
{
	if(Q->front==Q->rear)	return 0;
	else
	{
	    *x=Q->data[Q->front];
		return 1;
	}
}


void main()                                                           //main function
{
    void menu();                                                       //menu function
    void ESQ(SequenQueue * Q, int i);                                  //��Ӻ���
    void DSQ(SequenQueue * Q, int * i);                                 //���Ӻ���
    void SQ_L(SequenQueue * Q);                                           //���г���

    struct SequenQueue *Q=Init_SequenQueue();                            //create queue.initiation queue
    struct SequenQueue *Q2=Init_SequenQueue();                          //create queue2.initiation queue2.

    elemtype z=1;                                                       //����ϵͳ����ѭ����������
    elemtype ye=0;                                                      //ϵͳ�˵���ѡ��
    elemtype j=1;                                                       //���Ԫ��
    elemtype k=0;                                                       //����Ԫ��
    elemtype l=0;                                                       //ѡ��Һŵ����ȼ��ж�

    while(z)
    {
        menu();
        scanf("%d",&ye);
        switch(ye)
        {
            case 1:
                printf("���������Һŵ����ȼ�1-2��������ȡ����:");
                scanf("%d",&l);
                if(l==1)
                {
                    Enter_SequenQueue(Q,j);
                    j=j+1;
                    printf("����ǰ�������ȼ�Ϊ1�ĵ�%dλ��\n",SequenQueue_Length(Q));
                    printf("��ǰ�Ŷӵ�����Ϊ%d�ˣ����У�\n���ȼ�1�ģ�%d��\n���ȼ�2�ģ�%d��\n\n",SequenQueue_Length(Q)+SequenQueue_Length(Q2),SequenQueue_Length(Q),SequenQueue_Length(Q2));
                }
                else if(l==2)
                {
                    Enter_SequenQueue(Q2,j);
                    j=j+1;
                    printf("����ǰ�������ȼ�Ϊ2�ĵ�%dλ��\n",SequenQueue_Length(Q2));
                    printf("��ǰ�Ŷӵ�����Ϊ%d�ˣ����У�\n���ȼ�1�ģ�%d��\n���ȼ�2�ģ�%d��\n\n",SequenQueue_Length(Q)+SequenQueue_Length(Q2),SequenQueue_Length(Q),SequenQueue_Length(Q2));
                }
                else break;
                break;                                                                                  //in queue function
            case 2:
                if(SequenQueue_Empty(Q)&&SequenQueue_Empty(Q2))                                        //�ж��Ƿ������Ŷ�
                    {
                        printf("��ǰ�����Ŷ�\n\n");
                    }
                else if(SequenQueue_Empty(Q2))
                {
                    GetFront_SequenQueue(Q,&k);
                    printf("����Ҫ��ϵ������ȼ�Ϊ1�ģ�%d��\n\n",k);
                    Delete_SequenQueue(Q,&k);
                }
                else
                {
                    GetFront_SequenQueue(Q2,&k);
                    printf("����Ҫ��ϵ������ȼ�Ϊ2�ģ�%d��\n\n",k);
                    Delete_SequenQueue(Q2,&k);
                }
                break;
            case 3:
                printf("��ǰ�Ŷӵ�����Ϊ%d�ˣ����У�\n���ȼ�1�ģ�%d��\n���ȼ�2�ģ�%d��\n\n",SequenQueue_Length(Q)+SequenQueue_Length(Q2),SequenQueue_Length(Q),SequenQueue_Length(Q2));
                break;
            case 4:
                z=0;
                printf("\n*********** see you again! ***********\n\n");
                break;
            default :
                printf("your input error!Please re-enter.\n");
        }
        if(SequenQueue_Empty(Q)&&SequenQueue_Empty(Q2))                                        //�ж��Ƿ������Ŷӣ����������������ϳ����˵�����
            {
                j=1;
                k=0;
            }
    }
}

void menu()                                                                                         //menu function
{
    printf("*************************************************************\n");
    printf("**********************   1.�ŶӹҺ�   ***********************\n");
    printf("**********************   2.ҽ������   ***********************\n");
    printf("**********************   3.��ǰ����   ***********************\n");
    printf("**********************   4.�˳�ϵͳ   ***********************\n");
    printf("*************************************************************\n");
    printf("Please enter your choice:");
}
