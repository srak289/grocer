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
    class DataFile {
        std::ifstream m_iStream;
        std::ofstream m_oStream;
        std::map<std::string, unsigned int> m_itemMap;
        static void itoc(char*, unsigned int&);
        static void ctoi(char*, unsigned int&);
        void Write();
        void Read();
        bool FindItem(std::string&);
    public:
        unsigned int GetItem(std::string&);
        void AddItem(std::string&);
        DataFile();
        ~DataFile();
    };


    class App {
        void DisplayHeader();
        DataFile m_dataFile;
        void ClearScreen();
        template <class T, typename F>
        void HandleInput(const char*, T&, F&& = [](T&){ return true; });
    public:
        void ShowQuantities(bool);
        void FileInput();
        void Run();
        App();
    };
}

#endif
