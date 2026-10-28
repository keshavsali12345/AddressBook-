#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;

typedef struct {
    Contact contacts[MAX_CONTACTS];
    int contactCount;
} AddressBook;  

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook, int sortCriteria);
void initialize(AddressBook *addressBook);
void saveContactsToFile(AddressBook *AddressBook);
//new added for me ;.................
int validateName(char *);
int validatePhone(char *);
int validateEmail(char email[]);
void printAllContacts(AddressBook *addressBook);
void loadContactsFromFile( AddressBook *addressBook);
void saveAndExit(AddressBook *addressBook);


//...................................

#endif
