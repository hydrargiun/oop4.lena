#include <iostream>
#include "Table.h"
#include "Lux.h"

namespace oop4 {

    void Table::Display() {
       for (auto it = map_all.all.begin(); it != map_all.all.end(); ++it)
        {
            std::cout <<*it->second;
            std::cout<<std::endl;
            std::cout<<std::endl;
            std::cout<<std::endl;

        }
    }

    Table &Table::Add(Room *room) {
        map_all.all.insert(std::make_pair(room->Get_number(), room));
        return *this;
    }



    void Table::Show_element(int key) {
        try {
            Room * find;
            find = Find_element(key);
            std::cout <<*find;
            std::cout <<"\n";
        }
        catch (std::exception &ex) {
            std::cout << "Exception detected: " << ex.what() << std::endl;
        }




    }

    Room *Table::Find_element(int key) {
        std::map<int,Room*> ::iterator it;
        it =  map_all.all.find(key);
        if(it != map_all.all.end()){
            return it->second;
        }
        throw std::invalid_argument("invalid number!");

    }

    Table &Table::Del(int key) {
        try {
            Room * find;
            find = Find_element(key);
            map_all.all.erase(key);
        }
        catch (std::exception &ex) {
            std::cout << "Exception detected: " << ex.what() << std::endl;
        }

        return *this;
    }

    void Table::QShow() {
        std::cout<< "Num          Type";
        std::cout << "\n";
        for (auto it = map_all.all.begin(); it != map_all.all.end(); ++it)
        {
            std::cout<< it->first;
            std::cout << "           ";
            std::cout <<it->second->Get_type();
            std::cout << "\n";

        }
    }

    std::map<int, Room *>::iterator Table::Find_it(int key) {
        std::map<int, Room *>::iterator it;
        it = map_all.all.find(key);
        return it;
    }


    Table::Table() = default;



}
