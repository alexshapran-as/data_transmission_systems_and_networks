//
// Created by Алексей Шапран on 13.03.2021.
//

#ifndef DATA_TRANSMISSION_SYSTEMS_AND_NETWORKS_UTILS_H
#define DATA_TRANSMISSION_SYSTEMS_AND_NETWORKS_UTILS_H


#include "Queue.h"

void dispatcher1(int mode, int number_of_init_blocks, int number_of_write_blocks, int z1, int z2, int m);
void dispatcher2(int mode, int number_of_init_blocks, int number_of_write_blocks);
void dispatcher3(int mode, int number_of_init_blocks, int number_of_write_blocks, int z1, int z2, int m, int mcicl);

Queue *alg1(int number_of_init_blocks);
void alg2(int number_of_write_blocks, int m, Queue *queue);
std::pair<Queue *, Queue *> alg3(int number_of_init_blocks, int number_of_write_blocks, Queue *queue);
void alg4(Package *package, int z1, int z2);
void alg5(Queue *queue_32, Queue *queue_repeat, std::bitset<bits_size> *register_out);
void alg6(Package *package_rr_ptr);
void alg7(Package *package_rr_ptr, Queue *queue_free);
void alg8(Queue *queue_free, Queue *queue_kpm);
bool alg9(Package *package_rr_ptr);
void alg10(Queue *queue_kpm, Queue *queue_repeat, Queue *queue_free);
void alg11();
Queue *alg12(int number_of_init_blocks);
void alg13(int number_of_write_blocks, int m, Queue *queue);
std::pair<Queue *, Queue *> alg14(int number_of_init_blocks, int number_of_write_blocks, Queue *queue);
void alg15(Queue *queue_32, int z1, int z2, int mcicl);
void alg16(Queue *queue_32, Queue *queue_repeat, int mcicl, std::bitset<bits_size> *register_out, std::vector<std::bitset<bits_size> *> &registers_out);

void move_head(Queue *source_queue, Queue *target_queue);
void clean_up();

#endif //DATA_TRANSMISSION_SYSTEMS_AND_NETWORKS_UTILS_H
