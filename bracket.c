/************************************************************************
 * Decription: use the stack to verify that paraentheses match
 * Author : Ming Yi
 * Date: 2018-04-24 15:00:00
 * *********************************************************************/

#define INIT_STACK_SIZE 100
#define SIZE_INCREMENT 10
#define ERROR -1
#define OK 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	
typedef char elemType;

typedef struct
{
	elemType *base;
	elemType *top;
	int stacksize;
}SqStack;

//stack function
void init(SqStack *s);
int pop(SqStack *s);
void push(SqStack *s, elemType e);
int getLength(SqStack *s);
void matching(char *);

void init(SqStack *s)
{
    //initial allocation of 100 spaces 
	(*s).base = (elemType *)malloc(INIT_STACK_SIZE * sizeof(elemType));
	if((*s).base == NULL)
	{
		printf("Lack of space!");
		exit(1);
	}
	(*s).top = (*s).base;
	(*s).stacksize = INIT_STACK_SIZE;
}

void push(SqStack *s, elemType e)
{
    //stack full, append storage space 
	if((*s).top - (*s).base >= (*s).stacksize)
	{
		(*s).base = (elemType *)realloc((*s).base, (*s).stacksize * sizeof(elemType));
		if((*s).base == NULL)
		{
			printf("Lack of space!");
			exit(1);
		}
		(*s).top = (*s).base;
		(*s).stacksize = INIT_STACK_SIZE + SIZE_INCREMENT;
	}
	*(*s).top++ = e;
}

int pop(SqStack *s)
{
	if((*s).top == 	(*s).base)
		return ERROR;
	--(*s).top;
	return OK;
}

//stack length == 0 ---> stack is empty
int getLength(SqStack *s)
{
    return (*s).top - (*s).base;
}

//determine if parentheses match
void matching(char * brackets)
{
    SqStack s;
    int i, stackState = 0;//stackState is matching status 
    init(&s);

    for(i = 0; i < strlen(brackets); ++i)
    {
        //push the element if it's a left parenthesis
        if(brackets[i] == '{' || brackets[i] == '[' || brackets[i] == '(')
            push(&s, brackets[i]);
        
        //if the closing bracket is compared to the stack top data
        //pop operation of stack if it is the corresponding braket
        if(brackets[i] == '}')
        {
            if(*(s.top-1) == '{')
                pop(&s);
            else
            {
                stackState = -1;
                break;
            }
        }
        if(brackets[i] == ']')
        {
            if(*(s.top-1) == '[')
                pop(&s);
            else
            {
                stackState = -1;
                break;
            }
        }
        if(brackets[i] == ')')
        {
            if(*(s.top-1) == ')')
                pop(&s);
            else
            {
                stackState = -1;
                break;
            }
        }
    }

    //determine the final match status
    if(stackState == 0 && getLength(&s) == 0)
        printf("Matching.\n");
    else
        printf("Mismatching.\n");
}

int main(void)
{
    elemType brackets[15];
    scanf("%s", brackets);
    matching(brackets);

	return 0;
}
