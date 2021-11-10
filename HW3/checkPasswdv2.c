/**
 * Dileep Reddy
 * Homework 3
 * 10/27/2021
 * Program to determine the validity of a given password based on its length
 */

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
 * @returns Deduction for the password based on the absence of uppercase, 
 * lowercase, numeric and presence of consecutive letters, -20 each
 */
int check(char *password)
{
    int i, length = strlen(password);

    //c to store current value, prev1 and prev2 to store previous values and the others
    char c, prev1 = '\0', prev2 = '\0';
    //flag binary value
    char hasLower = 0, hasUpper = 0, hasNumber = 0, twoConsec = 0;
    for (i = 0; i < length; i++)
    {
        c = password[i];
        //OR is used so that if a flag is triggered once, it is permanently set
        //using ASCII values for checking
        hasLower = hasLower || (c >= 'a' && c <= 'z');
        hasUpper = hasUpper || (c >= 'A' && c <= 'Z');
        hasNumber = hasNumber || (c >= '0' && c <= '9');
        twoConsec = twoConsec || (prev2 + 1 == prev1 && prev1 + 1 == c);
        prev2 = prev1;
        prev1 = c;
    }

    //returning the sum of deductions based on the state of the flags
    return (hasLower ? 0 : 20) + (hasUpper ? 0 : 20) + (hasNumber ? 0 : 20) + (twoConsec ? 20 : 0);
}
