//
// Created by Алексей Шапран on 13.03.2021.
//

#include "Package.h"

Package::Package(Package *prevPackage,
                 Package *nextPackage,
                 std::bitset<bits_size> address[address_size],
                 std::bitset<bits_size> prev_address[address_size],
                 std::bitset<bits_size> next_address[address_size],
                 std::bitset<bits_size> package_header[package_header_size],
                 std::bitset<bits_size> frame_header,
                 std::bitset<bits_size> package_info[package_info_size],
                 std::bitset<bits_size> kpk[kpk_size]) : prev_package(prevPackage), next_package(nextPackage) {
    address = new std::bitset<bits_size>[2]{std::bitset<bits_size>(0), std::bitset<bits_size>(get_address(1))};
}

Package::Package() :
                    prev_package(nullptr),
                    next_package(nullptr),
                    address(new std::bitset<bits_size>[address_size]{0}),
                    prev_address(new std::bitset<bits_size>[address_size]{0}),
                    next_address(new std::bitset<bits_size>[address_size]{0}),
                    package_header(new std::bitset<bits_size>[package_header_size]),
                    frame_header(std::bitset<bits_size>(0)),
                    package_info(new std::bitset<bits_size>[package_info_size]),
                    kpk(new std::bitset<bits_size>[kpk_size]) {
    address = new std::bitset<bits_size>[2]{std::bitset<bits_size>(0), std::bitset<bits_size>(get_address(1))};
}

Package::~Package() {
    delete [] this->next_package;
    delete [] this->prev_package;
    delete [] this->address;
    delete [] this->next_address;
    delete [] this->prev_address;
    delete [] this->package_header;
    delete [] this->package_info;
    delete [] this->kpk;
}
