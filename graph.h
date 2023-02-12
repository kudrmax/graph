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

    bool empty();

    size_t size();

    value_type &value() { return m_value; }

    void clear();

    void print() {
        std::cout << m_value << std::endl;
        for (auto const &pair: m_edge)
            std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    };

private:
    value_type m_value; // значение ноды
    std::unordered_map<key_type, weight_type> m_edge; // ребро, имеющее вес
};