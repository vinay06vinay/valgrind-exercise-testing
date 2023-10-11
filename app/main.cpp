#include <iostream>
#include <AnalogSensor.hpp>

int main()
{
    AnalogSensor lightSensor(5);
    std::cout << "Averaged sensor reading: " << lightSensor.Read() << std::endl;

    //There is no terminator variable assigned. Hence it is causing unintialization variable error in valgrind. So, it is commented.


    // bool terminator;
    // if( terminator )
    // {
    //     std::cout << "DONE" << std::endl;
    // }
    // return 0;
}
