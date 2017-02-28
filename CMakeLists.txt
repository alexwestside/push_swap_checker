cmake_minimum_required(VERSION 3.6)

project(push_swap_checker)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.c push_swap_checker.h usage.c move_stack.c checker.c gnl/get_next_line.c)

add_executable(push_swap_checker ${SOURCE_FILES})

target_link_libraries(push_swap_checker ${CMAKE_SOURCE_DIR}/ft_printf/libftprintf.a)