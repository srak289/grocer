// Copyright © 2024 Spencer Rak <spencer.rak@snhu.edu>
// SPDX-License-Header: MIT
// 
// Spencer Rak
// Assignment 7-3
// 20240124

#include <algorithm>
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
 * Display the header
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
 * Read an integer into the passed reference
 * Trap the user in an input validation loop
 *
 * @param   t_prompt    The prompt to show the user
 * @param   t_result    The reference to assign
 */
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

/**
 * Read a string into the passed reference
 *
 * @param   t_prompt    The prompt to show the user
 * @param   t_result    The reference to assign
 */
void App::ReadString(const char* t_prompt, std::string& t_result) {
    std::cout << t_prompt;
    // We must call cin.ignore before a getline call
    std::cin.ignore();
    std::getline(std::cin, t_result);
}

/**
 * Convert a string to lowercase for database consistency
 */
void App::LowerString(std::string& t_string) {
    std::transform(
        t_string.begin(),
        t_string.end(),
        t_string.begin(),
        [](unsigned char c){ return std::tolower(c); }
    );
}

/**
 * Read the data from stdin into the DataFile map
 *
 * @param   t_file  the file to read
 *
 * @throws  std::runtime_error
 */
void App::FileInput(const char* t_file) {
    std::ifstream iStream(t_file);
    if (!iStream.good()) {
        throw std::runtime_error("File could not be read.");
    }
    std::string buf;
    while (getline(iStream, buf)) {
        // lower the string for consistency
        App::LowerString(buf);
        //std::cout << "Adding \"" << buf << "\" to datafile\n";
        this->m_dataFile.AddItem(buf);
    }
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
                // lower the string
                App::LowerString(t_strInput);
                // always add our item to the list because we are purchasing
                // this will either increment the existing key or create a new key
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
            if (t_intInput != 1) {
                // only ignore if the last call to cin was not `getline`
                std::cin.ignore();
            }
            std::cout << "Press ENTER to continue...";
            std::cin.get();
        }
    }
}
