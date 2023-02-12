#include "graph.h"

//template<typename key_type, typename value_type, typename weight_type>
//graph::Graph<key_type, value_type, weight_type>::Node::Node(value_type value) : m_value(value) {};

template<typename key_type, typename value_type, typename weight_type>
bool graph::Graph<key_type, value_type, weight_type>::Node::empty() {
    return m_edge.empty();
}

template<typename key_type, typename value_type, typename weight_type>
size_t graph::Graph<key_type, value_type, weight_type>::Node::size() {
    return m_edge.size();
}

template<typename key_type, typename value_type, typename weight_type>
void graph::Graph<key_type, value_type, weight_type>::Node::clear() {
    m_edge.clear();
}
