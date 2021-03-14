#include <iostream>
#include <bitset>
#include "utils.h"

int main() {
    std::cout << "*****Системы и сети передачи данных*****" << std::endl;

    int number_of_init_blocks, number_of_write_blocks, m, z1, z2;

    std::cout << "Введите N1: ";
    std::cin >> number_of_init_blocks;

    std::cout << "Введите N2: ";
    std::cin >> number_of_write_blocks;

    std::cout << "Введите Z1: ";
    std::cin >> z1;

    std::cout << "Введите Z2: ";
    std::cin >> z2;

    std::cout << "Введите m: ";
    std::cin >> m;

    int mode = 1;
    dispatcher(mode, number_of_init_blocks, number_of_write_blocks, z1, z2, m);
    return 0;
}

