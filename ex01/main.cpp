#include "PhoneBook.hpp"
#include <iostream>

void	msg_help(void)
{
	std::cout
		<< "Interaction with the program is with a couple of commands:\n"
		<< "EXIT:\tStop the program. Be carefull, you lose the contacts currently stored!\n"
		<< "HELP:\tShow this list of commands.\n"
		<< "ADD:\tAdd a contact into the PhoneBook overwriting the oldest one if you try to add a nineth contact. You add fields one by one with a prompt for each.\n"
		<< "SEARCH:\tShows the added contacts and allows to display all fields stored in a contact\n"
		;
}

void	msg_welcome(void)
{
	std::cout
		<< "Welcome to your Awesome PhoneBook\n"
		<< "We can store 8 Contacts for you!\n"
		<< std::endl;
		;
	msg_help();
}

void	msg_bad_input(const std::string in)
{
	std::cout
		<< "Error: '" << in << "' is not a known command\n"
		;
}

int	parse_input(PhoneBook& book, const std::string& input)
{
	if (std::cin.eof())
		return (1);
	else if (input == "EXIT")
		return (1);
	else if (input == "HELP")
		msg_help();
	else if (input == "ADD")
		return (book.add_contact());
	else if (input == "SEARCH")
		return (book.search_contact());
	else if (input == "")
		;
	else
		msg_bad_input(input);
	return (0);
}

int	program_loop(void)
{
	PhoneBook book;
	std::string input;
	
	msg_welcome();
	while (!std::cin.eof() && std::cout << "PhoneBook: ")
	{
		getline(std::cin, input);
		if (parse_input(book, input))
			break ;
	}
	std::cout << (std::cin.eof() ? "\n" : "") << "Goodbye!\n";
	return (0);
}

int	main(void)
{
	program_loop();
	return (0);
}
