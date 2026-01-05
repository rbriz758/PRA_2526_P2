#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include <string>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
        BSTree<TableEntry<V>>* tree;

    public:
        BSTreeDict() {
            tree = new BSTree<TableEntry<V>>();
        }

        ~BSTreeDict() {
            delete tree;
        }

        friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs) {
            out << *(bs.tree);
            return out;
        }

        V operator[](std::string key) {
            return search(key);
        }

        void insert(std::string key, V value) override {
            TableEntry<V> entry(key, value);
            tree->insert(entry);
        }

        V search(std::string key) override {
            TableEntry<V> keyEntry(key); 
            TableEntry<V> res = tree->search(keyEntry);
            return res.value;
        }

        V remove(std::string key) override {
            TableEntry<V> keyEntry(key);
            TableEntry<V> val = tree->search(keyEntry); // Find first to get value
            tree->remove(keyEntry);
            return val.value;
        }

        int entries() override {
            return tree->size();
        }
        
};

#endif
