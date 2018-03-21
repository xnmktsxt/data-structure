/****************************************************
    Discription: About calculation of the complex number.
    Author: Ming
    Date: 2018-03-19
****************************************************/
#include <stdio.h>

//declare a complex struct
typedef struct
{
    int real;//real part
    int imag;//imag part
}complex;

//our add, subtract, multiply and divide the function prototype
complex add_complex(complex a, complex b);
complex sub_complex(complex a, complex b);
complex mult_complex(complex a, complex b);



int main(void)
{
    complex comp1;//define a variable that 'complex' struct
    complex comp2;
    complex result_comp;//result that the calculation of comp1 and comp2
    printf("Input a complex number, please!");
    puts("");
    printf("real part:");
    scanf("%d", &comp1.real);//read the real part of comp1
    printf("imag part:");
    scanf("%d", &comp1.imag);//read the imag part of comp1
    printf("You have been input a complex number:");
    if(comp1.imag >= 0)
        printf("%d+%di\n", comp1.real, comp1.imag);//print the complex number
    else
        printf("%d%di\n", comp1.real, comp1.imag);

    printf("Input another complex number, please!");
    puts("");
    printf("real part:");
    scanf("%d", &comp2.real);//read the real part of comp2
    printf("imag part:");
    scanf("%d", &comp2.imag);//read the imag part of comp2
    printf("You have been input another complex number:");
    if (comp2.imag >= 0)
        printf("%d+%di\n", comp2.real, comp2.imag); //print the complex number
    else
        printf("%d%di\n", comp2.real, comp2.imag);

    //print four arithmetic operation

    result_comp = add_complex(comp1, comp2);
    if(result_comp.imag >= 0)
        printf("Addition operation result:%d+%di\n", result_comp.real, result_comp.imag);
    else
        printf("Addition operation result:%d%di\n", result_comp.real, result_comp.imag);

    result_comp = sub_complex(comp1, comp2);
    if (result_comp.imag >= 0)
        printf("Subtract operation result:%d+%di\n", result_comp.real, result_comp.imag);
    else
        printf("Subtract operation result:%d%di\n", result_comp.real, result_comp.imag);

    result_comp = mult_complex(comp1, comp2);
    if (result_comp.imag >= 0)
        printf("Mutiply operation result:%d+%di\n", result_comp.real, result_comp.imag);
    else
        printf("Multiply operation result:%d%di\n", result_comp.real, result_comp.imag);

    return 0;
}

complex add_complex(complex a, complex b)
{
    complex new_comp;
    new_comp.real = a.real + b.real;
    new_comp.imag = a.imag + b.imag;
    return new_comp;
}

complex sub_complex(complex a, complex b)
{
    complex new_comp;
    new_comp.real = a.real - b.real;
    new_comp.imag = a.imag - b.imag;
    return new_comp;
}
complex mult_complex(complex a, complex b)
{
    complex new_comp;
    new_comp.real = a.real * b.real - a.imag * b.imag;
    new_comp.imag = a.imag * b.real + a.real * b.imag;
    return new_comp;
}