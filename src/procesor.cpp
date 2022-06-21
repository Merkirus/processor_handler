#include "procesor.hpp"

#define OVERLOAD_THRESHOLD 70

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
	if (randnum(1,6) == 1 || overloaded)
		return;

	int how_many = randnum(2,6);
	for (;how_many-- > 0;)
		procesy.push_back(proces());
	update();
}

std::vector<proces> procesor::getProcesy()
{
	return procesy;
}

proces procesor::getOneAndDestroy()
{
	proces result = procesy.at(0);
	procesy.erase(procesy.begin());
	update();
	return result;
}


void procesor::dodajProces(proces proces)
{
	procesy.push_back(proces);
	update();
}

void procesor::update()
{
	obciazenie = 0;
	for (int i = 0; i < procesy.size(); ++i) {
		obciazenie += procesy.at(i).getWaga();
	}
	if (obciazenie <= OVERLOAD_THRESHOLD)
		overloaded = false;
}

void procesor::updatePlus()
{
	historia_obciazen.push_back(obciazenie);
	obciazenie = 0;
	for (int i = 0; i < procesy.size(); ++i) {
		obciazenie += procesy.at(i).getWaga();
	}
	if (obciazenie <= OVERLOAD_THRESHOLD)
		overloaded = false;
	if (obciazenie >= 100) {
		++overloading;
		overloaded = true;
	}
}

int procesor::getObciazenie()
{
	return obciazenie;
}

std::vector<int> procesor::getHistoriaObciazen()
{
	return historia_obciazen;
}

int procesor::getMigracje()
{
	return migracje;
}

int procesor::getZapytania()
{
	return zapytania;
}

void procesor::usuwanieZer()
{
	auto match = find_if(procesy.begin(), procesy.end(), [&](proces& proc) {
			return proc.getCzas() == 0;
		});
	procesy.erase(match, procesy.end());
}

void procesor::zmniejszCzas()
{
	for (int i = 0; i < procesy.size(); ++i)
		procesy.at(i).zmniejszCzas();
}

int procesor::getOverloading()
{
	return overloading;
}
