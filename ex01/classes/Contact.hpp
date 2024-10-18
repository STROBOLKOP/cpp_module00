#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	public:
		Contact();
		Contact(const Contact& other);
		~Contact();
		Contact& operator = (const Contact& other);
		std::string get_first_name() const;
		std::string get_last_name() const;
		std::string get_nickname() const;
		std::string get_number() const;
		std::string get_dark_secret() const;
		void set_first_name(std::string str);
		void set_last_name(std::string str);
		void set_nickname(std::string str);
		void set_number(std::string str);
		void set_dark_secret(std::string str);
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string number;
		std::string dark_secret;
};

std::ostream& operator << (std::ostream& os, const Contact& c);

#endif
