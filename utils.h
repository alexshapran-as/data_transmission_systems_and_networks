//
// Created by Алексей Шапран on 13.03.2021.
//

#ifndef DATA_TRANSMISSION_SYSTEMS_AND_NETWORKS_UTILS_H
#define DATA_TRANSMISSION_SYSTEMS_AND_NETWORKS_UTILS_H


#include "Queue.h"

std::bitset<3> ns;
std::bitset<3> nr;

void dispatcher(int mode, int number_of_init_blocks, int number_of_write_blocks, int z1, int z2, int m);
Queue *alg1(int number_of_init_blocks);
void alg2(int number_of_write_blocks, int m, Queue *queue);
std::pair<Queue *, Queue *> alg3(int number_of_init_blocks, int number_of_write_blocks, Queue *queue);
void alg4(Package *package, int z1, int z2);
void alg5(Queue *queue_32, Queue *queue_repeat, std::bitset<bits_size> *register_out);
void move_head(Queue *source_queue, Queue *target_queue);

#endif //DATA_TRANSMISSION_SYSTEMS_AND_NETWORKS_UTILS_H
