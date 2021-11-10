/**
 * Dileep Reddy
 * Lab 10 Post-Lab
 * 10/28/2021
 * Program to find highest and lowest string in alphabetical order
 */
#include <string.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char current_word[20], smallest_word[20], largest_word[20];
    int len = 0;
    while (len != 4)
    {
        printf("Enter word: ");
        scanf("%s", current_word);
        len = strlen(current_word);
        if (strlen(smallest_word) == 0)
        {
            strcpy(smallest_word, current_word);
        }
        if (strlen(largest_word) == 0)
        {
            strcpy(largest_word, current_word);
        }
        if (strcmp(current_word, smallest_word) < 0)
        {
            strcpy(smallest_word, current_word);
        }
        else if (strcmp(current_word, largest_word) > 0)
        {
            strcpy(largest_word, current_word);
        }
    }
    printf("Smallest word: %s\nLargest word: %s\n", smallest_word, largest_word);
    return 0;
}
