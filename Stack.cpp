#include <iostream>

template<typename elemType>
class Stack
{
public:
    using position = elemType *; 
    Stack();
    Stack(int);
    ~Stack();
    int stackLength();//return the length of the stack.    
    bool isEmpty();
    void push(elemType);
    elemType pop();
    int stacksize;
private:
    position base;
    position top;
   
};

template<typename elemType>
Stack<elemType>::Stack(): stacksize(10)
{
    //create a stack with a default capacity of 10
    base = new (std::nothrow) elemType[stacksize];
    if(base == nullptr)
        std::cerr << "Allocating memory failed!";
    top = base;
}

template<typename elemType>
Stack<elemType>::Stack(int s): stacksize(s)
{
    //create a stack of custom capacity
    base = new (std::nothrow) elemType[stacksize];
    if(base == nullptr)
        std::cerr << "Allocating memory failed!";
    top = base;
}

template<typename elemType>
Stack<elemType>::~Stack()
{
    delete[] base;
}

template<typename elemType>
bool Stack<elemType>::isEmpty()
{
    return base == top ? true : false;
}

template<typename elemType>
int Stack<elemType>::stackLength()
{
    return top - base;
}

template<typename elemType>
void Stack<elemType>::push(elemType data)
{
    if(top - base >= stacksize)    
    {
        std::cerr << "Stack full!";
        exit(1);
    }
    *(top++) = data;
}

template<typename elemType>
elemType Stack<elemType>::pop()
{
    if(top == base)
        std::cerr << "Stack empty!";
    return *--top;
}
