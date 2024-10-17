#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>

class PhoneBook
{
	public:
		PhoneBook();
		PhoneBook(const PhoneBook& other);
		~PhoneBook();
		PhoneBook& operator = (const PhoneBook& other);
		int	add_contact();
		int	add_contact(const Contact& contact);
		int	search_contact();
	private:
		friend std::ostream& operator << (std::ostream& os, const PhoneBook& phonebook);
		Contact list[8];
		int index;
};

#endif
