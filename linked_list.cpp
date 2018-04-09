#include <iostream>
#include "linkedlist.h"

using namespace std;

int main()
{
    LinkedList L = initLinkedList();
    for(int i = 'z'; i >= 'a'; --i)
        insertX(L, i);
    cout << "Curent list data: ";
    display(L);
    cout << endl;
    deleteX(L, 'c');
    display(L); 
    cout << endl;
    deleteLinkedList(L);
    display(L);

   return 0;
}

LinkedList initLinkedList()
{
    LinkedList L;
    L = (Node *)malloc(sizeof(Node));
    L -> next = NULL;
    return L;
}

int isEmpty(LinkedList L)
{
    return L->next == NULL;
}

void insertX(LinkedList L, ElementType X)
{
    Position p = (Node *)malloc(sizeof(struct Node));
    if(p == NULL)
        cout << "Out of space!!!" << endl;
    p -> data = X;
    p -> next = L -> next;
    L -> next = p; 
}

void deleteX(LinkedList L, ElementType X)
{
    Position temp = L -> next;
    Position pre = L;
    while(temp -> data != X)
    {
        pre = temp;
        temp = temp -> next;
    }
    pre -> next = temp -> next;    
    free(temp);
}

void deleteLinkedList(LinkedList L)
{
    Position p, q;
    p = L -> next;
    while(p)
    {
        q = p;
        free(p);
        p = q -> next;
    }
    L -> next = NULL; 
}

void display(LinkedList L)
{
    Position current;
    current = L -> next;

    if(isEmpty(L))
        cout << "Empty linked list." << endl;
    else
    {
        while(current != NULL)
        {
            cout << current -> data << " ";
            current = current -> next;
        }
    }
}
                  
