/**
 * Dileep Reddy
 * Lab 10 Post-Lab
 * 10/28/2021
 * Program to emulate the strcpy function
 */
#include <stdio.h>

char* strcpy(char* strDest, const char* strSrc){
    char* save = strDest;
    while(*strSrc){
        *strDest++ = *strSrc++;
    }
    *strDest = '\0';
    return save;
}

int main(int argc, char const *argv[])
{
    char a[] = "source", b[] = "destination";
    printf("Before strcpy: %s %s\n", a, b);
    strcpy(a, b);
    printf("After strcpy: %s %s\n", a, b);
    return 0;
}
