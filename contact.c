#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include <ctype.h>
#include "my_func.h"//created my self...

void listContacts(AddressBook *addressBook, int sortChoice) 
{   
    
    
    char name[50];
    int i;
    int count = 0;
    switch(sortChoice)
    {
        //...................................................short by name.....................
    case 1: 
           printf("=====Enter name to search=====\n");
           scanf(" %49[^\n]", name);
           printHeader();
           for (i = 0; i < addressBook->contactCount; i++)
          {
            if (strcmp(addressBook->contacts[i].name,name) == 0)
          {
           printContact(&addressBook->contacts[i]);
           count++;
          }
          }
           if (count == 0)
           {
             printf("\nContact not found\n");
           }
           else
           {
             printf("\nTotal contacts with name '%s' = %d\n",name, count);
           }
           break;
           //....................................phone number...................
        case 2: 
           printf("=====Enter Phone to search=====\n");
           scanf(" %49[^\n]", name);
           printHeader();
           for (i = 0; i < addressBook->contactCount; i++)
          {
            if (strcmp(addressBook->contacts[i].phone,name) == 0)
          {
           printContact(&addressBook->contacts[i]);
           count++;
          }
          
          }
           if (count == 0)
           {
             printf("\nContact not found\n");
           }
           else
           {
             printf("\nTotal contacts with phone '%s' = %d\n",name, count);
           }
           break;
          //.....................................email id.......................
        case 3:
           printf("=====Enter email to search=====\n");
           scanf(" %49[^\n]", name);
           printHeader();
           for (i = 0; i < addressBook->contactCount; i++)
          {
            if (strcmp(addressBook->contacts[i].email, name) == 0)
          {
           printContact(&addressBook->contacts[i]);
           count++;
          }
          }
           if (count == 0)
           {
             printf("\nContact not found\n");
           }
           else
           {
             printf("\nTotal contacts with email '%s' = %d\n",name, count);
           }
           break;

 }         
}


