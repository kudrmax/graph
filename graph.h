#pragma once

#include <unordered_map>
#include <iostream>

namespace graph {
    template<typename key_type, typename value_type, typename weight_type>
    class Graph {
    public:
        class Node;

        Graph() = default;

        bool empty() const {};

        size_t size() const {};

        void clear() {};

        void swap() {};
        //Node& at(key);
        //size_t degree_in(key);
        //size_t degree_out(key);
        //bool loop(key);
    private:
        std::unordered_map<key_type, Node> m_map; // мап из нод, которые содержит граф
    };
}

template<typename key_type, typename value_type, typename weight_type>
class graph::Graph<key_type, value_type, weight_type>::Node {
public:
    Node() = default; // конструктор по умолчанию
    Node(value_type value) : m_value(value) {}; // конструктор с параметром

    bool empty() const;

    size_t size() const;

    value_type &value() { return m_value; }

    void clear();

    void print() const;

private:
    value_type m_value; // значение ноды
    std::unordered_map<key_type, weight_type> m_edge; // ребро, имеющее вес
};

template<typename key_type, typename value_type, typename weight_type>
bool graph::Graph<key_type, value_type, weight_type>::Node::empty() const {
    return m_edge.empty();
}

template<typename key_type, typename value_type, typename weight_type>
size_t graph::Graph<key_type, value_type, weight_type>::Node::size() const {
    return m_edge.size();
}

template<typename key_type, typename value_type, typename weight_type>
void graph::Graph<key_type, value_type, weight_type>::Node::clear() {
    m_edge.clear();
}

template<typename key_type, typename value_type, typename weight_type>
void graph::Graph<key_type, value_type, weight_type>::Node::print() const {
    std::cout << "m_value: " << m_value << std::endl;
    for (auto const &pair: m_edge)
        std::cout << "m_edge: {" << pair.first << ": " << pair.second << "}" << std::endl;
    std::cout << "empty(): " << empty() << std::endl;
    std::cout << "size(): " << size() << std::endl;

};
