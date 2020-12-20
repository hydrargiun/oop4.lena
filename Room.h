#ifndef OOP4_LENA_ROOM_H
#define OOP4_LENA_ROOM_H
#include <string>
namespace oop4 {
    class Room {
    private:
        int num;
        int busy;
        int people;
        int cost_per_day;
        std::string type;

    protected:
        virtual std::ostream& show(std::ostream&)const = 0;
        //virtual Room& Take(int d, int t, int p) = 0;
    public:
         friend std::ostream& operator << (std::ostream& out, const Room&);
         Room &Set_first(int n, int c, const std::string&);
         Room &Set_busy(int);
         Room &Set_people(int);
         int Get_busy() const;
         int Get_number() const ;
         int Get_people() const;
         int Get_cost() const;
         std::string Get_type();
         virtual Room& Take(int d, int t, int p) = 0;
         virtual Room& Checkout(int p) = 0;
         virtual int Cost(int p) = 0;

         

    };
}

#endif