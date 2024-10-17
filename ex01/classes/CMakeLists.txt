add_library(classes
	Contact.cpp PhoneBook.cpp
)
target_include_directories(classes
	PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}"
)
