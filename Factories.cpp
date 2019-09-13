#include "Factories.h"
#include <iostream>
#include "Antena.h"

#define RESOURCES_VALUE 20
#define SECONDARY_RESOURCES_VALUE 10
#define CHANNELS_VALUE 10
#define SECONDARY_CHANNELS_VALUE 8

Antena *Nokia::makeAntena(bool choice)
{
	if(choice)
		return new AnalogAntena(RESOURCES_VALUE,true,SECONDARY_RESOURCES_VALUE);
	else
		return new DigitalAntena(CHANNELS_VALUE,SECONDARY_CHANNELS_VALUE);
}