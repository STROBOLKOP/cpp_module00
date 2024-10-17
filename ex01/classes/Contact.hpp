#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

class Contact
{
	public:
		Contact();
		Contact(const Contact& other);
		~Contact();
		Contact& operator = (const Contact& other);
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string number;
		std::string dark_secret;
	private:
		friend std::ostream& operator << (std::ostream& os, const Contact& c);
};

#endif
