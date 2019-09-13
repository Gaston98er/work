#ifndef FACTORIES_H_
#define FACTORIES_H_

#include <iostream>
#include "Antena.h"

class Nokia
{
	public:
		Nokia() = default;
		static Antena *makeAntena(bool choice);
};

// class OtherCompanies
// {

// };

#endif