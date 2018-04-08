#ifndef _linkedlist_H

struct Node;
typedef struct Node * PtrToNode;
typedef PtrToNode LinkedList;
typedef PtrToNode Position;
typedef char ElementType;

LinkedList initLinkedList();
int isEmpty(LinkedList L);
void insertX(LinkedList L, ElementType X);
void deleteX(LinkedList L, ElementType X);
void deleteLinkedList(LinkedList L);
void display(LinkedList L);

#endif

struct Node
{
    ElementType data;
    Position next;
};
