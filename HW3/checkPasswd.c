/**
 * Dileep Reddy
 * Homework 3
 * 10/27/2021
 * Program to determine the validity of a given password based on its length
 * */

//stdlib.h for malloc and free, string.h for strlen
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(char *);

int main(int argc, char const *argv[])
{
    char *password;
    int length, missChar;
    password = malloc(256); //allocating memory to the pointer upto 256 bytes
    printf("Enter the password: ");
    scanf("%s", password);
    missChar = check(password);
    //showing message per the conditions specified
    if (missChar > 30)
    {
        printf("The password is unsafe! Please reset. Deduction: %d\n", missChar);
    }
    else
    {
        printf("The password is safe!\n");
    }
    free(password); //freeing allocated memory
    return 0;
}

/**
 * Function to check the validity of a given password string
 * @param password pointer to the password string
 * @returns Deduction for the password based on its length
 */
int check(char *password)
{
    //using tertiary operator as it is a binary one-time check
    return strlen(password) > 9 ? 0 : 5 * (10 - strlen(password));
}
