//
// Created by Алексей Шапран on 13.03.2021.
//

#include "utils.h"

std::bitset<3> ns(0);
std::bitset<3> nr(0);

static Queue *queue = nullptr;
static Queue *queue_32 = nullptr;
static Queue *queue_free = nullptr;
static Queue *queue_repeat = new Queue();
static int register_out_size = address_size * 3 + package_header_size + 1 + package_info_size + kpk_size;
std::bitset<bits_size> *register_out = new std::bitset<bits_size>[register_out_size]{0};

void dispatcher1(int mode, int number_of_init_blocks, int number_of_write_blocks, int z1, int z2, int m) {
    switch (mode) {
        case 1: {
            queue = alg1(number_of_init_blocks);
            break;
        }
        case 2: {
            alg2(number_of_write_blocks, m, queue);
            break;
        }
        case 3: {
            std::pair<Queue *, Queue *> queue_pair = alg3(number_of_init_blocks, number_of_write_blocks, queue);
            queue_32 = queue_pair.first;
            queue_free = queue_pair.second;
            break;
        }
        case 4: {
            alg4(queue->front, z1, z2);
            break;
        }
        case 5: {
            alg5(queue_32, queue_repeat, register_out);
            for (unsigned int i = 0; i < register_out_size; ++i) {
                std::cout << register_out[i] << std::endl;
            }
            break;
        }
        default: {
            return;
        }
    }
    mode += 1;
    dispatcher1(mode, number_of_init_blocks, number_of_write_blocks, z1, z2, m);
}

void dispatcher2(int mode, int number_of_init_blocks, int number_of_write_blocks) {
    switch (mode) {
        case 1: {
            Package *package = new Package();
            package->package_header = queue_repeat->back->package_header;
            package->frame_header = queue_repeat->back->frame_header;
            package->package_info = queue_repeat->back->package_info;
            package->kpk = queue_repeat->back->kpk;
            Package package_rr = *package;
            alg6(package_rr);
            break;
        }
        case 2: {
            alg7();
            break;
        }
        case 3: {
            alg8();
            break;
        }
        case 4: {
            alg9();
            break;
        }
        case 5: {
            alg10();
            break;
        }
        case 6: {
            alg11();
            break;
        }
        default: {
            break;
        }
    }
}

Queue *alg1(int number_of_init_blocks) {
    Queue *queue = new Queue();
    for (unsigned int i = 0; i < number_of_init_blocks; ++i) {
        queue->push(new Package());
    }
    return queue;
}

void alg2(int number_of_write_blocks, int m, Queue *queue) {
    Package *package_iter = queue->front;
    if (number_of_write_blocks > queue->count) {
        std::cerr << "Ошибка: запись за пределы очереди" << std::endl;
        return;
    }
    for (unsigned int i = 0; i < number_of_write_blocks; ++i) {
        unsigned char msg = m + 1;
        for (unsigned int j = 0; j < package_info_size; ++j) {
            package_iter->package_info[j] = std::bitset<bits_size>(msg);
        }
        package_iter = package_iter->next_package;
    }
}

std::pair<Queue *, Queue *> alg3(int number_of_init_blocks, int number_of_write_blocks, Queue *queue) {
    Queue *queue_32 = new Queue();
    Queue *queue_free = new Queue();
    queue_32->front = queue->front;
    queue_32->count = number_of_write_blocks;
    queue_free->back = queue->back;
    queue_free->count = number_of_init_blocks - number_of_write_blocks;
    Package *packages_iter_32 = queue->front;
    for (unsigned int i = 0; i < number_of_write_blocks - 1; ++i) {
        packages_iter_32 = packages_iter_32->next_package;
    }
    Package *packages_iter_free = packages_iter_32->next_package;
    queue_32->back = packages_iter_32;
    packages_iter_32->next_package = nullptr;
    packages_iter_32->next_address = new std::bitset<bits_size>[address_size]{0};
    queue_free->front = packages_iter_free;
    packages_iter_free->prev_package = nullptr;
    packages_iter_free->prev_address = new std::bitset<bits_size>[address_size]{0};
    return std::pair<Queue *, Queue *>(queue_32, queue_free);
}

void alg4(Package *package, int z1, int z2) {
    std::bitset<bits_size> z1_bits(z1);
    std::bitset<bits_size> z2_bits(z2);
    for (unsigned int i = 0; i < 3; ++i) {
        package->frame_header[package->frame_header.size() - i - 2] = z1_bits[i];
        ns[i] = z1_bits[i];
        package->frame_header[package->frame_header.size() - i - 6] = z2_bits[i];
        nr[i] = z2_bits[i];
    }
    package->kpk[kpk_size - 1] = package->frame_header ^ package->package_info[0];
    package->kpk[kpk_size - 1][4] = 0;
}

void alg5(Queue *queue_32, Queue *queue_repeat, std::bitset<bits_size> *register_out) {
    for (unsigned int i = 0; i < address_size; ++i) {
        register_out[i] = queue_32->front->address[i];
    }
    for (unsigned int i = 0; i < address_size; ++i) {
        register_out[address_size + i] = queue_32->front->prev_address[i];
    }
    for (unsigned int i = 0; i < address_size; ++i) {
        register_out[address_size * 2 + i] = queue_32->front->next_address[i];
    }
    register_out[address_size * 3] =  queue_32->front->frame_header;
    for (unsigned int i = 0; i < package_header_size; ++i) {
        register_out[address_size * 3 + 1 + i] = queue_32->front->package_header[i];
    }
    for (unsigned int i = 0; i < package_info_size; ++i) {
        register_out[address_size * 3 + 1 + package_header_size + i] = queue_32->front->package_info[i];
    }
    for (unsigned int i = 0; i < kpk_size; ++i) {
        register_out[address_size * 3 + 1 + package_header_size + package_info_size + i] = queue_32->front->kpk[i];
    }
    move_head(queue_32, queue_repeat);
}


void alg6(Package &package_rr) {
    std::bitset<bits_size> rr(1);
    std::bitset<3> new_nr(ns.to_ulong() + 1);
    for (unsigned int i = 0; i < 3; ++i) {
        rr[rr.size() + i - 3] = new_nr[i];
    }
    package_rr.kpk[1] = rr;
}

void alg7() {

}

void alg8() {

}

void alg9() {

}

void alg10() {

}

void alg11() {

}

void move_head(Queue *source_queue, Queue *target_queue) {
    Package *front_elem = source_queue->front;
    source_queue->pop();
    front_elem->next_address = new std::bitset<bits_size>[address_size]{0};
    front_elem->next_package = nullptr;
    target_queue->push(front_elem);
}

void save_to_file(std::bitset<bits_size> header) {

}
