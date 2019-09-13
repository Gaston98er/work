#ifndef USER_H_
#define USER_H_

#include<iostream>
#include<string.h>

class User
{
    std::string name_;
    long long CNP_;
    std::string country_;
    unsigned int resources_;
    int IPv4_;

public:
    User() = default;
    User(std::string name, long long CNP, std::string country, int IPv4);

    friend std::ostream &operator<<(std::ostream &os, const User &user);

    void showUser();

    unsigned int getResources();

    std::string getName();

    int getIP();

    friend class Pool;

    friend class Antena;
};



#endif