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
        std::copy(package_address->address, package_address->address + address_size, this->back->next_address);
        package_address->prev_package = this->back;
        std::copy(this->back->address, this->back->address + address_size, package_address->prev_address);
        this->back = package_address;
    } else {
        this->front = package_address;
        this->back = this->front;
    }
    this->count += 1;
}

void Queue::pop() {
    if (!this->empty()) {
        if (this->count == 1) {
            this->front = nullptr;
            this->back = nullptr;
        } else {
            Package *front_package = this->front;
            delete [] front_package->next_package->prev_address;
            front_package->next_package->prev_address = new std::bitset<bits_size>[address_size]{0};
            front_package->next_package->prev_package = nullptr;
            this->front = front_package->next_package;
        }
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
        std::cout << "Начальный адрес массива: ";
        for (unsigned int i = 0; i < address_size; ++i) {
           std::cout << p->address[i];
        }
        std::cout << std::endl;
        std::cout << "Первое адресное поле : ";
        for (unsigned int i = 0; i < address_size; ++i) {
           std::cout << p->prev_address[i];
        }
        std::cout << std::endl;
        std::cout << "Второе адресное поле : ";
        for (unsigned int i = 0; i < address_size; ++i) {
           std::cout << p->next_address[i];
        }
        std::cout << std::endl;
//        std::cout << "package_address: " << p << std::endl;
//        std::cout << "package_next_address: " << p->next_package << std::endl;
//        std::cout << "package_prev_address: " << p->prev_package << std::endl;
        std::cout << "Заголовок кадра : " << p->frame_header << std::endl;
        std::cout << "Заголовок пакета : ";
        for (unsigned int i = 0; i < package_header_size; ++i) {
            std::cout << p->package_header[i];
        }
        std::cout << std::endl;
        std::cout << "Информационная часть пакета : ";
        for (unsigned int i = 0; i < package_info_size; ++i) {
            std::cout << p->package_info[i];
        }
        std::cout << std::endl;
        std::cout << "КПК: ";
        for (unsigned int i = 0; i < kpk_size; ++i) {
            std::cout << p->kpk[i];
        }
        std::cout << std::endl;
        std::cout << "______________________" << std::endl;
        p = p->next_package;
    }
}
