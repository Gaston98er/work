#ifndef GENERATOR_H_
#define GENERATOR_H_ 

#include<vector>

class IPGenerator
{
    std::vector<int> IPv4_{176, 186, 196, 106, 126, 116};

    static IPGenerator *generator;
    IPGenerator() = default;

public:
    static IPGenerator *createGenerator();

    int getAdress();
};

#endif