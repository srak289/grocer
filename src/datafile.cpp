// Copyright © 2024 Spencer Rak <spencer.rak@snhu.edu>
// SPDX-License-Header: MIT
// 
// Spencer Rak
// Assignment 7-3
// 20240124

#include <fstream>
#include <map>
#include <string>
#include "grocer.hpp"

using namespace grocer;


DataFile::DataFile() {
    this->m_iStream("frequency.dat");
    this->m_oStream("frequency.dat");
    this->m_itemMap = std::map<std::string, int>();
}

void DataFile::Read() {

}

void DataFile::Write() {

}

/**
 * Return whether or not an item exists in m_itemMap
 */
bool DataFile::FindItem(std::string& t_itemName) {
    auto it = this->n_itemMap.find(t_itemName);
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

std::string DataFile::GetItem(std::string& t_itemName) {
    if (this->FindItem(t_itemName)) {
        return this->m_itemMap[t_itemName];
    }
    return NULL;
}
