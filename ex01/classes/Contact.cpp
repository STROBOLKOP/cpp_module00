#include "Contact.hpp"

Contact::Contact()
{
	first_name = std::string();
	last_name = std::string();
	nickname = std::string();
	number = std::string();
	dark_secret = std::string();
}

Contact::Contact(const Contact& other)
{
	first_name = other.first_name;
	last_name = other.last_name;
	nickname = other.nickname;
	number = other.number;
	dark_secret = other.dark_secret;
}

Contact::~Contact()
{
}

Contact& Contact::operator=(const Contact& other)
{
	first_name = other.first_name;
	last_name = other.last_name;
	nickname = other.nickname;
	number = other.number;
	dark_secret = other.dark_secret;
	return (*this);
}

std::ostream& operator << (std::ostream& os, const Contact& c)
{
	os << "Contact with information:\n"
		<< "First Name:\t" << c.first_name << std::endl
		<< "Last Name:\t" << c.last_name << std::endl
		<< "Nickname:\t" << c.nickname << std::endl
		<< "Number:\t" << c.number << std::endl
		<< "Secret:\t" << c.dark_secret << std::endl;
	return (os);
}
