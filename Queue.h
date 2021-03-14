//
// Created by Алексей Шапран on 13.03.2021.
//

#ifndef DATA_TRANSMISSION_SYSTEMS_AND_NETWORKS_QUEUE_H
#define DATA_TRANSMISSION_SYSTEMS_AND_NETWORKS_QUEUE_H


#include "Package.h"

class Queue {
public:
    Package *front;
    Package *back;
    unsigned int count;

    Queue(Package *front, Package *back, unsigned int count);
    Queue();
    ~Queue();

    void push(Package *package_address);
    void pop();
    bool empty();
    void print();
};


#endif //DATA_TRANSMISSION_SYSTEMS_AND_NETWORKS_QUEUE_H
