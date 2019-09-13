#include "User.h"

User::User(std::string name, long long CNP, std::string country, int IPv4) : IPv4_(IPv4), CNP_(CNP), country_(country), name_(name)
{
    resources_ = rand() % 10 + 1;
}

void User::showUser() { std::cout << *(this); }

std::ostream &operator<<(std::ostream &os, const User &user)
{
    os << user.name_ << "\t" << user.CNP_ << "\t" << user.country_ << "\t" << user.resources_ << "\t" << user.IPv4_ << "\n";
    return os;
}

unsigned int User::getResources()
{
    return this->resources_;
}

std::string User::getName()
{
	return this->name_;
}

int User::getIP(){
	return this->IPv4_;
}