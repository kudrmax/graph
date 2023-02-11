#pragma once
#include <unordered_map>

namespace graph{
    template <typename key_type, typename value_type, typename weight_type>
    class Graph{
    public:
        Graph() = default;

        bool empty() const{};
        size_t size() const{};
        void clear (){};
        void swap(){};
        //Node& at(key);
        //size_t degree_in(key);
        //size_t degree_out(key);
        //bool loop(key);
    private:
        class Node;
        std::unordered_map<key_type, Node> m_map; // мап из нод, которые содержит граф
    };
}

template <typename key_type, typename value_type, typename weight_type>
class graph::Graph<key_type, value_type, weight_type>::Node{
public:
    Node() = default; // конструктор по умолчанию
    Node(value_type value); // конструктор с параметром

    bool empty(){};
    size_t size(){};
    value_type& value(){ return &m_value; }
    void clear (){};
private:
    value_type m_value; // значение ноды
    std::unordered_map<key_type, weight_type> m_edge; // ребро, имеющее вес
};

template <typename key_type, typename value_type, typename weight_type> // конструктор с параметром
graph::Graph<key_type, value_type, weight_type>::Node::Node(value_type value) : m_value{value} {};