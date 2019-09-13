#ifndef POOL_H_
#define POOL_H_

#include <iostream>
#include <vector>
#include "User.h"
#include "IPGenerator.h"
#include "Antena.h"
#include <list>
#include "Factories.h"

class Pool
{
    std::vector<User> users_;
    IPGenerator *generator_;
    Antena *antena;
    Nokia factory;

public:
    Pool()
    {
        generator_ = IPGenerator::createGenerator();
        factory = Nokia();
    }

    void generateUsers(unsigned int numberOfUsers);

    void removeUsers(int IPv4);

    void showUsersFromCountry(const std::string &country);

    std::vector<User> getUsers();

    void sortUsersByName();

    void sortUsersByNetworkUsage();

    float averageUsagePerCountry(const std::string &country);

    float averageUsage();

    std::list<User> getListOfUsers(unsigned int numberOfUsers);

    void addAnalogAntena();

    void addDigitalAntena();

    void showUsersFromAntena();

};

#endif