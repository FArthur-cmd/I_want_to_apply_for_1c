//
// Created by Arthur on 4/9/21.
//

#include "Node.hpp"

namespace solution {

Node::Node(uint64_t start) : start(start) {}

std::shared_ptr<Node> Node::AddNode(wchar_t symbol, uint64_t starts) {
    // if exists return already existing

    if (next.find(symbol) != next.end()) {
        return next.find(symbol)->second;
    }

    // else create new Node
    std::shared_ptr<Node> new_node(std::make_shared<Node>(starts));

    next[symbol] = new_node;
    new_node->current = symbol;
    return new_node;
}

std::shared_ptr<Node> Node::Find(wchar_t symbol) {
    if (next.find(symbol) == next.end()) {
        return nullptr;
    }
    return next.find(symbol)->second;
}

}