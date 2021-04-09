#include <iostream>

#include "Finder.hpp"

/**
 * open file, create finder to read all information and create bor
 *
 * read count of tests
 *
 * read request and print result
 */
int main(int argc, char **argv) {
    if (argc < 1) {
        std::cout << "You forgot to enter full path to file" << std::endl;
    }
    std::wifstream in_file(argv[1]);

    if (!in_file.is_open()) {
        std::cout << "Error with open" << std::endl;
        return 0;
    }

    Finder answer(in_file);

    size_t n;
    std::wcin >> n;

    std::wstring request;
    for (size_t i = 0; i < n; ++i) {
        std::wcin >> request;
        std::cout << answer.Find(request) << std::endl;
    }

    return 0;
}
