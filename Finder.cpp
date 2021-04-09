//
// Created by illusioncat on 4/9/21.
//

#include "Finder.hpp"


/*
 * Создаение слова.
 *   Тут создаются слова из первой буквы первого слова, второй второго слов и тд,
 *   то есть искомые ключи
 */
std::wstring Finder::CreateWord(const std::deque<std::wstring> &pool) {
    std::wstring result;
    for (size_t i = 0; i < pool.size(); ++i) {
        result.push_back(pool[i][i]);
    }
    return result;
}

/*
 * Добавление слова.
 *   Добавление реализуется с помощью удобств добавления в узел, а именно, возвращение указателя
 *   на добавленный узел. Далее добавляем до предела (то есть максимум до 5 букв). При этом в случае,
 *   если мы добавили узел, мы устанавливаем ему точку старта, таким образом каждый
 *   узел знает, где начиналось это слово.
 */
void Finder::AddWord(const std::wstring &putting, uint64_t start) {
    std::shared_ptr<Node> current = root_->AddNode(putting[0], start);

    for (uint64_t i = 1; i < putting.size(); ++i) {
        current = current->AddNode(putting[i], start);
    }
}

/*
 * Считывание всех слов.
 *   В общем это выполняет функции конструктора и сделано, чтобы сделать конструктор легковесным
 *   Считываем все слова из файла, обрабатывая их, а именно, конструируя искомые ключи и добавляя в бор
 */
void Finder::ReadAllWords(std::wifstream &input) {
    std::deque<std::wstring> words;
    std::wstring next_read;
    std::wstring word_to_put;
    uint64_t counter = 0;

    while (!input.eof()) {
        input >> next_read;
        words.emplace_back(next_read);

        // Не имеет смысла рассматривать слова длинной
        // больше пяти символов
        if (words.size() == 6) {
            words.pop_front();
            ++counter;
        }

        word_to_put = CreateWord(words);
        AddWord(word_to_put, counter);
    }

    // Необходимо добавить конечный случай, то есть обработать количество
    // слов меньше пяти на конце всего текста
    while (words.size() != 1) {
        words.pop_front();
        ++counter;

        word_to_put = CreateWord(words);
        AddWord(word_to_put, counter);
    }
}

/*
 * Поиск использует тривиальный поиск, который возвращает либо результат, либо nullptr
 * в случае неудачи. Тогда наш поиск вернет -1, а в случае успеха дойдет до конца слова и
 * вернет индекс его старта, который был записан изначально
 */
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