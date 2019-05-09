#include<stdio.h>
void main()
{
    char c;
    int blanks = 0, tabs = 0, newline = 0;
    scanf("%c",&c);
    while( (c = getchar()) != EOF )
    {
        if( c == ' ' )
            blanks++;
        else if( c == '\t')
            tabs++;
        else if( c == '\n')
            newline++;
    }
    printf("Blanks are = %d\nTabs are = %d\nNewline = %d\n", blanks, tabs, newline);
}
