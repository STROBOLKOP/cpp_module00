#include <iostream>

void	my_toupper(std::string &str)
{
	for (unsigned long i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	for (int i = 1; i < ac; i++)
	{
		std::string str(av[i]);
		my_toupper(str);
		std::cout << str;
	}
	std::cout << std::endl;

	return (0);
}
