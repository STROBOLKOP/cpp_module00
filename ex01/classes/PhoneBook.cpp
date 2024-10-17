#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

PhoneBook::PhoneBook()
{
	for (int i = 0; i < 8; i++)
	{
		list[i] = Contact();
	}
	index = 0;
}

PhoneBook::PhoneBook(const PhoneBook& other)
{
	index = other.index;
	for (int i = 0; i < 8; i++)
	{
		list[i] = other.list[i];
	}
}

PhoneBook::~PhoneBook()
{
}

PhoneBook&	PhoneBook::operator=(const PhoneBook& other)
{
	index = other.index;
	for (int i = 0; i < 8; i++)
	{
		list[i] = other.list[i];
	}
	return (*this);
}

std::ostream& operator << (std::ostream& os, const PhoneBook& phonebook)
{
	std::size_t col_width = 10;

	os
		<< "+-------------------------------------------+" << std::endl;
	os
		<< "|"
		<< std::setw(col_width) << "index" << "|"
		<< std::setw(col_width) << "first name" << "|"
		<< std::setw(col_width) << "last name" << "|"
		<< std::setw(col_width) << "nickname" << "|"
		<< std::endl;
	os
		<< "+-------------------------------------------+" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::string print_first_name = phonebook.list[i].first_name.substr(0, col_width);
		if (phonebook.list[i].first_name.length() > col_width)
			print_first_name[col_width - 1] = '.';

		std::string print_last_name = phonebook.list[i].last_name.substr(0, col_width);
		if (phonebook.list[i].last_name.length() > col_width)
			print_last_name[col_width - 1] = '.';

		std::string print_nickname = phonebook.list[i].nickname.substr(0, col_width);
		if (phonebook.list[i].nickname.length() > col_width)
			print_nickname[col_width - 1] = '.';

		os
			<< "|"
			<< std::setw(col_width) << i << "|"
			<< std::setw(col_width) << print_first_name << "|"
			<< std::setw(col_width) << print_last_name << "|"
			<< std::setw(col_width) << print_nickname << "|"
			<< std::endl;
		os
			<< "+-------------------------------------------+" << std::endl;
	}
	return (os);
}

// TODO: "A saved contact can't have empty fields"
// TODO: catch EOF during input here
int	PhoneBook::add_contact(void)
{
	Contact c = Contact();
	std::cout << "First Name: ";
	getline(std::cin, c.first_name);
	if (std::cin.eof()) return (1);
	std::cout << "Last Name: ";
	getline(std::cin, c.last_name);
	if (std::cin.eof()) return (1);
	std::cout << "Nickname: ";
	getline(std::cin, c.nickname);
	if (std::cin.eof()) return (1);
	std::cout << "Number: ";
	getline(std::cin, c.number);
	if (std::cin.eof()) return (1);
	std::cout << "Dark Secret: ";
	getline(std::cin, c.dark_secret);
	if (std::cin.eof()) return (1);
	std::cout << std::endl;
	return (add_contact(c));
}

int	PhoneBook::add_contact(const Contact& contact)
{
	list[index] = contact;
	index = (index + 1) % 8;
	return (0);
}

int	PhoneBook::search_contact(void)
{
	std::cout << *this;

	std::string input;
	while (!std::cin.eof() && std::cout << "Input index of contact to show: ")
	{
		getline(std::cin, input);
		if (std::cin.eof())
			break ;
		if (input.find_first_not_of("0123456789") != std::string::npos)
		{
			std::cout << "Error: Invalid index. Needs to be an integer in range [0,8[.\n";
			continue ;
		}

		std::stringstream ss;
		ss << input;
		int index;
		ss >> index;
		if (index < 0 || 8 <= index)
		{
			std::cout << "Error: Invalid index. Needs to be an integer in range [0,8[.\n";
			continue ;
		}
		else
		{
			std::cout << std::endl << list[index] << std::endl;
			return (0);
		}
	}
	return (0);
}
