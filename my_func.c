#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "my_func.h"

int validateName(char name[])
{
    if (strlen(name) == 0) // name length should not zero
        return 0;

    for (int i = 0; name[i] != '\0'; i++)
    {
        if (!isalpha(name[i]) && name[i] != ' ')// not contain digits...
        {
             printf("====Enter a valid name ! Try Again===\n");
             return 0;
        }
    }
    return 1;
}

int validatePhone(char phone[])
{
    if (strlen(phone) != 10) // digit lenght should be 10, if not throw error
    {
        printf("Enter a valide phonenumber ! Try Again..\n");
        return 0;
    }

    for (int i = 0; phone[i] != '\0'; i++)
    {
        if (!isdigit(phone[i])) // cheack is alpha.
        {
            printf("Enter a valide phonenumber ! Try Again..\n");
            return 0;
        }
    }
    return 1;
}

int validateEmail(char email[])
{
    int at = 0, dot = 0;

    for (int i = 0; email[i] != '\0'; i++)
    {
        if (email[i] == '@')
            at++;

        if (email[i] == '.' && at == 1)
            dot = 1;
        
    }
    if (at == 0 || dot == 0 )
    {
        printf("Error: Email must contain @\n");
        return 0;
    }

    return (at == 1 && dot);
}

void printAllContacts(AddressBook *addressBook)
{
    printf("\n---------------------------------------------------------------\n");
    printf("%-15s %-15s %-30s\n", "Name", "Phone", "Email");
    printf("-----------------------------------------------------------------\n");

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        printf("%-15s %-15s %-30s\n",
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email);
    }
    printf("------------------------------------------------------------------\n");
}
//.............................................................................
void printHeader()
{
    printf("\n----------------------------------------------------------------\n");
    printf("%-20s %-15s %-30s\n", "Name", "Phone", "Email");
    printf("------------------------------------------------------------------\n");
}
//..........................function to print single contact....................
void printContact(Contact *Contact)
{
    printf("%-20s %-15s %-30s\n",
               Contact->name,
               Contact->phone,
               Contact->email);
    
}