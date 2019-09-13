#ifndef ANTENA_H_
#define ANTENA_H_

#include<iostream>
#include<list>
#include "User.h"

class Antena
{
protected:
    int IP_;
    bool status_; //true -> ENABLED ; false -> DISABLED
    std::list<User> userList_;

public:
    Antena();

    void addUser(User us);

    virtual void removeUser(int IPv4) = 0;

    virtual void updateStatus(User us) = 0;

    bool getStatus();

    virtual void showUsers();

};

class AnalogAntena : public Antena
{
    int resources_;
    bool transmissionDir_; //true -> TX ; false -> RX
    int secondaryResources_;

public:
    AnalogAntena(int resources, bool transmissionDir, int secondaryResources) : Antena(){
        resources_ = resources;
        transmissionDir_ = transmissionDir;
        secondaryResources_ = secondaryResources;
    }

    void removeUser(int IPv4);

    void updateStatus(User us);

    void showUsers();
};

class DigitalAntena : public Antena
{
    int channels_;
    int secondaryChannels_;

public:
    DigitalAntena(int channels , int secondaryChannels):Antena()
    {
        channels_ = channels;
        secondaryChannels_ = secondaryChannels;
    }

    void removeUser(int IPv4);

    void updateStatus(User us);

    void showUsers();
};

#endif