#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook
{
	public:
		PhoneBook();
		PhoneBook(const PhoneBook& other);
		~PhoneBook();
		PhoneBook& operator = (const PhoneBook& other);
		Contact* get_list();
		Contact get_contact(int index) const;
		int	add_contact();
		int	add_contact(const Contact& contact);
		int	search_contact();
	private:
		Contact list[8];
		int index;
};

std::ostream& operator << (std::ostream& os, const PhoneBook& phonebook);

#endif
