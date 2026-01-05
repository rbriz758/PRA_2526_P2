#include <iostream>
#include <string>
#include "TableEntry.h"

int main() {
    TableEntry<int> te1("Key1", 10);
    TableEntry<int> te2("Key1", 20); // Same key, diff value
    TableEntry<int> te3("Key2", 10); // Diff key

    std::cout << "Testing TableEntry..." << std::endl;
    std::cout << "te1: " << te1 << std::endl;
    std::cout << "te2: " << te2 << std::endl;
    std::cout << "te3: " << te3 << std::endl;

    if (te1 == te2) {
        std::cout << "te1 == te2: OK (Same key)" << std::endl;
    } else {
        std::cout << "te1 == te2: FAIL" << std::endl;
    }

    if (te1 != te3) {
        std::cout << "te1 != te3: OK (Diff key)" << std::endl;
    } else {
        std::cout << "te1 != te3: FAIL" << std::endl;
    }

    return 0;
}
