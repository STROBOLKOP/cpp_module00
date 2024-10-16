cmake_minimum_required(VERSION 3.15)

project(Megaphone VERSION 1.0)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_EXTENSIONS false)
add_compile_options(-Wall -Wextra -Werror)
add_link_options(-Wall -Wextra -Werror)

#set(CMAKE_ENABLE_EXPORTS True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

add_executable(megaphone megaphone.cpp)

add_custom_target(
	re
	COMMAND ${CMAKE_COMMAND} --build . --target clean
	COMMAND ${CMAKE_COMMAND} --build . --target all
)

enable_testing()
add_test(NAME Runs COMMAND megaphone)
add_test(NAME NoArgs COMMAND megaphone)
set_tests_properties(NoArgs
	PROPERTIES PASS_REGULAR_EXPRESSION "\\* LOUD AND UNBEARABLE FEEDBACK NOISE \\*"
)

function(do_test target name result)
	set(args ${ARGN})
	add_test(NAME ${name} COMMAND ${target} ${args})
	set_tests_properties(${name} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endfunction()

do_test(megaphone input1
	"SHHHHH... I THINK THE STUDENTS ARE ASLEEP..."
	"shhhhh... I think the students are asleep..."
)

do_test(megaphone input2
	"DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF."
	"Damnit" " ! " "Sorry students, I thought this thing was off."
)
