#include <stdio.h>
#include "contact.h"

int main() {
    int choice;
    AddressBook addressBook; 
    initialize(&addressBook); // Initialize the address book
    // Load contacts from file before displaying menu
    loadContactsFromFile(&addressBook);
    int oldcontact = addressBook.contactCount;

    do {
        printf("\033[31m\n+-------------------------------------+\033[0m\n");
        printf("\033[32m|         ADDRESS BOOK MENU           |\033[0m\n");
        printf("\033[93m|             BY Keshav               |\033[0m\n");
        printf("\033[33m+-------------------------------------+\033[0m\n");
        printf("\033[34m| 1. Create Contact                   |\033[0m\n");
        printf("\033[35m| 2. Search Contact                   |\033[0m\n");
        printf("\033[36m| 3. Edit Contact                     |\033[0m\n");
        printf("\033[91m| 4. Delete Contact                   |\033[0m\n");
        printf("\033[92m| 5. List All Contacts                |\033[0m\n");
        printf("\033[93m| 6. Show All Contacts                |\033[0m\n");
        printf("\033[94m| 7. Exit                             |\033[0m\n");
        printf("\033[95m+-------------------------------------+\033[0m\n");
        printf("Enter your choice---->\n");
        scanf("%d", &choice); 
        
        switch (choice) {
            case 1:
                createContact(&addressBook);
                printf("Total Contact = %d\n",addressBook.contactCount);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:
                printf("Select sort criteria:\n");
                printf("1. Sort by name\n");
                printf("2. Sort by phone\n");
                printf("3. Sort by email\n");
                printf("Enter your choice: ");
                int sortChoice;
                scanf("%d", &sortChoice);
                listContacts(&addressBook, sortChoice);
                break;
            case 6:
                //loadContactsFromFile(&addressBook);
                printAllContacts(&addressBook);
                break;
            case 7:
                printf("Saving and Exiting...\n");
                //saveContactsToFile(&addressBook);
                saveAndExit(&addressBook);
                break;
                
            default:
                printf("\n========Invalid choice! Please try again.========\n");
        }
    } while (choice != 7);
    
       return 0;
}
