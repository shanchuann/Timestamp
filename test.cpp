#include "Timestamp.hpp"
#include <iostream>

int main()
{
    logsys::Timestamp test;
    test = logsys::Timestamp::Now();
    std::cout << test.toFormattedString() << std::endl;
    std::cout << test.toFileString() << std::endl;
}