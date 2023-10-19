//
// Created by artem on 19.10.23.
//

#include "dicts.hpp"


// Словарь значений
namespace CustomStructs {

    template<typename Item>
    Dict<Item>::Dict(int s) {
        size = s;
        nodes = new Node*[s] {nullptr};
        usedSize = 0;
    };

    template<typename Item>
    Dict<Item>::~Dict() {
        for (int i = 0; i < size; i++) {
            if (nodes[i] != nullptr) {
                delete nodes[i];
            }
        }
        delete [] nodes;
    };

    template<typename Item>
    int Dict<Item>::hash(Key k) {
        int val = 0;
        for (int i = 0; i < k.length(); i++) {
            val = (val * 1000003) ^ k[i];
        }
        val = val < 0 ? val * -1 : val;
        /*
            h(k) = (h1(k) + i*h2(k)) % m
            h1(k) = k,
            h2(k) = k % (m-1) if(h2 % 2 == 0) + 1,
            where m = size_dict = 2^n
        */
        int h1 = val % size;
        int h2 = val % 1001531;
        if (h2 % 2 == 0) h2++;
        int j;
        for (int i = 0; i < size; i++) {
            j = (h1 + i * h2) % size;
            if (nodes[j] == nullptr || nodes[j]->key == k)
                break;
        }
        return j;
    };

    template<typename Item>
    bool Dict<Item>::push(const Key k, const Item item) {
        int pos = hash(k);
        if(pos >= size) return false;
        if (nodes[pos] != nullptr && nodes[pos]->key == k) {
            nodes[pos]->value = item;
            return true;
        }
        Node *newNode = new Node;
        newNode->key = k;
        newNode->value = item;
        nodes[pos] = newNode;
        usedSize++;

        if (usedSize >= size / 3 * 2) {
            int oldSize = size;
            size = usedSize > 50000 ? 2 * size : 4 * size;

            Node* oldNodes = nodes;
            nodes = new Node*[size];

            for (int i = 0; i < oldSize; i++) {
                if (oldNodes[i] == nullptr) continue;
                push(oldNodes[i]->key, oldNodes[i]->value);
            }
            delete [] oldNodes;
        }

        return true;
    };

    template<typename Item>
    bool Dict<Item>::del(Key key) {
        int i = hash(key);
        if (i >= size)
            return false;
        delete nodes[i];
        nodes[i] = nullptr;
        return true;
    }

    template<typename Item>
    Item &Dict<Item>::get(Key key) {
        int i = hash(key);
        if (i >= size)
            return nullptr;
        return nodes[i]->value;
    }

}

