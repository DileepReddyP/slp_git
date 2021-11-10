#include <stdio.h>
/**
 * Dileep Reddy
 * Lab 9
 * 10/23/2021
 * Program to read and print most frequent character in supplied file
 */
int main(int argc, char const *argv[])
{
    FILE *fp;
    char buff[255];
    int count[26] = {0};
    int i, c, maxChar = 0, maxCount = 0;
    if (argc == 1)
    {
        printf("No filename supplied\n");
        return 0;
    }
    else if (argc > 2)
    {
        printf("Too many arguments supplied\n");
        return 0;
    }
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Could not open file\n");
        return 0;
    }
    while ((c = fgetc(fp)) != EOF)
    {
        if (c <= 'z' && c >= 'a')
            count[c - 'a']++;
        else if (c <= 'Z' && c >= 'A')
            count[c - 'A']++;
    }
    for (i = 0; i < 26; i++)
    {
        if (count[i] > maxCount)
        {
            maxChar = i;
            maxCount = count[i];
        }
    }
    printf("The most frequent letter is '%c'. It appeared %d times.\n", maxChar + 'a', maxCount);
    fclose(fp);
    return 0;
}
