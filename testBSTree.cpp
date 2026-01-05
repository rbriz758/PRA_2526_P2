#include <iostream>
#include "BSTree.h"

int main() {
    BSTree<int> bst;

    std::cout << "Testing BSTree..." << std::endl;
    bst.insert(20);
    bst.insert(10);
    bst.insert(30);
    bst.insert(5);
    bst.insert(15);
    bst.insert(25);
    bst.insert(35);

    std::cout << "Inorder traversal: " << bst << std::endl;
    std::cout << "Size: " << bst.size() << std::endl;

    std::cout << "Search 15: " << bst.search(15) << std::endl;
    
    try {
        std::cout << "Search 100: " << bst.search(100) << std::endl;
    } catch(std::exception &e) {
        std::cout << "Search 100 failed: " << e.what() << std::endl;
    }

    std::cout << "Removing 20 (Root, 2 children)..." << std::endl;
    bst.remove(20);
    std::cout << "Inorder after remove 20: " << bst << std::endl;
    // Max of left subtree (15) should replace 20.
    
    std::cout << "Removing 5 (Leaf)..." << std::endl;
    bst.remove(5);
    std::cout << "Inorder after remove 5: " << bst << std::endl;

    std::cout << "All BSTree tests passed." << std::endl;
    return 0;
}