void initialize(AddressBook *addressBook) 
{
    addressBook->contactCount = 0;
    //loadContactsFromFile(addressBook);
   // populateAddressBook(addressBook);
   // Load contacts from file during initialization (After files)
  //loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook)
{
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}

// .............................................create contact..........................
void createContact(AddressBook *addressBook)
{
	
    //................ name..............................................................
    char name[30];
    do
    {  
      printf("\n+--------------------------------------+\n");
      printf("|            CREATE CONTACT            |\n");
      printf("+--------------------------------------+\n");
      printf("Enter Name--->");
    scanf(" %29[^\n]", name);
    }  while(! validateName(name));
    //after validation save name in address book 
    strcpy(addressBook->contacts[addressBook->contactCount].name,name);
     
    //................ phone...............................................................
    char phone[30];
    do
    {
        printf("Enter Phone number--->");
        scanf(" %30[^\n]",phone);
    }  while (!validatePhone(phone)); 
    strcpy(addressBook->contacts[addressBook->contactCount].phone,phone);
    //................ Email ..............................................................
    char email[30];
    do
    {
        printf("Enter email id--->");
        scanf(" %30[^\n]",email);
        
    }while(!validateEmail(email));
    strcpy(addressBook->contacts[addressBook->contactCount].email,email);
    //increase the number of contacts
     addressBook->contactCount++;

     printf("\033[32m    Contact Created Successfully!    \033[0m\n");
    

}
//--------------------------------------------------------------function for serching contact...................................................
void searchContact(AddressBook *addressBook)
{
    int choice;
    char search[50];
    int found = 0; // flag for message..
   
   printf("\n+--------------------------------------+\n");
   printf("|         SEARCH CONTACT BY            |\n");
   printf("+--------------------------------------+\n");
   printf("| 1. Name                              |\n");
   printf("| 2. Phone Number                      |\n");
   printf("| 3. Email ID                          |\n");
   printf("+--------------------------------------+\n");
   printf("Enter your choice: ");
   scanf("%d", &choice);

    printf("=========Enter Name or Email or phone for serch:=========\n"); // store name or phone number or email id... for serch
    scanf(" %49[^\n]", search);

    
    printHeader();
    for (int i = 0; i < addressBook->contactCount; i++) // for loop for serching student details.
    {
        switch (choice)
        {
            case 1:
                 
                if (strcmp(addressBook->contacts[i].name, search) == 0) //compaire name with all record ones found break loop
                {   

                    
                     printf("%-20s %-15s %-30s\n",
                     addressBook->contacts[i].name,
                     addressBook->contacts[i].phone,
                     addressBook->contacts[i].email);
                    // printf("Name  : %s\n", addressBook->contacts[i].name);
                    // printf("Phone : %s\n", addressBook->contacts[i].phone);
                    // printf("Email : %s\n", addressBook->contacts[i].email);
                    found = 1;
                }
                break;

            case 2:
                if (strcmp(addressBook->contacts[i].phone, search) == 0)
                {   
                    printf("%-20s %-15s %-30s\n",
                    addressBook->contacts[i].name,
                    addressBook->contacts[i].phone,
                    addressBook->contacts[i].email);
                    // printf("Name  : %s\n", addressBook->contacts[i].name);
                    // printf("Phone : %s\n", addressBook->contacts[i].phone);
                    // printf("Email : %s\n", addressBook->contacts[i].email);
                     found = 1;
                }
                break;

            case 3:
                if (strcmp(addressBook->contacts[i].email, search) == 0)
                {   
                    printf("%-20s %-15s %-30s\n",
                    addressBook->contacts[i].name,
                    addressBook->contacts[i].phone,
                    addressBook->contacts[i].email);
                    
                    found = 1;
                }
                break;

            default:
                printf("Invalid Choice\n");
                return;
        }
    }

    if (!found)
    {
        printf("\033[31mContact not found\033[0m\n");
    }

    printf("-------------------------------------------------------------------\n");
   
}
//...............................function for edit contact................................
void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    char search[50];
    int choice;
    int found = 1;

    printf("===Enter name of contact to edit:===\n");
    scanf(" %49[^\n]", search);

    // Search contact
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(addressBook->contacts[i].name, search) == 0)
        {
            found = i;
            break;
        }
    }

     if (found == 1)
    {
        printf("\033[31mContact not found\033[0m\n");
        return;
    }

    printf("\n===============Contact found===============\n");
    printf("%-20s %-15s %-30s\n", "Name", "Phone", "Email");
    printf("-------------------------------------------------------------\n");
    
    printf("%-20s %-15s %-30s\n",
               addressBook->contacts[found].name,
               addressBook->contacts[found].phone,
               addressBook->contacts[found].email);
   

   printf("\n==============What do you want to edit?===============\n");
   printf("1. Name\n");
   printf("2. Phone\n");
   printf("3. Email\n");
   printf("=========================================================\n");
   scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("--------Enter new name:--------\n ");
            scanf(" %49[^\n]", addressBook->contacts[found].name);
            printf("=====Name updated successfully=====\n");
            break;

        case 2:
            printf("--------Enter new phone--------\n ");
            scanf(" %49[^\n]", addressBook->contacts[found].phone);
            printf("=====phone updated successfully=====\n");
            break;

        case 3:
            printf("--------Enter new email--------\n ");
            scanf(" %49[^\n]", addressBook->contacts[found].email);
            printf("=====email updated successfully=====\n");
            break;

            default:
            printf("\033[31mInvalid choice\033[0m\n");
    }

}
//..............................................function for delete contact...................
void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    
    char name[50];
    int found = 1;

    printf("===Enter name of contact to delete:===\n ");
    scanf(" %49[^\n]", name);

    // Search contact
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(addressBook->contacts[i].name, name) == 0)
        {
            found = i;
            break;
        }
    }
     // Contact not found
    if (found == 1)
    {
        printf("\033[31mContact not found\033[0m\n");
        return;
    }

    // Shift contacts to the left
    for (int i = found; i < addressBook->contactCount - 1; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }

    // Decrease contact count
    addressBook->contactCount--;

    printf("========Contact deleted successfully========\n");
   
}

