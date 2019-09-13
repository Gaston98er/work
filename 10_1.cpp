#include <iostream>
#include <memory>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <functional>
#include <algorithm>
#include <list>
#include <array>
#include "User.h"
#include "Pool.h"


int main()
{
    Pool network;
    unsigned int opt, numberOfUsersCreate, numberOfUsersDelete, nrUsLst;
    std::vector<User>::iterator p;
    std::list<User>::iterator j;
    std::vector<User> users;
    std::list<User> usersList;
    std::string country, country1;
    int IPv4;

    do
    {
        std::cout << "\n1)Generate X users and add them to the pool";
        std::cout << "\n2)Remove X users from the pool";
        std::cout << "\n3)Print all the users from a certain country";
        std::cout << "\n4)Print all users";
        std::cout << "\n5)Sort users by name";
        std::cout << "\n6)Sort users by network usage";
        std::cout << "\n7)Computes the average network usage for each country";
        std::cout << "\n8)Computes the average network usage for all users";
        std::cout << "\n9)Return a list with a certain number of users in it";
        std::cout << "\n10)Add analog antena";
        std::cout << "\n11)Add digital antena";
        std::cout << "\n12)EXIT";
        std::cout << "\nChose an option : ";
        std::cin >> opt;
        switch (opt)
        {
        case 1:
            std::cout << "\nInput a number of users you want to create : ";
            std::cin >> numberOfUsersCreate;
            network.generateUsers(numberOfUsersCreate);
            break;
        case 2:
            std::cout << "\nInput a number of users you want to delete : ";
            std::cin >> numberOfUsersDelete;
            while(numberOfUsersDelete <= numberOfUsersCreate && numberOfUsersDelete != 0)
            {
                std::cout << "\nInput the IPv4 to find and delete the user : ";
                std::cin >> IPv4;
                network.removeUsers(IPv4);
                numberOfUsersDelete--;
            }
            
            break;
        case 3:
            std::cout << "\nInput country to show users : ";
            std::cin >> country;
            network.showUsersFromCountry(country);
            break;
        case 4:
            users = network.getUsers();

            for (p = users.begin(); p != users.end(); p++)
                p->showUser();

            network.showUsersFromAntena();
            break;
        case 5:
            network.sortUsersByName();
            break;
        case 6:
            network.sortUsersByNetworkUsage();
            break;
        case 7:
            std::cout << "\nInput country to show average : ";
            std::cin >> country1;
            std::cout << "\nThe average usage in " << country << " is" << network.averageUsagePerCountry(country1) << "\n";
            break;
        case 8:
            std::cout << "\nThe average usage of all users is " << network.averageUsage();
            break;
        case 9:
            std::cout << "\nHow many users do you want to put in the list ? : ";
            std::cin >> nrUsLst;
            usersList = network.getListOfUsers(nrUsLst);
            for (j = usersList.begin(); j != usersList.end(); j++)
                j->showUser();
            break;
        case 10:
            network.addAnalogAntena();
            break;
        case 11:
            network.addDigitalAntena();
            break;

        }

    } while (opt <= 11);

    return 0;
}