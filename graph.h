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

        bool empty() const { return m_map.empty(); };
        size_t size() const { return m_map.size(); };
        void clear() { m_map.clear(); };
        void swap();
        void print() const;

        Node& operator[](key_type const key) { return m_map[key]; }
        Node& at(key_type const key) { return m_map.at(key); }
        //size_t degree_in(key);
        //size_t degree_out(key);
        //bool loop(key);

        std::pair<iterator, bool> insert_node(key_type key, value_type value) {
            return m_map.insert({key, value});
        }
        std::pair<iterator, bool> insert_or_assign_node(key_type key, value_type value) {
            return m_map.insert_or_assign_node({key, value});
        }
        std::pair<typename Node::iterator, bool> insert_edge(std::pair<key_type, key_type> p, weight_type weight);
    private:
        std::unordered_map<key_type, Node> m_map;
    };
}


template<typename key_type, typename value_type, typename weight_type>
class graph::Graph<key_type, value_type, weight_type>::Node {
public:
    Node() = default;
    Node(value_type value) : m_value(value) {};

    using const_iterator = typename std::unordered_map<key_type, weight_type>::const_iterator;
    using iterator = typename std::unordered_map<key_type, weight_type>::iterator;

    const_iterator cbegin() const { return m_edge.cbegin(); }
    const_iterator cend() const { return m_edge.cend(); }
    iterator begin() { return m_edge.begin(); }
    iterator end() { return m_edge.end(); }

    bool empty() const { return m_edge.empty(); }
    size_t size() const { return m_edge.size(); }
    void clear() { m_edge.clear(); }
    void print() const;
    value_type& value() { return m_value; }
//    void swap(Node& obj1, Node& obj2);

    std::pair<Graph::Node::iterator, bool> add_edge(key_type key, weight_type weight) {
        return m_edge.emplace(key, weight); // мб заменить на инсерт?
    }
//    std::pair<Graph::Node::iterator, bool> end_edge() { return {m_edge.begin(), false}; }
private:
    value_type m_value; // значение ноды
    std::unordered_map<key_type, weight_type> m_edge; // ребро, имеющее вес
};

//template<typename key_type, typename value_type, typename weight_type>
//void graph::swap(Node& obj1, Node& obj2) {
//    Node temp = obj1;
//    obj1 = obj2;
//    obj2 = temp;
//}


template<typename key_type, typename value_type, typename weight_type>
std::pair<typename graph::Graph<key_type, value_type, weight_type>::Node::iterator, bool>
graph::Graph<key_type, value_type, weight_type>::insert_edge(std::pair<key_type, key_type> p, weight_type weight) {
    auto it_from = m_map.find(p.first);
//            auto it_to = m_map.find(p.second);
    if (it_from == m_map.end() || m_map.find(p.second) == m_map.end()) {
        std::cout << "There is no key" << std::endl; // заменить потом на искобчение
        return {it_from->second.begin(), false};
//        return it_from->second.end_edge();
    }
    return it_from->second.add_edge(p.second, weight);
}

template<typename key_type, typename value_type, typename weight_type>
void graph::Graph<key_type, value_type, weight_type>::Node::print() const {
    std::cout << m_value << "" << std::endl;
    for (auto const& pair: m_edge)
        std::cout << " —> " << pair.first << " (" << pair.second << ")" << std::endl;
};

template<typename key_type, typename value_type, typename weight_type>
void graph::Graph<key_type, value_type, weight_type>::print() const {
    std::cout << "GRAPH\n" << std::endl;
    std::cout << "empty_graph(): " << empty() << std::endl;
    std::cout << "size_graph(): " << size() << std::endl;
    std::cout << std::endl;
    for (auto const& pair: m_map) {
        std::cout << "" << pair.first << ": ";
        pair.second.print();
    }
};