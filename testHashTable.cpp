#include <iostream>
#include "HashTable.h"

int main() {
    HashTable<int> ht(5);

    std::cout << "Testing HashTable..." << std::endl;
    
    try {
        ht.insert("one", 1);
        ht.insert("two", 2);
        ht.insert("three", 3);
        ht.insert("four", 4);
        ht.insert("five", 5);
        // Collision test depending on hash, but let's just insert more
        ht.insert("six", 6);

        std::cout << "Inserted 6 elements." << std::endl;
        std::cout << ht << std::endl;

        std::cout << "Search 'three': " << ht.search("three") << " (Expected 3)" << std::endl;
        std::cout << "Search 'one': " << ht["one"] << " (Expected 1)" << std::endl;

        std::cout << "Removing 'two'..." << std::endl;
        int val = ht.remove("two");
        std::cout << "Removed value: " << val << std::endl;
        
        std::cout << "Entries after remove: " << ht.entries() << std::endl;

        // Test error
        try {
            ht.search("two");
            std::cout << "FAIL: Found 'two' after removal" << std::endl;
        } catch(std::exception &e) {
            std::cout << "OK: 'two' not found (" << e.what() << ")" << std::endl;
        }

    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
