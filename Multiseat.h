
#include "Room.h"
#ifndef OOP4_LENA_MULTISEAT_H
#define OOP4_LENA_MULTISEAT_H

namespace oop4 {
    class Multiseat : public Room {
    private:
        struct humans{
            int number;
            int date;
            int time;
        };
        humans hum[4];
        int places;
        int free_places;

    public:
        Multiseat();
        Multiseat(int, int, int);
        Room& take(int d, int t, int p) override;
    };
}

#endif
