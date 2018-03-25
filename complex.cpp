/*******************************************
    Description: complex arithmetic
    Date: 2018-03-26 01:07:00
    Author: Ming Yi
    Student ID: 17080701008
*******************************************/

#include <iostream>
using namespace std;

//declaring a complex structure
typedef struct
{
    int real;
    int imag;
}complex;

//overloaded operator: +, -, *
complex operator + (complex &a, complex &b);
complex operator - (complex &a, complex &b);
complex operator * (complex &a, complex &b);

int main()
{
    complex comp1, comp2, result;//declaring a variable of complex structure type
    cout << "Please enter the real and imaginary parts of a complex number(integer): ";
    cin >> comp1.real >> comp1.imag;
    cout << "Please enter the real and imaginary parts of a complex number(integer): ";
    cin >> comp2.real >> comp2.imag;
    char c_operator;//declaring the variable of operator
    cout << "Please enter the operator: ";
    cin >> c_operator;

    //Find the corresponding operator operation.
    //When an incorrect operator is entered, 
    //give a prompt and ask for it again.
    while(true)
    {
        if(c_operator == '+')
        {
            result = comp1 + comp2;
            break;
        }
        else if (c_operator = '-')
        {
            result = comp1 - comp2;
            break;
        }
        else if(c_operator = '*')
        {
            result = comp1 * comp2;
            break;
        }
        else
        {
            cout << "Sorry, your entered an incorrect operator!"
                 << "Please try again." << endl;
            continue;
        }
    }
    //If the complex imaginary part is less than zero, 
    //the plus sign will not be printed
    if(result.imag >= 0)
        cout << "The result of the operation is: " << result.real 
             << "+" << result.imag << "i" << endl;
    else
        cout << "The result of the operation is: " << result.real 
             << result.imag << "i" << endl;
     
    return 0;
}

complex operator + (complex &a, complex &b)
{
    complex temp;
    temp.real = a.real + b.real;
    temp.imag = a.imag + b.imag;
    return temp;
}

complex operator - (complex &a, complex &b)
{
    complex temp;
    temp.real = a.real - b.real;
    temp.imag = a.imag - b.imag;
    return temp;
}

complex operator * (complex &a, complex &b)
{
    complex temp;
    temp.real = a.real * b.real - a.imag * b.imag;
    temp.imag = a.imag * b.real + a.real * b.imag;
    return temp;
}
