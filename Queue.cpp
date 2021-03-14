//
// Created by Алексей Шапран on 13.03.2021.
//

#include "Queue.h"

Queue::Queue(Package *front, Package *back, unsigned int count) : front(front), back(back), count(count) {}

Queue::Queue() : front(nullptr), back(nullptr), count(0) {}

Queue::~Queue() {
    this->front = nullptr;
    this->back = nullptr;
}

void Queue::push(Package *package_address) {
    if (!this->empty()) {
        this->back->next_package = package_address;
        this->back->next_address = package_address->address;
        package_address->prev_package = this->back;
        package_address->prev_address = this->back->address;
        this->back = package_address;
    } else {
        this->front = package_address;
        this->back = this->front;
    }
    this->count += 1;
}

void Queue::pop() {
    if (!this->empty()) {
        Package *front_package = this->front;
        front_package->next_package->prev_address = new std::bitset<bits_size>[address_size]{0};
        front_package->next_package->prev_package = nullptr;
        this->front = front_package->next_package;
        this->count -= 1;
    }
}

bool Queue::empty() {
    if (this->front) {
        return false;
    } else {
        return true;
    }
}

void Queue::print() {
    Package *p = this->front;
    for (unsigned int i = 0; i < this->count; ++i) {
        std::cout << "address: ";
        for (unsigned int i = 0; i < address_size; ++i) {
           std::cout << p->address[i];
        }
        std::cout << std::endl;
        std::cout << "package_address: " << p << std::endl;
        std::cout << "package_next_address: " << p->next_package << std::endl;
        std::cout << "package_prev_address: " << p->prev_package << std::endl;
        std::cout << "package_info: ";
        for (unsigned int i = 0; i < package_info_size; ++i) {
            std::cout << p->package_info[i];
        }
        std::cout << std::endl;
        std::cout << "frame_header: " << p->frame_header << std::endl;
        std::cout << "kpk: ";
        for (unsigned int i = 0; i < kpk_size; ++i) {
            std::cout << p->kpk[i];
        }
        std::cout << std::endl;
        std::cout << "______________________" << std::endl;
        p = p->next_package;
    }
}
