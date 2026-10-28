#ifndef MY_FUNC_H
#define MY_FUNC_H

#include "contact.h"

int validateName(char name[]);
int validatePhone(char phone[]);
int validateEmail(char email[]);
void printAllContacts(AddressBook *addressBook);
void printContact(Contact *contact);
void printHeader();


#endif