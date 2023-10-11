#include <AnalogSensor.hpp>
#include <numeric>
#include <vector>

AnalogSensor::AnalogSensor(unsigned int samples)
    : mSamples(samples)
{
}

AnalogSensor::~AnalogSensor()
{
}

int AnalogSensor::Read()
{
    // As the vector is allocated on heap it needs to be deleted to prevent memory leak. So, instead we 
    // change the vector to stor on stack
    std::vector<int> readings(mSamples, 10);
    
    double sum = 0;
    for (int n:readings){
        sum += n;
    }
    double result = sum / readings.size();
    return result;
}


