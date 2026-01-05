#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include <string>
#include "Dict.h"
#include "TableEntry.h"

#include "ListLinked.h" // Replacing std::list

template <typename V>
class HashTable: public Dict<V> {

    private:
        int n; // Number of elements
        int max; // Table size (buckets)
        ListLinked<TableEntry<V>>* table; // Array of buckets (lists)

        int h(std::string key) {
            int sum = 0;
            for (char c : key) {
                sum += int(c);
            }
            return sum % max;
        }

    public:
        HashTable(int size) : n(0), max(size) {
            if (size <= 0) throw std::runtime_error("Size must be positive");
            table = new ListLinked<TableEntry<V>>[max];
        }

        ~HashTable() {
            delete[] table;
        }

        int capacity() { 
            return max; 
        }

        friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th) {
            out << "HashTable [entries: " << th.n << ", capacity: " << th.max << "]" << std::endl;
            out << "==============" << std::endl << std::endl;
            for (int i = 0; i < th.max; ++i) {
                out << "== [" << i << "] ==" << std::endl;
                // ListLinked usually only supports iteration via get() or search().
                // However, our ListLinked implements operator<< to print all elements.
                // But to print formatted like "  (key => value)", we might need to iterate.
                // Since ListLinked doesn't expose iterators in the basic version, we use get().
                // Note: get() is O(N), so loop is O(N^2) for printing a bucket. 
                // In a proper implementation we would add iterators to ListLinked.
                for (int j = 0; j < th.table[i].size(); ++j) {
                    out << "  " << th.table[i].get(j) << std::endl;
                }
            }
            out << "==============" << std::endl;
            return out;
        }

        V operator[](std::string key) {
            return search(key);
        }

        void insert(std::string key, V value) override {
            int idx = h(key);
            // Check if key exists
            TableEntry<V> entryToFind(key); // Dummy entry just for key comparison
            int pos = table[idx].search(entryToFind);
            if (pos != -1) {
                 throw std::runtime_error("Key already exists: " + key);
            }
            table[idx].prepend(TableEntry<V>(key, value));
            n++;
        }

        V search(std::string key) override {
            int idx = h(key);
            TableEntry<V> entryToFind(key);
            int pos = table[idx].search(entryToFind);
            if (pos == -1) {
                 throw std::runtime_error("Key not found: " + key);
            }
            return table[idx].get(pos).value;
        }

        V remove(std::string key) override {
            int idx = h(key);
            TableEntry<V> entryToFind(key);
            int pos = table[idx].search(entryToFind);
            if (pos == -1) {
                 throw std::runtime_error("Key not found: " + key);
            }
            V val = table[idx].get(pos).value; // Get value before removing
            table[idx].remove(pos);
            n--;
            return val;
        }

        int entries() override {
            return n;
        }
};

#endif
