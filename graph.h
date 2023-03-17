#pragma once

#include <unordered_map>
#include <iostream>
#include <iomanip>
#include <vector>

namespace graph {
    template<typename key_type, typename value_type, typename weight_type>
    class Graph {
    public:
        class Node;
        using const_iterator = typename std::unordered_map<key_type, Node>::const_iterator;
        using iterator = typename std::unordered_map<key_type, Node>::iterator;

        const_iterator cbegin() const { return m_map.cbegin(); }
        const_iterator cend() const { return m_map.cend(); }
        iterator begin() { return m_map.begin(); }
        iterator end() { return m_map.end(); }
        const_iterator begin() const { return m_map.begin(); }
        const_iterator end() const { return m_map.end(); }

        bool empty() const { return m_map.empty(); }
        size_t size() const { return m_map.size(); }
        void clear() { m_map.clear(); }
        void swap(Graph<key_type, value_type, weight_type>&);
        void print() const;
        void print_matrix() const;

        Node& operator[](key_type const key) { return m_map[key]; }
        Node& at(key_type const key) { return m_map.at(key); }
        const_iterator find(key_type const key) const { return m_map.find(key); }

        size_t degree_in(key_type key) const { return m_map.find(key)->second.size(); }
        size_t degree_out(key_type) const;
        bool loop(key_type) const;

        std::pair<iterator, bool> insert_node(key_type key, value_type value);
        std::pair<iterator, bool> insert_or_assign_node(key_type key, value_type value);

        std::pair<typename Node::iterator, bool> insert_edge(std::pair<key_type, key_type>, weight_type);

    private:
        std::unordered_map<key_type, Node> m_map;
    };

    template<typename key_type, typename value_type, typename weight_type>
    void swap(Graph<key_type, value_type, weight_type>& gr1,
              Graph<key_type, value_type, weight_type>& gr2) { gr1.swap(gr2); }
}

template<typename key_type, typename value_type, typename weight_type>
class graph::Graph<key_type, value_type, weight_type>::Node {
public:
    Node() = default;
    Node(value_type value) : m_value(value) {};
    // Node(const Node&);
    // Node(Node&&);
    // operator= // copy
    // operator= // move

    using const_iterator = typename std::unordered_map<key_type, weight_type>::const_iterator;
    using iterator = typename std::unordered_map<key_type, weight_type>::iterator;

    const_iterator cbegin() const { return m_edge.cbegin(); }
    const_iterator cend() const { return m_edge.cend(); }
    iterator begin() { return m_edge.begin(); }
    iterator end() { return m_edge.end(); }
    const_iterator begin() const { return m_edge.begin(); }
    const_iterator end() const { return m_edge.end(); }

    bool empty() const { return m_edge.empty(); }
    size_t size() const { return m_edge.size(); }
    void clear() { m_edge.clear(); }
    void print() const;
    value_type& value() const { return m_value; }

    std::pair<Graph::Node::iterator, bool> add_edge(key_type key, weight_type weight);
    std::unordered_map<key_type, weight_type> get_edge() const { return m_edge; }

private:
    mutable value_type m_value;
    std::unordered_map<key_type, weight_type> m_edge;
};

template<typename key_type, typename value_type, typename weight_type>
std::pair<typename graph::Graph<key_type, value_type, weight_type>::iterator, bool>
graph::Graph<key_type, value_type, weight_type>::insert_node(key_type key, value_type value) {
    return m_map.insert({ key, value });
}

template<typename key_type, typename value_type, typename weight_type>
std::pair<typename graph::Graph<key_type, value_type, weight_type>::iterator, bool>
graph::Graph<key_type, value_type, weight_type>::insert_or_assign_node(key_type key, value_type value) {
    return m_map.insert_or_assign_node({ key, value });
}

template<typename key_type, typename value_type, typename weight_type>
std::pair<typename graph::Graph<key_type, value_type, weight_type>::Node::iterator, bool>
graph::Graph<key_type, value_type, weight_type>::Node::add_edge(key_type key, weight_type weight) {
    return m_edge.emplace(key, weight);
} // мб заменить на инсерт?

template<typename key_type, typename value_type, typename weight_type>
void graph::Graph<key_type, value_type, weight_type>::swap(Graph<key_type, value_type, weight_type>& gr) {
    m_map.swap(gr.m_map);
}

