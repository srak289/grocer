// Copyright © 2024 Spencer Rak <spencer.rak@snhu.edu>
// SPDX-License-Header: MIT
// 
// Spencer Rak
// Assignment 7-3
// 20240124

#include <iostream>
#include "grocer.hpp"


Menu::DisplayHeader() {
    std::cout << "Header\n";
}

int Menu::GetInput(const char* t_prompt, int& t_intRef) {
    cin.exceptions(ios::failbit);
    while (true) {
        std::cout << t_prompt;
        try {
            std::cin >> t_intRef;
        } catch (ios::failure& e) {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            std::cout << "Failed to parse input.\nPlease enter an integer 1-4.\n\n";
            continue;
        }
        if (t_intRef < 0 || t_intRef > 4) {
        }
    }

}

Menu::Run() {
    this->DisplayHeader();
    int x = 0;
    while (x != 4) {
        this->GetInput(&x);
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
