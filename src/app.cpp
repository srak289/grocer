// Copyright © 2024 Spencer Rak <spencer.rak@snhu.edu>
// SPDX-License-Header: MIT
// 
// Spencer Rak
// Assignment 7-3
// 20240124

#include <iomanip>
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

void App::ReadInteger(const char* t_prompt, int& t_result) {
    std::cin.exceptions(std::ios::failbit);
    while (true) {
        try {
            std::cout << t_prompt;
            std::cin >> t_result;
            break;
        } catch (const std::ios::failure& e) {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "Your input could not be parsed.\n";
        }
    }
}

void App::ReadString(const char* t_prompt, std::string& t_result) {
    std::cout << t_prompt;
    std::cin.ignore();
    std::getline(std::cin, t_result);
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

    int t_intInput = 0;
    unsigned int t_amt = 0;
    std::string t_strInput = "";
    std::pair<
        std::map<std::string, unsigned int>::iterator,
        std::map<std::string, unsigned int>::iterator
    > t_itemReport;

    while (t_intInput != 4) {

        this->ClearScreen();
        this->DisplayHeader();

        this->ReadInteger("Enter an integer [1-4]: ", t_intInput);

        switch (t_intInput) {
            case 1:
                this->ReadString("Enter an item to search for: ", t_strInput);
                this->m_dataFile.AddItem(t_strInput);
                t_amt = this->m_dataFile.GetItem(t_strInput);

                // here we use inline ternary statements to make the language correct
                // for plural results
                std::cout << "There " << ((t_amt > 1) ? "have " : "has ") << "been "
                    << t_amt << ((t_amt > 1) ? " purachases " : " purchase ") << "of \""
                    << t_strInput << "\"\n";

                break;

            case 2:
                t_itemReport = this->m_dataFile.GetReport();
                // loop while our begin iterator is not equal to the end iterator
                for (; t_itemReport.first != t_itemReport.second; ++t_itemReport.first) {
                    // output the pointed to values of the map iterator
                    // right align the set width, we assume items have
                    // a name < 24c in length
                    std::cout << std::setw(24) << std:: right << t_itemReport.first->first
                        << ": " << t_itemReport.first->second << std::endl;
                }
                std::cout << std::endl;
                break;

            case 3:
                t_itemReport = this->m_dataFile.GetReport();
                // loop while our begin iterator is not equal to the end iterator
                for (; t_itemReport.first != t_itemReport.second; ++t_itemReport.first) {
                    // construct a string of stars for the histogram
                    std::string stars(t_itemReport.first->second, '*');

                    // output the pointed to values of the map iterator
                    // right align the set width, we assume items have
                    // a name < 24c in length
                    std::cout << std::setw(24) << std::right << t_itemReport.first->first
                        << " " << stars << std::endl;
                }
                std::cout << std::endl;
                break;

            case 4:
                std::cout << "Program exit.\n";
                break;

            default:
                std::cout << t_intInput << " is not [1-4]\n";
        }
        if (t_intInput != 4) {
            //std::cin.ignore(256, '\n');
            std::cout << "Press ENTER to continue...";
            std::cin.ignore(); // FIXME double enter after item search
            std::getline(std::cin, t_strInput);
        }
    }
}
