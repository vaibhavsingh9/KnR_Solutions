#include<stdio.h>
void main()
{
    int c;
    while((c = getchar()) != EOF)
    {

        if( c == ' ')
        {
            while((c = getchar()) == ' ')
                ;
            putchar(' ');
        }
        putchar(c);
    }
}
