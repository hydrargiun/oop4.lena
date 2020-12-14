
#include "Multiseat.h"
namespace oop4 {
        Multiseat::Multiseat(int a, int b,int p) : Room(a, b),free_places(p),places(p) {
            type = "Milti-seat";

    }

    Room &Multiseat::take(int d, int t, int p) {
        if (p <= free_places) {
            for (int i = 0; i < p; i++) {
                hum[i].number = i + 1;
                hum[i].date = d;
                hum[i].time = t;
            }
            free_places += p;
            busy = 1;
            people = places  - free_places;

        }
    }
    Multiseat::Multiseat() = default;


}