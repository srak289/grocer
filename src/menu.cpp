// Copyright © 2024 Spencer Rak <spencer.rak@snhu.edu>
// SPDX-License-Header: MIT
// 
// Spencer Rak
// Assignment 7-3
// 20240124

#include <iostream>
#include "grocer.hpp"

using namespace grocer;


void Menu::DisplayHeader() {
    std::cout << "Header\n";
}

int Menu::GetInput(int& t_intRef) {
    std::cin.exceptions(std::ios::failbit);
    while (true) {
        try {
            std::cin >> t_intRef;
        } catch (std::ios::failure& e) {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "Failed to parse input.\nPlease enter an integer 1-4.\n\n";
            continue;
        }
        if (t_intRef < 0 || t_intRef > 4) {
        }
    }

}

void Menu::Run() {
    this->DisplayHeader();
    int x = 0;
    while (x != 4) {
        this->GetInput(x);
        switch (x) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                std::cout << "Program exit.\n";
                break;
        }
    }
}
