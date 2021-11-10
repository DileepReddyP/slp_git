/**
 * Dileep Reddy
 * Homework 3
 * 10/27/2021
 * Program to swap numeric characters from one string with alphabetical characters from the other
 */

#include <stdio.h>

void swap(char *, char *);
void intCharSwap(int, char *, char *);

int main(int argc, char const *argv[])
{
    int length, i = 0;
    printf("Enter the length of the string: ");
    scanf("%d", &length);
    //user input string
    char a[length], b[length];
    printf("Enter the first string: ");
    scanf("%s", a);
    printf("Enter the second string: ");
    scanf("%s", b);
    //terminating string at the specified length
    a[length] = '\0';
    b[length] = '\0';
    intCharSwap(length, a, b);
    printf("First string is now %s\nSecond string is now %s\n", a, b);
    return 0;
}

/**
 * Program to swap two characters based on their pointers without any temporary variable
 * @param a pointer to first character to swap
 * @param b pointer to second character to swap
 */
void swap(char *a, char *b)
{
    //this uses the principle that a + b - b = b,
    //to interchange the values of the characters at the addresses
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

/**
 * Program to swap alphabetical characters from second string with numeric characters of the first
 * If a string "runs out" of characters to swap in, the last value is repeated. Both should contain alphanumeric characters
 * @param length of the two strings
 * @param a pointer to first string
 * @param b pointer to second string
 */
void intCharSwap(int length, char *a, char *b)
{
    //used to mark current location in the string
    int i = 0, j = 0;
    //to save the character to repeat at the end
    char saved_num, saved_char;

    while (i < length || j < length)
    {
        //iterates to find chacraters to swap
        if (!(a[i] >= '0' && a[i] <= '9') && i < length)
        {
            i++;
        }
        else if (!((b[j] >= 'a' && b[j] <= 'z') || (b[j] >= 'A' && b[j] <= 'Z')) && j < length)
        {
            j++;
        }
        //if characters to swap are found
        else if ((a[i] >= '0' && a[i] <= '9') && ((b[j] >= 'a' && b[j] <= 'z') || (b[j] >= 'A' && b[j] <= 'Z')))
        {
            saved_num = a[i];
            saved_char = b[j];
            swap(&a[i], &b[j]);
            i++;
            j++;
        }
        //if a string has run out of characters to swap
        else
        {
            //skipping first condition as i and j's current values are necessary 
            for (; j < length; j++)
            {
                b[j] = saved_num;
            }
            for (; i < length; i++)
            {
                a[i] = saved_char;
            }
            return;
        }
    }
}