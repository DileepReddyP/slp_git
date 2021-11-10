/**
 * Dileep Reddy
 * Homework 3
 * 10/27/2021
 * Program to get country name given a code, from a list of codes and names in a struct array
 */
#include <stdio.h>

//macro to calculate the length of the struct array codes[]
#define SIZE sizeof(codes) / sizeof(CountryCodes)

//struct to store the name (as a pointer array `name`) and country code (as an int `code`) of a country
typedef struct CountryCodes
{
    char *name;
    int code;
} CountryCodes;

//array of type `struct CountryCodes` to store 22 country codes of different countries in random order
const CountryCodes codes[] = {
    {"United States", 1},
    {"India", 91},
    {"Russia", 7},
    {"Japan", 81},
    {"Turkey", 90}, //5
    {"China", 86},
    {"Mexico", 52},
    {"South Africa", 27},
    {"United Kingdom", 44},
    {"Pakistan", 92}, //10
    {"Egypt", 20},
    {"Greece", 30},
    {"South Korea", 82},
    {"Sri Lanka", 94},
    {"Brazil", 55}, //15
    {"Uruguay", 598},
    {"China", 86},
    {"Malaysia", 60},
    {"New Zealand", 64},
    {"Netherlands", 31}, //20
    {"Nepal", 977},
    {"Sweden", 46}, //22
    {"Norway", 40},
    {"Czech Republic", 420},
    {"Estonia", 372},
};

char *findCode(int);

int main(int argc, char const *argv[])
{
    int ccode;
    char *cname;
    printf("Enter country code to find: +");
    scanf("%d", &ccode);
    cname = findCode(ccode);

    //checks if the response is NULL
    if (cname)
    {
        printf("+%d is the code for %s\n", ccode, cname);
    }
    else
    {
        printf("Could not find name for country with code +%d\n", ccode);
    }
    return 0;
}


/**
 * Program to search for given code and return name of the country
 * @param code interger code to search for
 * @returns reference to name string of the country if found, else NULL
 */ 
char *findCode(int code)
{
    int i, l = SIZE;
    for (i = 0; i < l; i++)
    {
        if (codes[i].code == code)
        {
            return codes[i].name;
        }
    }
    return NULL;
}