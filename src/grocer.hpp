// Copyright © 2024 Spencer Rak <spencer.rak@snhu.edu>
// SPDX-License-Header: MIT
// 
// Spencer Rak
// Assignment 7-3
// 20240124

#ifndef GROCER_HPP_
#define GROCER_HPP_

#include <fstream>
#include <map>
#include <string>

namespace grocer {
    class App {
        void ClearScreen();
    public:
        void Run();
    };

    class DataFile {
        std::ifstream m_iStream;
        std::ofstream m_oStream;
        std::map<std::string, int> m_itemMap;
        static void itoc(char*, int&);
        static void ctoi(char*, int&);
        void Write();
        void Read();
        bool FindItem(std::string&);
    public:
        int GetItem(std::string&);
        void AddItem(std::string&);
        DataFile();
    };

    class Menu {
        void DisplayHeader();
    public:
        int GetInput(int&);
        void Quit();
        void ShowQuantities(bool);
        void Run();
    };
}

#endif
