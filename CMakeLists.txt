cmake_minimum_required(VERSION 3.14)
project(CppApp VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable strict warnings
if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# Library target
add_library(app_lib
    src/Calculator.cpp
    src/Calculator.hpp
)
target_include_directories(app_lib PUBLIC src)

# Executable target
add_executable(app_exec
    src/main.cpp
)
target_link_libraries(app_exec PRIVATE app_lib)

# Test executable target
add_executable(app_test
    tests/test_calculator.cpp
)
target_link_libraries(app_test PRIVATE app_lib)

enable_testing()
add_test(NAME CalculatorTests COMMAND app_test)
