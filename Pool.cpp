#include <iostream>
#include <functional>
#include "Pool.h"
#include <algorithm>
#include <vector>
#include <list>
#include "Factories.h"


std::string getName(int n){
    switch(n)
    {
        case 0 : return "User0";
                    break;
        case 1 : return "User1";
                    break;
        case 2 : return "User2";
                    break;
        case 3 : return "User3";
                    break;
        case 4 : return "User4";
                    break;
        case 5 : return "User5";
                    break;
        case 6 : return "User6";
                    break;
        case 7 : return "User7";
                    break;
        case 8 : return "User8";
                    break;
        case 9 : return "User9";
                    break;            
    }
}

std::string getCountry(int c){
    switch(c)
    {
        case 0 : return "Romania";
                    break;
        case 1 : return "Franta";
                    break;
        case 2 : return "Germania";
                    break;
        case 3 : return "Austria";
                    break;
        case 4 : return "Ungaria";
                    break;
        case 5 : return "India";
                    break;
        case 6 : return "Norvegia";
                    break;
        case 7 : return "SUA";
                    break;
        case 8 : return "Luxemburg";
                    break;
        case 9 : return "Suedia";
                    break;            
    }
}

long long getCNP(int cnp){
    switch(cnp)
    {
        case 0 : return 1981124350087;
                    break;
        case 1 : return 1981124350078;
                    break;
        case 2 : return 1981124350079;
                    break;
        case 3 : return 2041123456637;
                    break;
        case 4 : return 1962345643579;
                    break;
        case 5 : return 1984563746583;
                    break;
        case 6 : return 1972344536274;
                    break;
        case 7 : return 1664532437685;
                    break;
        case 8 : return 1765436289087;
                    break;
        case 9 : return 1763354287654;
                    break;            
    }
}

bool check13digits(long long number)
{
    unsigned int number_of_digits;
    if (number > 0)
    {
        for (number_of_digits = 0; number > 0; number_of_digits++)
            number /= 10;
    }

    if (number_of_digits == 13)
        return true;
    return false;
}

void Pool::generateUsers(unsigned int numberOfUsers)
{
    int info = 0;
    
    std::string name, country;
    long long CNP;
    User user;
    unsigned int i;

    for (i = 0; i < numberOfUsers; i++)
    {
        name = getName(info);
        country = getCountry(info);
        CNP = getCNP(info);

        info++;

        auto IP = generator_->getAdress();


        if (IP != 0 && check13digits(CNP) && antena->getStatus())
        {
            user = User(name, CNP, country, IP);
            users_.push_back(user);
            antena->addUser(user);
        }

        else
            {
                std ::cout << "The user could not be created. Please verify the list of parameters";
                break;
            }
    }
}



void Pool::removeUsers(int IPv4)
{
   std::vector<User>::iterator p;

    for(p = users_.begin() ; p != users_.end() ; p++)
        if(p->getIP() == IPv4)
            users_.erase(p);

    antena->removeUser(IPv4);
}

void Pool::showUsersFromCountry(const std::string &country)
{
    std::vector<User>::iterator p;
    for (p = users_.begin(); p != users_.end(); p++)
    {
        if (p->country_ == country)
            p->showUser();
    }
}

std::vector<User> Pool::getUsers()
{
    return users_;
}

void Pool::sortUsersByName()
{
    std::sort(users_.begin(), users_.end(), [](const User &x, const User &y){
        return x.name_ > y.name_;
    });
}

void Pool ::sortUsersByNetworkUsage()
{
    std::sort(users_.begin(), users_.end(),[](const User &x, const User &y){
        return x.resources_ > y.resources_;
    });
}

float Pool::averageUsagePerCountry(const std::string &country)
{
    unsigned int sum = 0, counter = 0;
    float average;
    std::vector<User>::iterator p;
    for (p = users_.begin(); p != users_.end(); p++)
        if (p->country_ == country)
        {
            sum += p->resources_;
            counter++;
        }

    average = (float)sum / counter;

    return average;
}

float Pool::averageUsage()
{
    unsigned int sum = 0;
    float average;
    std::vector<User>::iterator p;
    for (p = users_.begin(); p != users_.end(); p++)
        sum += p->resources_;

    average = (float)sum / users_.size();

    return average;
}

std::list<User> Pool::getListOfUsers(unsigned int numberOfUsers)
{
    std::vector<User>::iterator p;
    std::list<User> usersList(numberOfUsers);
    if (numberOfUsers <= users_.size())
        std::copy_n(users_.begin(), numberOfUsers, usersList.begin());

    return usersList;
}

void Pool::addAnalogAntena(){
    antena = factory.makeAntena(true);
}

void Pool::addDigitalAntena(){
    antena = factory.makeAntena(false);
}

void Pool::showUsersFromAntena()
{
    antena->showUsers();
}