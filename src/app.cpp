// Copyright © 2024 Spencer Rak <spencer.rak@snhu.edu>
// SPDX-License-Header: MIT
// 
// Spencer Rak
// Assignment 7-3
// 20240124

#include <iostream>
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
 * The main entrypoint for App
 */
void App::Run() {
    //this->ClearScreen();
    std::cout << "App running\n";
}
