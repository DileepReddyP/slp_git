#include <stdio.h>
/**
 * Dileep Reddy
 * Lab 7
 * 10/12/2021
 * Program to accept and print out phone number in specific format 
 */
int main(int argc, char const *argv[])
{
    int countryCode, areaCode, subscriberCode;
    printf("Enter phone number [(999)999-9999]: ");
    scanf("(%3d)%3d-%4d", &countryCode, &areaCode, &subscriberCode);
    printf("You entered %3d-%3d-%4d\n", countryCode, areaCode, subscriberCode);
    return 0;
}
