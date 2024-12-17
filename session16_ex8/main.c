#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Reverse(char *input, char *reverse);
int main()
{
    char  inputString[20],reverseString[20];
    fgets(inputString,sizeof(inputString),stdin);
    inputString[strcspn(inputString, "\n")] = '\0';
    Reverse(inputString,reverseString);
    printf("chuoi truoc : %s\n",inputString);
    printf("chuoi sau: %s\n",reverseString);
    printf("Hello world!\n");
    return 0;
}
void Reverse(char *input, char *reverse){
    char *begin=input;
    char *end=input+strlen(input)-1;
    while(end>=begin){
        *reverse=*end;
        reverse++;
        end--;
    }
    *reverse='\0';
}
