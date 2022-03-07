#include "util.h"
#include <iostream>

int main()
{
    uint64_t tmp = 0;
    uint64_t begin = xuan_web::GetCurrentMS();

    for (int i = 0; i < 655360; i++)
    {
        tmp += xuan_web::GetCurrentMS();
        tmp %= 65536;
    }

    uint64_t end = xuan_web::GetCurrentMS();
    std::cout << end - begin << std::endl;
    return 0;
}
