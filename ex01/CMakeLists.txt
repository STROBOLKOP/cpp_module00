cmake_minimum_required(VERSION 3.15)

project(PhoneBook VERSION 1.0)

################################################################################
# compiler options and such
################################################################################

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_EXTENSIONS false)
add_compile_options(-Wall -Wextra -Werror)
add_link_options(-Wall -Wextra -Werror)

#set(CMAKE_ENABLE_EXPORTS True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

################################################################################
# Setting up the file structure
################################################################################

add_subdirectory(classes)
list(APPEND EXTRA_LIBS classes)

add_subdirectory(utils/string_utils)
list(APPEND EXTRA_LIBS string_utils)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PUBLIC main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC ${EXTRA_LIBS})
target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/include")

################################################################################
# Custom rule to be generated
################################################################################

add_custom_target(
	re
	COMMAND ${CMAKE_COMMAND} --build . --target clean
	COMMAND ${CMAKE_COMMAND} --build . --target all
)

################################################################################
# Add some testing using CTest
################################################################################

#[[
enable_testing()
add_test(NAME Runs COMMAND ${PROJECT_NAME})

function(do_test target name result)
	set(args ${ARGN})
	add_test(NAME ${name} COMMAND ${target} ${args})
	set_tests_properties(${name} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endfunction()
]]
