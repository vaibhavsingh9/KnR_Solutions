//#include<stdio.h>
//#define MAXLINE 1000
//
//int mgetline(char line[],int maxline);
//int any(char s1[],char s2[]);
//
//int main(void)
//{
//    char s1[MAXLINE],s2[MAXLINE];
//    int val;
//
//    /* Give the first string s1 */
//
//    mgetline(s1,MAXLINE);
//
//    /* Give the second string s2 */
//
//    mgetline(s2,MAXLINE);
//
//    val = any(s1,s2);
//
//    printf("%d",val);
//
//    return 0;
//}
//
//int mgetline(char s[],int lim)
//{
//    int i,c;
//    for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n';++i)
//        s[i]=c;
//
//    if(c=='\n')
//        s[i++]=c;
//    s[i]='\0';
//}
//
//int any(char s1[],char s2[])
//{
//    int i,j,check_next_char;
//
//    check_next_char=1;
//
//    for(i=0;s1[i]!='\0'&& (check_next_char);)
//    {
//        // iterate through s2 while trying to find matching character from s1
//        for(j=0;s2[j]!='\0'&& (s1[i]!=s2[j]);++j)
//            ; // continue
//
//        if(s2[j]=='\0') {
//            check_next_char=1;
//            i++; // go for the next char in s1
//        }
//        else
//            check_next_char=0; // match found
//    }
//
//    if(s1[i]=='\0')
//        return -1;
//    else
//        return i;
//}
//
#include "stdio.h"
#include "string.h"
#include "Global_Parameters.h"

void readStrings()
{
	FILE *p;
	int index;

	p = fopen("C:\\Users\\vaibhav\\Desktop\\C_lang\\KnR\\Chapter-2\\2.5_InputCase.txt","r");

	if(!p)
	{
		printf("\n\tFile Not Found !");
		return;
	}

	while( ! (feof(p)) )
	{
		index = readMainString(p);

		mainstring[index] = '\0';

		index = readProcessorString(p);

		string[index] = '\0';
	}
}

int displayOccurences()
{
	int index = 0;

	while(string[index] != '\0')
	{
		if( isAlreadyDisplayed(index , string[index]) )
		{
			++index;
			continue;
		}

		display(string[index]);

		++index;
	}

	if( errorcounter == 0 )
		return FOUND;
	else
		return NOTFOUND;
}

void setFirstOccurence(char character)
{
	int index = 0;

	if(character == ' ')
		return;

	while(mainstring[index] != '\0')
	{
		if(mainstring[index] == character)
		{
			occurence[index] = 1;
			break;
		}

		++index;
	}
}

int isCharacterAlreadyRead(char character_read)
{
	static int index = 0;
	int i = 0;

	while(i < index)
	{
		if(charactersread[i] == character_read)
			return 1;
		else
			++i;
	}

	charactersread[index++] = character_read;

	return 0;
}

int main()
{
	int index = 0, no_occurences;

	readStrings();

	printf("%s\n%s\n\n", mainstring, string);

	while(string[index] != '\0')
	{
		if( ! (isCharacterAlreadyRead(string[index])) )

			setFirstOccurence(string[index]);

		++index;
	}

	no_occurences = displayOccurences();

	if( no_occurences )
		printf("%d\n", no_occurences);

	return 0;
}
