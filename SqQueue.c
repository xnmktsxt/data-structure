/*********************************************
 * filename: sqQueue.c
 * description: 队列的基本操作
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

Status InitQueue(SqQueue *q);//初始化队列
int QueueLength(SqQueue *q);//计算队列的长度
Status EnQueue(SqQueue *q, QElemType e);//插入数据e
Status DeQueue(SqQueue *q);//删除队尾数据
void Display(SqQueue *q);//显示队列中的数据

int main(void)
{
    int data;//要插入的数据
    int opNumber;//要选择的操作
    SqQueue q;

    InitQueue(&q);
    printf("请输入操作对应的数字:");
    puts("1.添加数据 2.删除数据 (按ctrl-c退出程序)");
     
    while(scanf("%d", &opNumber) == 1)
    {
        if(1 == opNumber)
        {
            printf("请输入要插入的数据:");
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
            puts("错误的操作！");
        }
        printf("请输入操作对应的数字:");
        puts("1.添加数据 2.删除数据");
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
	printf("队列中的元素: ");
	for(i = 0; i < QueueLength(q); ++i)
        printf("%d ", (*q).base[i]);
    puts("\n");
}



