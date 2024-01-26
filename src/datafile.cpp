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


/**
 * Construct DataFile
 *
 * Default constructor for m_itemMap is called implicitly
 * with types defined in the header
 */
DataFile::DataFile() {
    this->Read();
    std::string s = "squash";
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    s = "butternut squash";
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    this->AddItem(s);
    s = "sweet corn";
    this->AddItem(s);
    this->AddItem(s);
    s = "cilantro";
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
    s = "green bell pepper";
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
    s = "engligsh cucumber";
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

void DataFile::itoc(char* buf, unsigned int& i) {
    buf[0] = (i & 0xff000000) >> 24;
    buf[1] = (i & 0x00ff0000) >> 16;
    buf[2] = (i & 0x0000ff00) >> 8;
    buf[3] = (i & 0x000000ff);
}

void DataFile::ctoi(char* buf, unsigned int& i) {
    i = reinterpret_cast<unsigned char&>(buf[0]) << 24
        | reinterpret_cast<unsigned char&>(buf[1]) << 16
        | reinterpret_cast<unsigned char&>(buf[2]) << 8
        | reinterpret_cast<unsigned char&>(buf[3]);
}

void DataFile::Read() {
    this->m_iStream = std::ifstream("frequency.dat", std::ios::binary);

    char buf[256] = {0};
    unsigned int fsz = 0;

    // read the first 4-byte int from the file to tell us
    // how many item there are
    this->m_iStream.read(buf, 4);
    DataFile::ctoi(buf, fsz);

    std::cout << "Reading " << fsz << " from file\n";

    for (int i=0; i<fsz; i++) {
        // zero the important part of the buffer each
        // loop or our single byte read will be incorrect
        // from DataFile::ctoi
        buf[0] = 0;
        buf[1] = 0;
        buf[2] = 0;
        buf[3] = 0;

        // read the first byte to get our string length
        this->m_iStream.read(buf, 1);
        // Copy MSB to LSB for ctoi to give us the right int back
        // zero the MSB
        buf[3] = buf[0];
        buf[0] = 0;

        // get the string length to read including \0
        unsigned int len = 0;
        DataFile::ctoi(buf, len);

        std::cout << "Reading " << len << " from file.\n";
        this->m_iStream.read(buf, len);

        // make a new string from buf up to \0
        std::string s(buf);

        // read the int for how many items there are
        this->m_iStream.read(buf, 4);
        DataFile::ctoi(buf, len);

        std::cout << "Adding " << s << " with quantity " << len << " to map\n";
        // add the reconstructed key to the map
        this->m_itemMap[s] = len;
    }

    this->m_iStream.close();
}

void DataFile::Write() {
    this->m_oStream = std::ofstream("frequency.dat", std::ios::binary | std::ios::trunc);

    char buf[256] = {0};
    unsigned int fsz = this->m_itemMap.size();
    DataFile::itoc(buf, fsz);

    this->m_oStream.write(buf, 4);

    for (auto it = this->m_itemMap.begin(); it != this->m_itemMap.end(); ++it) {
        std::cout << "Writing key " << it->first << " with value " << it->second << "\n";

        // compute the length of our c_str and make a static cast
        // so pass-by-ref works with DataFile::itoc
        unsigned int len = static_cast<unsigned int>(it->first.size()+1);

        std::cout << "Writing int " << len << " to file\n";
        DataFile::itoc(buf, len);
        buf[0] = buf[3];
        // write the length of the following string
        this->m_oStream.write(buf, 1);

        // write the string
        this->m_oStream.write(it->first.c_str(), it->first.size()+1);

        // reuse len 
        len = static_cast<unsigned int>(it->second);
        // convert the amount to chars and write them
        DataFile::itoc(buf, len);
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

unsigned int DataFile::GetItem(std::string& t_itemName) {
    if (this->FindItem(t_itemName)) {
        return this->m_itemMap[t_itemName];
    }
    return -1;
}
