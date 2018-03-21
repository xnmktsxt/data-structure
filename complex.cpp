/***********************************************
 * Discription: four operation of plural numbers
 * Date: 2018-03-20 20:30:00
 * Author: Ming Yi
 ***********************************************/
#include <iostream>
using namespace std;

class complex
{
    int real;//real part
    int imag;//imaginary part

    complex add(complex a, complex b)
    {
        complex temp;
        temp.imag = a.imag + b.imag;
        temp.real = a.real + b.real;
        return temp;
    }

    complex sub(complex a, complex b)
    {
        complex temp;
        temp.imag = a.imag - b.imag;
        temp.real = a.real - b.real;
        return temp;
    }


};

int main()
{
    cout << "Enter a plural numbers, please." << endl;
    cout << "Real part:";
    complex comp1;//instantiate the first plural
    cin >> comp1.real;
    cout << "Imaginary part:";
    cin >> comp1.imag;
    
    

    return 0;
}




