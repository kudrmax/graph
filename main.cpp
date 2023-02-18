#include "graph.h"
#include <iostream>
#include <unordered_map>

int main() {

    graph::Graph<std::string, int, double> gr;
    gr.insert_node("one", 1);
    gr.insert_node("two", 2);
    gr.insert_node("three", 3);
    gr.insert_node("four", 4);

    gr.insert_edge(std::make_pair("one", "two"), 12);
    gr.insert_edge(std::make_pair("one", "three"), 13);
    gr.insert_edge(std::make_pair("four", "two"), 42);

    gr.print();
    std::cout << gr.degree_out("one") << std::endl;
    std::cout << gr.degree_out("two") << std::endl;
    std::cout << gr.degree_out("three") << std::endl;
    std::cout << gr.degree_out("four") << std::endl;


//    graph::Graph<std::string, int, double> gr;
//    gr.insert_node("one", 1);
//    gr.insert_node("two", 2);
//    gr.insert_node("three", 3);
//    gr.print();
//    auto a = gr.insert_edge(std::make_pair("one", "two"), 12);
//    gr.insert_edge(std::make_pair("one", "three"), 13);
//    gr.insert_edge(std::make_pair("one", "three"), 13);
//    gr.insert_edge(std::make_pair("two", "three"), 23);
//    gr.insert_edge(std::make_pair("three", "two"), 32);
//    gr.print();



//    graph::Graph<int, std::string, int> gr(1, "one", 11);
//    graph::Graph<int, std::string, int>::Node node(5, "five", 55);
//    gr[5] = node;
//    gr.print();

//    gr[1] = graph::Graph<int, std::string, int>::Node(1, "one";
//    gr[1] = graph::Graph<int, std::string, int>::Node(1, "one");
//    gr[2] = graph::Graph<int, std::string, int>::Node(2, "two", 22);
//    gr[3] = graph::Graph<int, std::string, int>::Node(3, "three", 33);
//    gr.print();
////    gr.insert_node(4, "four");
//    std::cout << "ПРОБЕЛ" << std::endl;
//    gr.insert_edge({2, 3}, 77);
//    gr.print();




//    gr.insert_node(4, "four");
//    gr.print();
//    graph::Graph<int, int, int>::iterator it_graph;
//    graph::Graph<int, int, int>::Node::iterator it_node;


//    gr[6] = graph::Graph<int, std::string, int>::Node(6, "six", 66);

//    std::unordered_map<std::string, std::unordered_map<std::string, int>> map("one",std::pair("two", 1));
//    map["one"] = {"two", 1};
//    map.emplace("one", std::pair("two", 1));
//    map.emplace("two", std::make_pair("one", 2));
//    std::pair<std::string, std::string> p = {"one", "two"};
//    auto it_from = map.find(p.first);
//    auto it_to = map.find(p.second);
//    std::cout << "map: " << (map.begin()->second).begin()->first << std::endl;
//    std::cout << "it_from: " << it_from->second << std::endl;
//    std::cout << "it_to: " << it_to->second << std::endl;

//    std::unordered_map<int, std::string> map;
//    map.emplace(1, "one");
//    map.emplace(2, "two");
//    std::pair<int, int> p = {1, 2};
//    auto it_from = map.find(p.first);
//    auto it_to = map.find(p.second);
//    std::cout << "map: " << map.begin()->second << std::endl;
//    std::cout << "it_from: " << it_from->second << std::endl;
//    std::cout << "it_to: " << it_to->second << std::endl;

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
