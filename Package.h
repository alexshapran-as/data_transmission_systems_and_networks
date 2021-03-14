//
// Created by Алексей Шапран on 13.03.2021.
//

#ifndef DATA_TRANSMISSION_SYSTEMS_AND_NETWORKS_PACKAGE_H
#define DATA_TRANSMISSION_SYSTEMS_AND_NETWORKS_PACKAGE_H

#include <iostream>

const int bits_size = 8;
const int address_size = 2;
const int package_header_size = 3;
const int package_info_size = 128;
const int kpk_size = 2;

class Package {
    static int get_address(const int delta = 0) {
        static int address = 0;
        return address += delta;
    }

public:
    Package(Package *prevPackage,
            Package *nextPackage,
            std::bitset<bits_size> address[address_size],
            std::bitset<bits_size> prev_address[address_size],
            std::bitset<bits_size> next_address[address_size],
            std::bitset<bits_size> package_header[package_header_size],
            std::bitset<bits_size> frame_header,
            std::bitset<bits_size> package_info[package_info_size],
            std::bitset<bits_size> kpk[kpk_size]);
    Package();
    ~Package();

    Package *prev_package;
    Package *next_package;
    std::bitset<bits_size> *address;
    std::bitset<bits_size> *prev_address;
    std::bitset<bits_size> *next_address;
    std::bitset<bits_size> *package_header;
    std::bitset<bits_size> frame_header;
    std::bitset<bits_size> *package_info;
    std::bitset<bits_size> *kpk;
};


#endif //DATA_TRANSMISSION_SYSTEMS_AND_NETWORKS_PACKAGE_H
