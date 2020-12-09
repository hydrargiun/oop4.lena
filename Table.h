#ifndef OOP4_LENA_TABLE_H
#define OOP4_LENA_TABLE_H
#include "Room.h"
#include <map>
#include <vector>
namespace oop4 {

    class Table {
    public:
        Table();
        void Display();
        Table &Add(int);
        Table &Resort(int);
        void Show_vec();
        class Vec {
        private:
            std::vector<int> vec;
        public:
            Vec();
            Vec &Sort();
            Vec &Add(int);
            int Get_vec_pos(int);
            friend Table;
        };
    private:
        std::map<int, int> TMap;
        Vec nums;
    };


}

#endif