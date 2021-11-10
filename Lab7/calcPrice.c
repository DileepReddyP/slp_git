#include <stdio.h>
/**
 * Dileep Reddy
 * Lab 7
 * 10/12/2021
 * Program to accept and print out purchase data in specific format 
 */
int main(int argc, char const *argv[])
{
    int itemNo, quantity, purchDay, purchMonth, purchYear;
    float unitPrice, totalAmount;
    printf("Enter item number:");
    scanf("%d", &itemNo);
    printf("Enter unit price:");
    scanf("%f", &unitPrice);
    printf("Enter quantity:");
    scanf("%d", &quantity);
    printf("Enter purchase date (mm/dd/yyyy):");
    scanf("%2d/%2d/%4d", &purchMonth, &purchDay, &purchYear);
    totalAmount = unitPrice * quantity;
    printf("%-4s\t%-10s\t%-6s\t%-10s\t%-10s\n", "Item", "Unit Price", "QTY", "Purchase Date", "Total Amount");
    printf("%-4d\t$%9.2f\t%-6d\t%-2d/%-2d/%-4d\t$%11.2f\n", itemNo, unitPrice, quantity, purchMonth, purchDay, purchYear, totalAmount);
    return 0;
}
