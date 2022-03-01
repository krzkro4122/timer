#include <assert.h>
#include <iostream>
#include "Time.h"

int main()
{
    int timestamp = 101069;
    timer::Time t(timestamp);
    std::cout << t << std::endl;

    assert(t.getDays() == 1);
    assert(t.getHours() == 4);
    assert(t.getMinutes() == 4);
    assert(t.getSeconds() == 29);

    t.up(1);
    std::cout << t << std::endl;

    t.down(60); 
    std::cout << t << std::endl;

    t.down(90000);
    std::cout << t << std::endl;

    return 0;
}