#include "graph.h"
#include <iostream>
#include <unordered_map>

int main() {

    graph::Graph<int, int, int> gr1(11, 22, 33);
    gr1.begin()->second;

//    gr1.begin()->print();
//        gr1.m_map.begin();
//    node1.print();
//    node2.print();

//    graph::swap(node1, node2);
//    gr1.print();



//    graph::Graph<int, int, int> gr;
//    gr.print();

//    std::unordered_map<int, int> some_map;
//    some_map.emplace(1, 11);
//    some_map.emplace(4, 44);
//    some_map.emplace(3, 33);
//
//    for (auto const& pair: some_map)
//        std::cout << "{" << pair.first << ": " << pair.second << "}" << std::endl;
//    std::cout << "{" << some_map.begin()->first << ": " << some_map.begin()->second << "}" << std::endl;
//    std::cout << "{" << some_map.begin().operator++()->first << ": " << some_map.begin().operator++()->second << "}"
//              << std::endl;
    return 0;
}
