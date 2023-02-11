#pragma once
#include <unordered_map>

namespace graph{
    template <typename T1, typename T2, typename T3>
    class Graph{
    public:
        // ПСЕВДОНИМЫ
        using key_type = T1; // псевдоним для ключа
        using value_type = T2; // псевдоним для значения
        using weight_type = T3; // псевдоним для веса

        // КОНСТРУКТОРЫ
        Graph() noexcept = default;
        Graph(const Graph&);// конструктор копирования
        // консутрутор перемещения

        // МЕТОДЫ
        bool empty() const{};
        size_t size() const{};
        void clear (){};
        void swap(){};
        //Node& at(key);
        //size_t degree_in(key);
        //size_t degree_out(key);
        //bool loop(key);
    private:
        // РЕСУРСЫ
        key_type m_key; // ключ
        class Node;
        std::unordered_map<key_type, Node> m_map; // мап из нод, которые содержит граф
    };
}

template <typename T1, typename T2, typename T3>
class graph::Graph<T1, T2, T3>::Node{
public:
    // КОНСТРУКТОРЫ
    Node() noexcept = default; // конструктор по умолчанию
    Node(value_type value); // конструктор с параметром
    Node(const Node& node); // конструктор копирования
    // консутрутор перемещения

    // МЕТОДЫ
    bool empty(){};
    size_t size(){};
    value_type& value(){ return &m_value; }
    void clear (){};
private:

    // РЕСУРСЫ
    value_type m_value; // значение ноды
    weight_type m_weight; // вес ноды
    std::unordered_map<key_type, weight_type> m_edge; // ребро, имеющее вес
};

// NODE

template <typename T1, typename T2, typename T3> // конструктор с параметром
graph::Graph<T1, T2, T3>::Node::Node(value_type value) : m_value{value} {};

template <typename T1, typename T2, typename T3> // конструктор копирования
graph::Graph<T1, T2, T3>::Node::Node(const Node& node) {
    m_value = node.m_value;
    m_weight = node.m_weight;
    m_edge = node.m_edge;
};

// GRAPH

template <typename T1, typename T2, typename T3> // конструктор копирования
graph::Graph<T1, T2, T3>::Graph(const Graph& gr) {
    m_key = gr.m_key;
    m_map = gr.m_map;
};