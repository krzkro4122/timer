#include <assert.h>
#include <iostream>
#include "Time.h"

int main()
{
    // Test #1
    std::cout << "Test case #1 in progress..." << std::endl;

    int timestamp = 101069;
    timer::Time t(timestamp);
    std::cout << t << std::endl;

    assert(t.getDays() == 1);
    assert(t.getHours() == 4);
    assert(t.getMinutes() == 4);
    assert(t.getSeconds() == 29);

    t.up(1);
    std::cout << t << std::endl;

    t.up(1203012401203401); 
    std::cout << t << std::endl;

    t.setTime(0, 1, 1, 1);
    std::cout << t << std::endl;

    std::cout << "Test case #1 passed." << std::endl;

    // Test #2
    std::cout << "Test case #2 in progress..." << std::endl;

    timer::Time t1(0, 0, 0, 0);

    t1.down(12314);
    t1.down(0);
    t1.down(1);

    assert(t1.getDays() == 0);
    assert(t1.getHours() == 0);
    assert(t1.getMinutes() == 0);
    assert(t1.getSeconds() == 0);

    std::cout << "Test case #2 passed." << std::endl;

    return 0;
}