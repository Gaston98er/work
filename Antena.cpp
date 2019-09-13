#include <iostream>
#include "Antena.h"
#include "User.h"
#include <stdlib.h>
#include <algorithm>
#include <list>

#define RESOURCES_VALUE 20
#define SECONDARY_RESOURCES_VALUE 10
#define CHANNELS_VALUE 10
#define SECONDARY_CHANNELS_VALUE 8

void Antena::addUser(User us)
{
    updateStatus(us);
    
    if(status_ == true)
        this->userList_.push_back(us); 
}

void Antena::showUsers()
{
    std::list<User>::iterator p;
    for(p = userList_.begin() ; p != userList_.end() ; p++)
    {
        p->showUser();
        std::cout << "\n";
    }
    
}

bool Antena::getStatus(){
    return status_;
}

void AnalogAntena::removeUser(int IPv4){
	std::list<User>::iterator p;

    for(p = userList_.begin() ; p != userList_.end() ; p++)
        if(p->getIP() == IPv4)
        {
            if(secondaryResources_ < SECONDARY_RESOURCES_VALUE)
                secondaryResources_ += p->getResources();

            else
                this->resources_ += p->getResources();

            userList_.erase(p);

            std::cout << "\nUser DELETED\n";

            if(secondaryResources_ > 0 && status_ == false)
            {
                status_ = true;
                std::cout << "AnalogAntena ENABLED" << "\n";
            }  
                
            break;
        }
}

void AnalogAntena::showUsers()
{
    std::cout << "\n------------------ANALOG ANTENA USERS-------------------\n";

    Antena::showUsers();
}

Antena::Antena(){
    this->IP_ = rand() % 1000 + 1000;
    this->status_ = true; 
}

void AnalogAntena::updateStatus(User us)
{

    if(resources_ >= us.getResources())
        resources_ -= us.getResources();

    else if(resources_ < us.getResources() && secondaryResources_ >= us.getResources())
    {
        std::cout << "\nSecondary resources have been accessed\n";
        secondaryResources_ -= us.getResources();
    }

    else
    {
        status_ = false;
        std::cout << "AnalogAntena DISABLED" << "\n";
    }
}


void DigitalAntena::removeUser(int IPv4){
    std::list<User>::iterator p;

    for(p = userList_.begin() ; p != userList_.end() ; p++)
    {
        if(p->getIP() == IPv4)
        {
            userList_.erase(p);
            channels_ += 2;
            break;
        }
    }

    if(channels_ > 0 && status_ == false)
    {
        status_ = true;
        std::cout << "DigitalAntena ENABLED" << "\n";
    }
}

void DigitalAntena::showUsers()
{
    std::cout << "\n-------------------DIGITAL ANTENA USERS-------------------\n";

    Antena::showUsers();
}


void DigitalAntena::updateStatus(User us)
{
    if(channels_ > 0)
        channels_ -= 2;

    else 
    {
        status_ = false;
        std::cout << "DigitalAntena DISABLED" << "\n";
    }
}