#include "Contact.hpp"
#include <iomanip>
#include <sstream>

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
	std::stringstream ss;
	ss << "Contact with information:\n" << std::left
		<< std::setw(12) << "First Name:" << c.first_name << std::endl
		<< std::setw(12) << "Last Name:" << c.last_name << std::endl
		<< std::setw(12) << "Nickname:" << c.nickname << std::endl
		<< std::setw(12) << "Number:" << c.number << std::endl
		<< std::setw(12) << "Secret:" << c.dark_secret << std::endl;
	os << ss.str();
	return (os);
}
