/*********************************************
 * filename: sqQueue.c
 * description: ���еĻ�������
 * data: 2018-05-27 13:00:00
 * author: Ming Yi
 * ******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAXQSIZE 100
#define OK 0
#define OVERFLOW -2
#define ERROR -1

typedef int Status;
typedef int QElemType;
typedef struct
{
    QElemType *base;
    int front;
    int rear;
}SqQueue;

Status InitQueue(SqQueue *q);//��ʼ������
int QueueLength(SqQueue *q);//������еĳ���
Status EnQueue(SqQueue *q, QElemType e);//��������e
Status DeQueue(SqQueue *q);//ɾ����β����
void Display(SqQueue *q);//��ʾ�����е�����

int main(void)
{
    int data;//Ҫ���������
    int opNumber;//Ҫѡ��Ĳ���
    SqQueue q;

    InitQueue(&q);
    printf("�����������Ӧ������:");
    puts("1.������� 2.ɾ������ (��ctrl-c�˳�����)");
     
    while(scanf("%d", &opNumber) == 1)
    {
        if(1 == opNumber)
        {
            printf("������Ҫ���������:");
            scanf("%d", &data);
            EnQueue(&q, data);
            Display(&q);
        }
        else if(2 == opNumber)
        {
            DeQueue(&q);
            Display(&q);
        }
        else
        {
            puts("����Ĳ�����");
        }
        printf("�����������Ӧ������:");
        puts("1.������� 2.ɾ������");
    }
    return 0;
}

Status InitQueue(SqQueue *q)
{
    (*q).base = (QElemType *)malloc(MAXQSIZE * sizeof(QElemType));
    if(!(*q).base) exit(OVERFLOW);
    (*q).front = (*q).rear = 0;
    return OK;
}

int QueueLength(SqQueue *q)
{
   return ((*q).rear - (*q).front + MAXQSIZE) % MAXQSIZE;
}

Status EnQueue(SqQueue *q, QElemType e)
{
    if(((*q).rear + 1) % MAXQSIZE == (*q).front) return ERROR;
    (*q).base[(*q).rear] = e;
    (*q).rear = ((*q).rear + 1) % MAXQSIZE;
    return OK;
}

Status DeQueue(SqQueue *q)
{
    if((*q).front == (*q).rear) return ERROR;
    (*q).front = ((*q).front + 1) % MAXQSIZE;
    return OK;
}

void Display(SqQueue *q)
{
	int i;
	printf("�����е�Ԫ��: ");
	for(i = 0; i < QueueLength(q); ++i)
        printf("%d ", (*q).base[i]);
    puts("\n");
}



