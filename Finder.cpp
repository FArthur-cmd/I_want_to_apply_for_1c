//
// Created by illusioncat on 4/9/21.
//

#include "Finder.hpp"


std::wstring Finder::CreateWord(const std::deque<std::wstring> &pool) {
    std::wstring result;
    for (size_t i = 0; i < pool.size(); ++i) {
        result.push_back(pool[i][i]);
    }
    return result;
}

void Finder::AddWord(const std::wstring &putting, uint64_t start) {
    std::shared_ptr<Node> current = root_->AddNode(putting[0], start);

    for (uint64_t i = 1; i < putting.size(); ++i) {
        current = current->AddNode(putting[i], start);
    }
}

void Finder::ReadAllWords(std::wifstream &input) {
    std::deque<std::wstring> words;
    std::wstring next_read;
    std::wstring word_to_put;
    uint64_t counter = 0;

    while (!input.eof()) {
        input >> next_read;
        words.emplace_back(next_read);

        if (words.size() == 6) {
            words.pop_front();
            ++counter;
        }

        word_to_put = CreateWord(words);
        AddWord(word_to_put, counter);
    }

    while (words.size() != 1) {
        words.pop_front();
        ++counter;

        word_to_put = CreateWord(words);
        AddWord(word_to_put, counter);
    }
}

ssize_t Finder::Find(const std::wstring &need) {
    std::shared_ptr<Node> current = root_->Find(need[0]);
    if (current == nullptr) {
        return -1;
    }

    size_t index = 1;
    while (index < need.size()) {
        current = current->Find(need[index]);
        if (current == nullptr) {
            return -1;
        }
        ++index;
    }

    return current->start;
}

Finder::Finder(std::wifstream &input): root_(new Node()) {
    ReadAllWords(input);
}