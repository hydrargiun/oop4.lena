#ifndef OOP4_LENA_TABLE_H
#define OOP4_LENA_TABLE_H
#include <map>
#include <vector>
#include "Room.h"
namespace oop4 {
    class Table {
    private:
        class TMap{
        public:
            std::map<int,Room*> all;
            std::map<int, Room*> free;

        };
        TMap map_all;
    public:
        Table();
        Room* Find_element(int key);
        std::map<int, Room *>::iterator Find_it(int);
        void Display();
        Table &Add(Room *);
        void Show_element(int k);
        Table &Del(int);
        void QShow();



};

}

#endif
