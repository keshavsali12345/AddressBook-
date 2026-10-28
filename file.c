#include <stdio.h>
#include "file.h"
//.......................................store contact in file..............................
void saveContactsToFile(AddressBook *addressBook ) 
{
    FILE *fp;
    fp = fopen("contacts.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        fprintf(fp, "%s,%s,%s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
    }

    fclose(fp);

    printf("Contacts saved successfully\n");

  
}
//......................fetch contact from file.......

void loadContactsFromFile(AddressBook *addressBook)
{
    FILE *fp;

    fp = fopen("contacts.txt", "r");

    if (fp == NULL)
    {
        printf("No contact file found\n");
        return;
    }

    addressBook->contactCount = 0;

    while (fscanf(fp, " %49[^,],%19[^,],%49[^\n]",
                  addressBook->contacts[addressBook->contactCount].name,
                  addressBook->contacts[addressBook->contactCount].phone,
                  addressBook->contacts[addressBook->contactCount].email) == 3)
    {
        addressBook->contactCount++;

        if (addressBook->contactCount >= 100)
        {
            break;
        }
    }

    fclose(fp);

    printf("Contacts loaded successfully\n");
}
