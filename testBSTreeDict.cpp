#include <iostream>
#include "BSTreeDict.h"

int main() {
    BSTreeDict<int> dict;

    std::cout << "Testing BSTreeDict..." << std::endl;

    dict.insert("c", 3);
    dict.insert("a", 1);
    dict.insert("b", 2);
    dict.insert("d", 4);

    std::cout << "Dict content (Inorder by Key): " << dict << std::endl;
    // Expected: ('a' => 1) ('b' => 2) ('c' => 3) ('d' => 4)

    std::cout << "Search 'b': " << dict.search("b") << std::endl;
    std::cout << "Search 'c': " << dict["c"] << std::endl;

    try {
        dict.search("z");
    } catch (std::exception &e) {
        std::cout << "Search 'z' failed: " << e.what() << std::endl;
    }

    std::cout << "Removing 'a'..." << std::endl;
    int val = dict.remove("a");
    std::cout << "Removed: " << val << std::endl;
    std::cout << "Dict content: " << dict << std::endl;

    std::cout << "Entries: " << dict.entries() << std::endl;

    std::cout << "All BSTreeDict tests passed." << std::endl;
    return 0;
}
