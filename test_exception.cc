#include "exception.h"
#include <unistd.h>
#include <iostream>

void fn(int count)
{
    if (count <= 0)
    {
        throw xuan_web::Exception("fn 递归结束");
    }
    fn(count - 1);
}

void throw_system_error()
{
    if (write(0xffff, nullptr, 0) == -1)
    {
        throw xuan_web::SystemError("傻逼");
    }

}

int main()
{
    try
    {
        fn(10);
    }
    catch (const xuan_web::Exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << e.stackTrace() << std::endl;
    }

    try
    {
        throw_system_error();
    }
    catch (const xuan_web::SystemError& e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << e.stackTrace() << std::endl;
    }

    return 0;
}
