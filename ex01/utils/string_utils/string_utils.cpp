#include "string_utils.hpp"

std::string	trim(const std::string& str, const std::string& whitespace)
{
	const std::size_t str_begin = str.find_first_not_of(whitespace);
	if (str_begin == std::string::npos)
		return "";
	const std::size_t str_end = str.find_last_not_of(whitespace);
	const std::size_t str_range = str_end - str_begin + 1;

	return (str.substr(str_begin, str_range));
}

std::string reduce(
		const std::string& str,
		const std::string& fill,
		const std::string& whitespace)
{
	std::string result = trim(str, whitespace);

	std::size_t begin_space = result.find_first_of(whitespace);
	while (begin_space != std::string::npos)
	{
		const std::size_t end_space = result.find_first_not_of(whitespace, begin_space);
		const std::size_t range = end_space - begin_space;
		result.replace(begin_space, range, fill);
		const std::size_t new_start = begin_space + fill.length();
		begin_space = result.find_first_of(whitespace, new_start);
	}
	return (result);
}
