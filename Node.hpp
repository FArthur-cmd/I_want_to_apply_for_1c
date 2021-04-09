//
// Created by Arthur on 4/9/21.
//

#ifndef FOR_1C_NODE_HPP
#define FOR_1C_NODE_HPP

#endif //FOR_1C_NODE_HPP

#include <memory>
#include <unordered_map>

/**
 * Класс Node для реализации бора
 *
 * Методы:
 *     Добавление по символу с учетом стартовой позиции для вывода ответа.
 *     Поиск элемента и возврат nullptr в случае неудачи
 */
struct Node {
    explicit Node(uint64_t start=0);

    std::shared_ptr<Node> AddNode(wchar_t symbol, uint64_t starts);

    std::shared_ptr<Node> Find(wchar_t symbol);

    wchar_t current;
    uint64_t start;
    std::unordered_map<wchar_t, std::shared_ptr<Node>> next;
};