//
// Created by artem on 19.10.23.
//

#ifndef STRUCTS_DICTS_H
#define STRUCTS_DICTS_H

/*
    Файл для обьявления всех вспомогательных утилит использовавшихся в проектах
*/

// 1. Библиотеки использовавшиеся в проeкте

#include <string>

#define BASE_DICT_LENGTH 8

// 2. Dict класс

namespace CustomStructs {

    typedef std::string Key;

    template<typename Item = int>
    class Dict {
    private:
        struct Node {
            Key key;
            Item value;
        }; // Элeменты ячейки словаря
        Node **nodes; // Список указателей на ячейки словаря
        int size;  // Размер словаря
        int usedSize;  // Кол-во используемых ячеек

        int hash(Key k); // Ф-я хеширования ключа
        void resizable(); // Ф-я по увелечению словаря и перезаполнению его
    public:
        Dict(int s = BASE_DICT_LENGTH);
        virtual ~Dict();
        Item &get(const Key k);
        bool push(const Key k, const Item item);
        virtual bool del(const Key k);
        void show() const;
        int length() const;
    };

}

#endif //STRUCTS_DICTS_H
