// Copyright © 2024 Spencer Rak <spencer.rak@snhu.edu>
// SPDX-License-Header: MIT
// 
// Spencer Rak
// Assignment 7-3
// 20240124

#include <cstring>
#include <iostream>
#include "grocer.hpp"


void print_help(const char* t_prog) {
    std::cout << "Usage:\n"
        << "\t" << t_prog << "\t\t\t - Run the program's menu interface\n"
        << "\t" << t_prog << " -f <filename>\t - Load test data from a text file\n";
}

int main(int argc, char* argv[]) {
    grocer::App app;

    if (argc > 1) {

        // exit if we get the wrong number of arguments
        if (argc != 3) {
            print_help(argv[0]);
            return EXIT_FAILURE;
        }

        // exit if we get any argument other than `-f`
        if (strcmp(argv[1], "-f") != 0) {
            std::cout << "Unrecognized argument " << argv[1] << std::endl;
            print_help(argv[0]);
            return EXIT_FAILURE;
        }

        try {
            app.FileInput(argv[2]);
        } catch (std::runtime_error& e) {
            std::cout << e.what() << std::endl;
            print_help(argv[0]);
            return EXIT_FAILURE;
        }
    } else {
        app.Run();
    }

    return EXIT_SUCCESS;
}
