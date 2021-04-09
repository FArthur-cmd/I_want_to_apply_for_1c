//
// Created by illusioncat on 4/9/21.
//

#ifndef FOR_1C_FINDER_HPP
#define FOR_1C_FINDER_HPP

#include <cwchar>
#include <deque>
#include <fstream>
#include <memory>

#include "Node.hpp"

/**
 * Класс Finder
 *
 * Его задача искать, поэтому не удивительно, что он умеет строиться и искать =)
 *
 * Из приватных методов есть создание слова, чтение всех слов и добавление в бор,
 * но об этом подробнее в самом коде.
 */

namespace solution {

class Finder {
public:
    explicit Finder(std::wifstream &input);

    ssize_t Find(const std::wstring &need);

private:
    void ReadAllWords(std::wifstream &input);

    static std::wstring CreateWord(const std::deque<std::wstring> &pool);

    void AddWord(const std::wstring &putting, uint64_t start);

    std::unique_ptr<Node> root_;
};

}
#endif //FOR_1C_FINDER_HPP
