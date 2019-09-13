#include "IPGenerator.h"

IPGenerator *IPGenerator::generator = 0;

IPGenerator* IPGenerator::createGenerator()
{
    if (generator == 0)
        generator = new IPGenerator();
    return generator;
}

int IPGenerator ::getAdress()
{
    int adress = 0, i;
    if (IPv4_.size() != 0)
    {
        adress = IPv4_[0];
        IPv4_.erase(IPv4_.begin() + 0);
    }

    return adress;
}