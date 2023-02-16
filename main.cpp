#include "graph.h"
#include <iostream>
#include <unordered_map>

int main() {

//    graph::Graph<int, std::string, int> gr(1, "one", 11);
//    graph::Graph<int, std::string, int>::Node node(5, "five", 55);
//    gr[5] = node;
//    gr.print();

    graph::Graph<int, std::string, int> gr;
    gr[1] = graph::Graph<int, std::string, int>::Node(1, "one", 11);
    gr[2] = graph::Graph<int, std::string, int>::Node(2, "two", 22);
    gr[3] = graph::Graph<int, std::string, int>::Node(3, "three", 33);
    gr.print();

//    gr[6] = graph::Graph<int, std::string, int>::Node(6, "six", 66);

//    std::unordered_map<int, std::string> map{{1, "one"}};
//    map[2] = "two";
//
//    for (auto const& pair: map)
//        std::cout << "{" << pair.first << ": " << pair.second << "}" << std::endl;


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
