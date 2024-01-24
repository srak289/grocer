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
 * Clear the screen
 */
App::ClearScreen() {
    std::cout << u8"\033[2J\033[1;1H";
}

/**
 * The main entrypoint for App
 */
App::Run() {
    this->ClearScreen();
    std::cout << "App running\n";
}
