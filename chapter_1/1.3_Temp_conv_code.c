#include<stdio.h>
void main()
{
    float fahr, celsius;
    int lower, upper, step;

    printf("***********TEMPERATURE CONVERSION CODE***********");

    upper = 300;
    lower = 0;
    step = 20;

    fahr = lower;
    while( fahr <= upper )
    {
        celsius = (5.0/9.0)*(fahr - 32.0);
        printf("%3.0f %6.1f\n",fahr, celsius);
        fahr = fahr + step;
    }
}
