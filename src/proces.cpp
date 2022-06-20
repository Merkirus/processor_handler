#include "proces.hpp"

proces::proces()
{
	waga = randnum(3,10);
	czas = randnum(5,15);
}

void proces::zmniejszCzas()
{
	--czas;
}

int proces::getWaga()
{
	return waga;
}

int proces::getCzas()
{
	return czas;
}
