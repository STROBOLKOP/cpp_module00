#include "PhoneBook.hpp"
#include "string_utils.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

PhoneBook::PhoneBook()
{
	for (int i = 0; i < 8; i++)
		list[i] = Contact();
	index = 0;
}

PhoneBook::PhoneBook(const PhoneBook& other)
{
	index = other.index;
	for (int i = 0; i < 8; i++)
		list[i] = other.list[i];
}

PhoneBook::~PhoneBook()
{
}

PhoneBook&	PhoneBook::operator=(const PhoneBook& other)
{
	index = other.index;
	for (int i = 0; i < 8; i++)
		list[i] = other.list[i];
	return (*this);
}

Contact*	PhoneBook::get_list(void)
{
	return (&list[0]);
}

Contact	PhoneBook::get_contact(int index) const
{
	if (index < 0 || 8 <= index)
		throw std::invalid_argument("Index out of range for PhoneBook.");
	return (list[index]);
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
		Contact c = phonebook.get_contact(i);
		std::string print_first_name = c.get_first_name().substr(0, col_width);
		if (c.get_first_name().length() > col_width)
			print_first_name[col_width - 1] = '.';

		std::string print_last_name = c.get_last_name().substr(0, col_width);
		if (c.get_last_name().length() > col_width)
			print_last_name[col_width - 1] = '.';

		std::string print_nickname = c.get_nickname().substr(0, col_width);
		if (c.get_nickname().length() > col_width)
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

static int	get_input_field(const std::string prompt, std::string& in_buf, bool reduce_input = true)
{
	std::string input;
	in_buf = "";
	while (std::cout << prompt)
	{
		getline(std::cin, input);
		if (reduce_input)
			input = reduce(input);
		else
			input = trim(input);
		if (std::cin.eof())
			return (1);
		if (input.empty())
		{
			std::cout << "Error: A saved contact can't have empty fields.\n";
			continue ;
		}
		break ;
	}
	in_buf = input;
	return (0);
}

int	PhoneBook::add_contact(void)
{
	Contact c = Contact();
	std::string input;

	if (get_input_field("First Name: ", input)) return (1);
	c.set_first_name(input);
	if (get_input_field("Last Name: ", input)) return (1);
	c.set_last_name(input);
	if (get_input_field("Nickname: ", input)) return (1);
	c.set_nickname(input);
	if (get_input_field("Number: ", input)) return (1);
	c.set_number(input);
	if (get_input_field("Dark Secret: ", input)) return (1);
	c.set_dark_secret(input);
	return (add_contact(c));
}

int	PhoneBook::add_contact(const Contact& contact)
{
	list[index] = contact;
	index = (index + 1) % 8;
	std::cout << "Contact succesfully added." << std::endl;
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
