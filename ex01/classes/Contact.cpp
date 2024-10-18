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

std::string Contact::get_first_name() const { return (first_name); }
std::string Contact::get_last_name() const { return (last_name); }
std::string Contact::get_nickname() const { return (nickname); }
std::string Contact::get_number() const { return (number); }
std::string Contact::get_dark_secret() const { return (dark_secret); }

void Contact::set_first_name(std::string str){ first_name = str; }
void Contact::set_last_name(std::string str){ last_name = str; }
void Contact::set_nickname(std::string str){ nickname = str; }
void Contact::set_number(std::string str){ number = str; }
void Contact::set_dark_secret(std::string str){ dark_secret = str; }


std::ostream& operator << (std::ostream& os, const Contact& c)
{
	std::stringstream ss;
	ss << "Contact with information:\n" << std::left
		<< std::setw(12) << "First Name:" << c.get_first_name() << std::endl
		<< std::setw(12) << "Last Name:" << c.get_last_name() << std::endl
		<< std::setw(12) << "Nickname:" << c.get_nickname() << std::endl
		<< std::setw(12) << "Number:" << c.get_number() << std::endl
		<< std::setw(12) << "Secret:" << c.get_dark_secret() << std::endl;
	os << ss.str();
	return (os);
}
