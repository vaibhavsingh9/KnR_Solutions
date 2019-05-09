#include<stdio.h>
void main()
{
    char c;

    while((c = getchar()) != EOF)
    {
        if( c == '\t' )
        {
            putchar('\\');
            putchar('t');
        }
        else if( c == '\b' || c == 127 || c == 8 )
        {

            putchar('\\');
            putchar('b');
        }
        else if( c == '\\' )
        {
            putchar('\\');
            putchar('\\');
        }
        else
            putchar(c);
    }
    c = getch();
}