template<typename key_type, typename value_type, typename weight_type>
std::pair<typename graph::Graph<key_type, value_type, weight_type>::Node::iterator, bool>
graph::Graph<key_type, value_type, weight_type>::insert_edge(std::pair<key_type, key_type> p, weight_type weight) {
    auto it_from = m_map.find(p.first);
//            auto it_to = m_map.find(p.second);
    if (it_from == m_map.end() || m_map.find(p.second) == m_map.end()) {
        std::cout << "There is no key" << std::endl; // заменить потом на exceptions
        return { it_from->second.begin(), false };
//        return it_from->second.end_edge();
    }
    return it_from->second.add_edge(p.second, weight);
}

template<typename key_type, typename value_type, typename weight_type>
size_t graph::Graph<key_type, value_type, weight_type>::degree_out(key_type key) const {
    size_t degree_out_count = 0;
    for (auto const& pair: m_map) {
        if (pair.first != key) {
            auto node = pair.second;
            auto edge_map = node.edge();
            if (edge_map.find(key) != edge_map.end()) ++degree_out_count;
        }
    }
    return degree_out_count;
}

template<typename key_type, typename value_type, typename weight_type>
bool graph::Graph<key_type, value_type, weight_type>::loop(key_type key) const {
    if (!m_map.count(key))
        return false;
    auto node = m_map.find(key)->second;
    auto edge_map = node.edge();
    for (auto const& pair: edge_map)
        if (pair.first == key) return true;
    return false;
}

template<typename key_type, typename value_type = int, typename weight_type>
void print_value(value_type val) {
    std::cout << "AAA";
}


template<typename key_type, typename value_type, typename weight_type>
void graph::Graph<key_type, value_type, weight_type>::Node::print() const {
////    std::cout << m_value << "" << std::endl;
////    std::cout << "{" << m_value.first << ", " << m_value.second << "}" << std::endl;
////    print_value(m_value);
////    print_value(5);
    std::cout << std::endl;
    for (auto const& pair: m_edge)
        std::cout << " —> " << pair.first << " (" << pair.second << ")" << std::endl;
};


template<typename key_type, typename value_type, typename weight_type>
void graph::Graph<key_type, value_type, weight_type>::print() const {
    std::cout << "GRAPH\n" << std::endl;
//    std::cout << "empty_graph(): " << empty() << std::endl;
//    std::cout << "size_graph(): " << size() << std::endl;
//    std::cout << std::endl;
    for (auto const& pair: m_map) {
        std::cout << "" << pair.first << ": ";
        pair.second.print();
    }
    std::cout << std::endl;
};

template<typename key_type, typename value_type, typename weight_type>
bool is_edge(typename graph::Graph<key_type, value_type, weight_type>::const_iterator& row_it) {
    return true;
}

template<typename key_type, typename value_type, typename weight_type>
void graph::Graph<key_type, value_type, weight_type>::print_matrix() const {
//    const_iterator row_it = this->cbegin();
//    is_edge(this->begin());
//    auto row_it = m_map.begin();
//    is_edge(row_it, row_it);


//    for (auto row_it = this->cbegin(); row_it != this->cend(); ++row_it) {
//        for (auto column_it = this->cbegin(); column_it != this->cend(); ++column_it) {
//            if (is_edge(row_it, column_it)) {
//                std::cout << 1 << ' ';
//            } else {
//                std::cout << 0 << ' ';
//            }
//        }
//        std::cout << std::endl;
//    }

//    auto size = this->size();
//    std::vector<std::tuple<key_type, key_type, weight_type>> vec(size * size);
//    size_t i = 0;
//    size_t j = 0;
//    for (auto const& pair: m_map) {
//        auto node = pair.second;
//        auto edge = node.get_edge();
//        ++i;
//        for (auto const& ed: edge) {
//            vec[i + j] = { i, j, ed.second };
//            ++j;
//        }
//    }
//    for (size_t ii = 0; ii < size; ++ii) {
//        std::cout << "| ";
//        for (size_t jj = 0; jj < size; ++jj)
//            std::cout << std::get<2>(vec[ii + jj]) << ' ';
//        std::cout << "|\n";
//    }


//    auto size = this->size();
//    std::vector<int> vec(size * size, 0);
//    size_t i = 0;
//    size_t j = 0;
//    for (auto const& pair: m_map) {
//        auto node = pair.second;
//        auto edge = node.get_edge();
//        ++i;
//        for (auto const& ed: edge) {
//            vec[i + j] = ed.second;
//            ++j;
//        }
//    }
//    for (size_t ii = 0; ii < size; ++ii) {
//        std::cout << "| ";
//        for (size_t jj = 0; jj < size; ++jj)
//            std::cout << vec[ii + jj] << ' ';
//        std::cout << " |\n";
//    }
}