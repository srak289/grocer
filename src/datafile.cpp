// Copyright © 2024 Spencer Rak <spencer.rak@snhu.edu>
// SPDX-License-Header: MIT
// 
// Spencer Rak
// Assignment 7-3
// 20240124

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include "grocer.hpp"

using namespace grocer;


DataFile::DataFile() {
    this->m_itemMap = std::map<std::string, int>();
    std::string s = "potato";
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    s = "zuccini";
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    s = "corn";
    this->AddItem(s);
    this->AddItem(s);
    s = "pumpkin";
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    s = "carrot";
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    s = "celery";
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    s = "yam";
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    s = "tomato";
    this->AddItem(s);
    this->AddItem(s);
    this->Write();
}

void DataFile::itoc(char* buf, int& i) {
    buf[0] = i & 0xf000;
    buf[1] = i & 0x0f00;
    buf[2] = i & 0x00f0;
    buf[3] = i & 0x000f;
}

void DataFile::ctoi(char* buf, int& i) {
    i = buf[0] | buf[1] | buf[2] | buf[3];
}

void DataFile::Read() {
    this->m_iStream = std::ifstream("frequency.dat", std::ios::binary);

    char buf[256] = {0};
    int fsz = 0;

    this->m_iStream.read(buf, 4);
    DataFile::ctoi(buf, fsz);

    for (int i=0; i<fsz; i++) {

    }

    this->m_iStream.close();
}

void DataFile::Write() {
    this->m_oStream = std::ofstream("frequency.dat", std::ios::binary | std::ios::trunc);

    char buf[256] = {0};

    int fsz = this->m_itemMap.size();
    DataFile::itoc(buf, fsz);

    this->m_oStream.write(buf, 4);

    for (auto it = this->m_itemMap.begin(); it != this->m_itemMap.end(); ++it) {
        std::cout << "Writing key " << it->first << " with value " << it->second << "\n";

        int w = static_cast<int>(it->first.size()+1);

        std::cout << "WRiting int " << w << " to file\n";
        DataFile::itoc(buf, w);
        this->m_oStream.write(buf, 1);

        this->m_oStream.write(it->first.c_str(), it->first.size()+1);

        DataFile::itoc(buf, it->second);
        this->m_oStream.write(buf, 4);
    }

    this->m_oStream.close();
}

/**
 * Return whether or not an item exists in m_itemMap
 */
bool DataFile::FindItem(std::string& t_itemName) {
    auto it = this->m_itemMap.find(t_itemName);
    if (it != this->m_itemMap.end()) {
        return true;
    }
    return false;
}

void DataFile::AddItem(std::string& t_itemName) {
    if (this->FindItem(t_itemName)) {
        this->m_itemMap[t_itemName]++;
        return;
    }
    this->m_itemMap[t_itemName] = 1;
}

int DataFile::GetItem(std::string& t_itemName) {
    if (this->FindItem(t_itemName)) {
        return this->m_itemMap[t_itemName];
    }
    return -1;
}
