#include "log.h"
#include "scheduler.h"
#include <iostream>

void fn()
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << "test1" << std::endl;
        xuan_web::Fiber::YieldToHold();
    }
}

void fn2()
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << "test2" << std::endl;
        xuan_web::Fiber::YieldToHold();
    }
}

int main(int, char**)
{
    xuan_web::Scheduler sc(2, true);
    sc.start();

    int i = 0;
    for (i = 0; i < 3; i++)
    {
        sc.schedule([&i]() {
            std::cout << ">>>>>> " << i << std::endl;
        });
    }

    sc.stop();
    return 0;
}
