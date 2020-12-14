#include "Room.h"
#include <iostream>
#include <string>
namespace oop4 {


    Room::Room() = default;

    Room::Room(int number, int cost) : num(number),busy(0), cost_per_day(cost) {
    }

    int Room::Get_number() const {
        return this->num;
    }

    std::ostream& operator << (std::ostream& out, const Room& room){
        out << "Room num -> ";
        out <<" "<< room.num<<"\n";
        out << "Room type -> ";
        out <<" "<< room.type<<"\n";
        (room.busy == 1)?(out << "busy\n"):(out << "free\n");
        out << "Room cost -> ";
        out <<" "<<room.cost_per_day<<"\n";
        room.show(out);
        return out;

    }


    Room& Room::Set_date(int d, int t) {
        date = d;
        time = t;
        return *this;
    }

    Room &Room::take(int d, int t) {
        this->Set_date(d,t);
        busy = 1;
        people = 1;
        return *this;
    }

    Room &Room::take(int d, int t, int p) {
        this->people = p;
        this->Set_date(t,d);
        this->busy = 1;
        return *this;

    }

    std::ostream &Room::show(std::ostream &out) const {

            out << "Amount of people ";
            out << this->people <<"\n";
            (busy == 1)?(out << "busy from "<<date<<"\n"<<"busy for "<<time<<"\n"):(out <<"not busy");
            return out;


    }




}
