/**
 * Dileep Reddy
 * Homework 3
 * 10/27/2021
 * Program to determine if a string is a palindrome
 */

//stdlib.h for malloc and free
#include <stdio.h>
#include <stdlib.h>
char isPalindrome(char *, int);

int main(int argc, char const *argv[])
{
    char c, *string;
    int length = 0;
    string = malloc(256); //allocating memory to the pointer upto 256 bytes
    printf("Enter the string: ");

    //calling getchar in a loop uptil newline so that length of string can be determined without 
    //using string functions, by adding characters to each position of the array
    while ((c = getchar()) != '\n')
    {
        string[length] = c;
        length++;
    }
    string[length] = '\0';//terminating string properly
    printf("'%s' is%s a palindrome\n", string, isPalindrome(string, length) ? "" : " not"); //message modified based on value of functiom
    free(string); //freeing allocated memory
    return 0;
}

/**
 * Function to check if a string is a palindrome
 * @param a pointer to the string to check
 * @param length length of the string
 * @returns 1 if the string is a palindrome, else 0
 */ 
char isPalindrome(char *a, int length)
{
    //a pointer to the address of the last character of the string
    char *reverse = a + length - 1;
    //a flag set to 1 as an empty string is a palindrome
    char isPalin = 1;
    int i;
    //need to scan only until the halfway marl
    for (i = 0; i < length/2 + 1; i++)
    {
        //AND because the flag is false if a single character doesn't match
        //subtracting i from the reverse pointer points at the correct value to compare
        isPalin = isPalin && (a[i] == *(reverse - i));
    }
    return isPalin;
}
