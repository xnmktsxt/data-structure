/********************************************************
 * Description: decimal conversion into binary or othre.
 * Author: Ming Yi
 * Data: 2018-04-22 13:00:00
 * *****************************************************/ 
#include <iostream>
#include "Stack.cpp"

using namespace std;

void conversion(int, int);
string mapping(int);//convert numbers into words.

int main()
{
    cout << "Please enter an integer to convert: ";
    int intToBeConverted;
    cin >> intToBeConverted;
    cout << "Please enter the system(integer) you want to go to: "; 
    int system;
    cin >> system;
    cout << intToBeConverted << "(decimal) convesion to "
         << mapping(system) << " is: "; 
    conversion(intToBeConverted, system); 
    cout << endl; 
    return 0;
}

void conversion(int intToBeConverted, int system)
{
    //Back up the data to be converted,
    //calculate the required stack capacity,
    //and create a stack of that capacity.
    int size = 1, backupITBC = intToBeConverted;
    while(intToBeConverted /= system)
        if(intToBeConverted)
            ++size;
    Stack<int> myStack(size);

    while(backupITBC)
    {
        myStack.push(backupITBC % system);
        backupITBC /= system;
    }

    while(! myStack.isEmpty())
    {
        cout << myStack.pop();
    }
}

string mapping(int system)
{
    if(system == 8)
        return "octal";
    else if(system == 16)
        return "hexadeciaml";
    else if(system == 2)
        return "binary";
    else
        return "unknow number of systems";
}
