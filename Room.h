#ifndef OOP4_LENA_ROOM_H
#define OOP4_LENA_ROOM_H
#include <string>
namespace oop4 {
    class Room {
    private:
        int num;
        int cost_per_day;
    protected:
        std::string type;
        int date;
        int time;
        int people;
        int busy;


    public:
     Room();
     Room(int,int);
     int Get_number() const;
     friend std::ostream& operator << (std::ostream& out, const Room& );
     virtual std::ostream& show(std::ostream&)const;
     virtual Room& Set_date(int d, int t);
     Room& take(int d, int t);
     virtual Room& take(int d, int t, int p);


    };
}

#endif