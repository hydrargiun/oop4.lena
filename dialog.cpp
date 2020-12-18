#include <iostream>
#include "dialog.h"
#include "Table.h"
#include "getnum.h"
#include "Lux.h"
#include "Standart.h"
#include "Multiseat.h"

namespace oop4{
    Table* (*fptr[])(Table *) = {NULL, D_Add, D_Del, D_Show, D_Find, D_QShow, D_Take, D_Checkout};
    Table table;
    void dialog() {
        while (true) {
            std::cout << "" << std::endl;
            std::cout << "0. Выход" << std::endl;
            std::cout << "1. Добавить номер " << std::endl;
            std::cout << "2. Удалить номер" << std::endl;
            std::cout << "3. Вывод всего списка" << std::endl;
            std::cout << "4. Вывод номера" << std::endl;
            std::cout << "5. Вывод таблицы типа номер-тип" << std::endl;
            std::cout << "6. Заселить" << std::endl;
            std::cout << "7. Выселить " << std::endl;
           // std::cout << "8.  " << std::endl;
           // std::cout << "9.  " << std::endl;
          //  std::cout << "10. " << std::endl;
          //  std::cout << "11. " << std::endl;
          //  std::cout << "12. " << std::endl;
            int pt;
            pt = getNum<int>();
            if (!fptr[pt](&table)) {
                break;
            }
        }


    }

    Table* D_Add(Table *tab){
        int num = 0;
        int cost = 0;
        std::cout <<"Введите ключ = ";
        std::cin >> num;
        std::cout <<"Введите цену = ";
        std::cin >> cost;
        std::cout << "Выберите тип";
        std::cout << "\n1. Lux\n2. Standart\n3. Multiseat\n";
        int ptr;
        std::cin >> ptr;
            if(ptr == 1)
            {
                Room *c = new Lux(num, cost);
                tab = &tab->Add(c);
            }
            if(ptr == 2)
            {
                Room *c = new Standart(num, cost);
                tab = &tab->Add(c);
            }
            if(ptr == 3)
            {   int p = 0;
                std::cout<<"Введите колличество мест ";
                std::cin >> p;
                Room *c = new Multiseat(num, cost,p);
                tab = &tab->Add(c);
            }

        return tab;
    }
    Table* D_Del(Table* tab){
        std::cout <<"Введите ключ ";
        int key;
        std::cin >> key;
        tab->Del(key);
        return tab;

    }
    Table* D_Show(Table* tab){
        tab->Display();
        return tab;
    }
    Table* D_Find(Table* tab){
        int num;
        std::cin >> num;
        tab->Show_element(num);
        return tab;
    }
    Table* D_QShow(Table* tab){
        tab->QShow();
        return tab;
    }
    Table* D_Take(Table* tab){
        std::cout <<"Введите ключ ";
        int key;
        std::cin >> key;
        int date;
        int time;
        int people;
        std::cout<<"Date of register-> ";
        std::cin >> date;
        std::cout<<"Time-> ";
        std::cin >> time;
        std::cout<<"People-> ";
        std::cin >> people;
        tab->Find_element(key)->Take(date,time,people);
        return tab;
    }
    Table* D_Checkout(Table* tab) {
        std::cout << "Введите ключ ";
        int key;
        std::cin >> key;
        std::map<int, Room *>::iterator it;
        it = tab->Find_it(key);
        if (it->second->Get_type() != "Multiseat") {
            it->second->Checkout(it->second->Get_people());
        } else {
            int p;
            std::cout<<"Введите индeкс человека ";
            std::cin >> p;

            try {
                it->second->Checkout(p);
            }
            catch (std::exception &ex) {
                std::cout << "Exception detected: " << ex.what() << std::endl;
            }
        }
        return tab;
    }
}
