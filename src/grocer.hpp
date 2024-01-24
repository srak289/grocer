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
        fstream::istream m_iStream;
        fstream::ostream m_oStream;
        std::map<std::string, int> m_itemMap;
        void Write();
        void Read();
        bool FindItem(std::string& t_itemName);
    public:
        int GetItem(std::string& t_itemName);
        void AddItem(std::string& t_itemName);
    };

    class Menu {
    public:
        void GetInput();
        void Quit();
        void ShowQuantities(bool);
    };
}

#endif
