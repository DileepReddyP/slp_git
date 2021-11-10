/**
 * Dileep Reddy
 * Lab 10 In-Lab
 * 10/28/2021
 * Program to convert time in seconds to hr/min/sec
 */
#include <stdio.h>
// Write the declaration of function split_time
void split_time(long, int *, int *, int *);
int main()
{
    int hr, min, sec;
    long int n;
    printf("Enter seconds: ");
    scanf("%ld", &n);
    /* Write the statement to call split_time */
    split_time(n, &hr, &min, &sec);
    printf("Converted format: %d hour%c %d min%c %d sec%c\n", hr, hr==1?'\0':'s', min, min==1?'\0':'s', sec, sec==1?'\0':'s');
    return 0;
}
void split_time(long total_sec, int *hr, int *min, int *sec)
{
    /* Write the statements to calculate hr, min and sec*/
    *hr = (int)total_sec/3600;
    total_sec %= 3600;
    *min = (int)total_sec/60;
    total_sec %= 60;
    *sec = (int)total_sec;
}