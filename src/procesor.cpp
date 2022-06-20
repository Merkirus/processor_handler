#include "procesor.hpp"

#define UPPER_THRESHOLD 70

procesor::procesor()
{
	procesy = std::vector<proces>();
	obciazenie = 0;
	historia_obciazen = std::vector<int>();
	overloading = 0;
	overloaded = false;
	migracje = 0;; 
	zapytania = 0;
}

void procesor::wyslijWiadomosc()
{
	++zapytania;
}

bool procesor::odbierzWiadomosc()
{
	++migracje;
	return true;
}

void procesor::generujProcesy()
{
	if (randnum(1,3) == 1)
		return;

	int how_many = randnum(1,4);
	for (;how_many-- > 0;)
		procesy.push_back(proces());
}

std::vector<proces> procesor::getProcesy()
{
	return procesy;
}

proces procesor::getOneAndDestroy()
{
	proces result = procesy.at(0);
	procesy.erase(procesy.begin());
	return result;
}


void procesor::dodajProces(proces proces)
{
	procesy.push_back(proces);
}

void procesor::update()
{
	historia_obciazen.push_back(obciazenie);
	obciazenie = 0;
	for (int i = 0; i < procesy.size(); ++i) {
		obciazenie += procesy.at(i).getWaga();
	}
}

void procesor::updatePlus()
{
	historia_obciazen.push_back(obciazenie);
	obciazenie = 0;
	for (int i = 0; i < procesy.size(); ++i) {
		obciazenie += procesy.at(i).getWaga();
	}
	if (obciazenie >= 100) {
		++overloading;
		overloaded = true;
	}
}

int procesor::getObciazenie()
{
	return obciazenie;
}
