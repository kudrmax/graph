#pragma once

#include <unordered_map>
#include <iostream>

namespace graph {
    template<typename key_type, typename value_type, typename weight_type>
    class Graph {
    public:
        class Node;
        using const_iterator = typename std::unordered_map<key_type, Node>::const_iterator;
        using iterator = typename std::unordered_map<key_type, Node>::iterator;

        const_iterator cbegin() const { return m_map.cbegin(); };
        const_iterator cend() const { return m_map.cend(); };
        iterator begin() { return m_map.begin(); };
        iterator end() { return m_map.end(); };

        Graph() = default;
        Graph(key_type key, value_type value, weight_type weight) {
            Node temp(key, value, weight);
            m_map.emplace(key, temp);
        };

        bool empty() const {};
        size_t size() const {};
        void clear() {};
        void swap() {};

        //Node& at(key);
        //size_t degree_in(key);
        //size_t degree_out(key);
        //bool loop(key);
        void print() const;

//        std::pair<Graph::iterator, bool> insert_node(key_type key, value_type val);
    public:
        std::unordered_map<key_type, Node> m_map; // мап из нод, которые содержит граф
    };
}


template<typename key_type, typename value_type, typename weight_type>
class graph::Graph<key_type, value_type, weight_type>::Node {
public:
    Node() = default; // конструктор по умолчанию
    Node(value_type value) : m_value(value) {}; // конструктор с параметром
    Node(key_type key, value_type value, weight_type weight) : m_value(value) {
        m_edge.emplace(key, weight);
    };


    bool empty() const;
    size_t size() const;

    value_type& value() { return m_value; }

    void clear();
    void print() const;

//    void swap(Node& obj1, Node& obj2);
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

//template<typename key_type, typename value_type, typename weight_type>
//void graph::swap(Node& obj1, Node& obj2) {
//    Node temp = obj1;
//    obj1 = obj2;
//    obj2 = temp;
//}

template<typename key_type, typename value_type, typename weight_type>
void graph::Graph<key_type, value_type, weight_type>::Node::print() const {
    std::cout << "m_value: " << m_value << std::endl;
    for (auto const& pair: m_edge)
        std::cout << "m_edge: {" << pair.first << ": " << pair.second << "}" << std::endl;
    std::cout << "empty(): " << empty() << std::endl;
    std::cout << "size(): " << size() << std::endl;
    std::cout << std::endl;
};

template<typename key_type, typename value_type, typename weight_type>
void graph::Graph<key_type, value_type, weight_type>::print() const {
    std::cout << "I'm here";
    for (auto const& node: m_map) {
        std::cout << node.first << std::endl;
        (node.second).print();
    }
};

//template<typename key_type, typename value_type, typename weight_type>
//std::pair<graph::Graph<key_type, value_type, weight_type>::iterator, bool>
//graph::Graph<key_type, value_type, weight_type>::insert_node(key_type key, value_type val) {
//
//    return std::make_pair(it, 1);
//}