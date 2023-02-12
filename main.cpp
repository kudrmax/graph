#include "graph.h"
#include <iostream>

int main() {
    graph::Graph<int, int, int>::Node node1;
    graph::Graph<int, int, int>::Node node2(6);
    //int val = 5;
    //node1.value() = val;
    node2.print();
    node2.value() = 5;
    node1.value() = 10;
    std::cout << node2.value() << " " << node1.value();
    //std::cout << "Hello, World!" << node2.value() << std::endl;
    return 0;
}
