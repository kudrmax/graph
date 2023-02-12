#include "graph.h"
#include <iostream>
#include <unordered_map>

int main() {
    graph::Graph<int, int, int>::Node node(6);
    node.print();
    node.clear();

    //std::unordered_map<int, int> some_map;
    //std::cout << some_map.empty() << std::endl;

    return 0;
}
