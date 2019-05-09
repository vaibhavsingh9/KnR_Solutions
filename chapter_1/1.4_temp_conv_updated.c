#include<stdio.h>
void main()
{
    float celsius, fahr;
    int upper, lower, step;

    upper = 300;
    lower = 0;
    step = 20;


    while(celsius <= upper)
    {
        fahr = ((celsius*9.0)/5.0) + 32.0;
        printf("%3.0f %6.1f\n",celsius, fahr);
        celsius = celsius + step;
    }
}
