#include <iostream>
#include "Table.h"
#include <algorithm>


namespace oop4 {

    void Table::Display() {
        for (auto x : this->TMap) {
            std::cout << x.first <<  " -> ";
            std::cout << x.second;
            std::cout<<std::endl;
        }
    }

    Table &Table::Add(int room_num) {
        nums = nums.Add(room_num);
        int pos = nums.Get_vec_pos(room_num);
        *this = this->Resort(pos);
        TMap.insert(std::make_pair(pos,room_num));

        return *this;
    }

    Table::Table() = default;

    void Table::Show_vec() {
        for (int & it : nums.vec)
            std::cout<<it;
    }

    Table &Table::Resort(int adding_pos) {
      if(adding_pos < TMap.size()){
          std::map<int, int> ::iterator it1;
          std::map<int, int> ::iterator it2;
          it2 = TMap.end();
          it1 = TMap.find(adding_pos);
         if (it1 != TMap.begin()) {
             it1--;
             it2--;
             while (it2 != it1) {
                 TMap.insert(std::make_pair(it2->first + 1, it2->second));
                 it2--;
                 TMap.erase(it2->first + 1);


             }
             return *this;
         }
         else{
             it2--;
             while (it2 != TMap.begin()){
                 TMap.insert(std::make_pair(it2->first + 1, it2->second));
                 it2--;
                 TMap.erase(it2->first + 1);

             }
             TMap.insert(std::make_pair(it1->first + 1, it1->second));
             TMap.erase(it1->first);
             return *this;
         }
      }

        return *this;
    }

    Table::Vec::Vec() = default;

    int Table::Vec::Get_vec_pos(int Room_num) {
        auto it = std::find(vec.begin(), vec.end(), Room_num);
        auto index = std::distance(vec.begin(), it);
        return index;
    }

    Table::Vec & Table::Vec::Sort() {
        sort(vec.begin(), vec.end());
        return *this;
    }

    Table:: Vec & Table::Vec::Add(int room_num) {
        vec.push_back(room_num);
        this->Sort();
        return *this;
    }

}
