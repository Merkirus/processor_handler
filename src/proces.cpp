#include "proces.hpp"

proces::proces()
{
	waga = randnum(3,7);
	czas = randnum(3,10);
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
