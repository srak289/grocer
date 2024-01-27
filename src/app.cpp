// Copyright © 2024 Spencer Rak <spencer.rak@snhu.edu>
// SPDX-License-Header: MIT
// 
// Spencer Rak
// Assignment 7-3
// 20240124

#include <iostream>
#include <stdexcept>
#include "grocer.hpp"

using namespace grocer;


/**
 * Construct App
 *
 * Explicitly initialize m_dataFile in constructor initializer list
 * which is otherwise done invisibly
 *
 * e.g.
 * App::App() { // Constructor for DataFile called here
 *     this->m_dataFile() = DataFile(); // Constructor called again!
 * }
 */
App::App() : m_dataFile() {
}

/**
 * Clear the screen
 */
void App::ClearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

/**
 * Dispslay the header
 */
void App::DisplayHeader() {
    std::string stars(34, '*');
    std::cout << '/' << stars << '\\' << std::endl
        << "|          GROCER CONSOLE          |" << std::endl
        << '\\' << stars << '/' << std::endl
        << "    1. Option One\n"
        << "    2. Option Two\n"
        << "    3. Option Three\n"
        << "    4. Quit\n";
}

/**
 * Handle inputs of type T by looping until the user enters valid input
 *    
 * @param   prompt  The prompt to display
 * @param   result  The reference to read the value into
 */
template <class T, typename F>
void App::HandleInput(const char* t_prompt, T& t_result, F&& t_funcTest) {
    std::cin.exceptions(std::ios::failbit);
    while (true) {
        try {
            std::cout << t_prompt;
            std::cin >> t_result;
            if (t_funcTest(t_result)) {
                break;
            }
            throw std::invalid_argument("Invalid Argument");
        } catch (const std::ios::failure& e) {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "Your input could not be parsed.\n";
        } catch (const std::invalid_argument& e) {
            std::cin.ignore(256, '\n');
            std::cout << "Your input failed the conditional test.\n";
        }
    }
}

/**
 * Read the data from stdin into the DataFile map
 */
void App::FileInput() {
}

/**
 * The main entrypoint for App
 */
void App::Run() {
    this->ClearScreen();
    this->DisplayHeader();
    int x = 0;
    while (x != 4) {
        this->HandleInput<int&>("Enter an integer [1-4]: ", x, [](int& x){ return x > 0 && x < 5; });
        switch (x) {
            case 1:
                std::cout << "You pressed 1\n";
                break;
            case 2:
                std::cout << "You pressed 2\n";
                break;
            case 3:
                std::cout << "You pressed 3\n";
                break;
            case 4:
                std::cout << "Program exit.\n";
                break;
        }
    }
}
