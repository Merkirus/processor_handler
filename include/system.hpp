#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include "procesor.hpp"

class system
{
public:
	system(int n);
	bool wyslijWiadomosc(int from, int to);
	void zerujWiadomosci();
	void przekazProcesy(int from);
	void tick();
	void pokazStatystyki();
	int getZegar();
	std::vector<procesor> getProcesory();
	void generujProcesy();
private:
	std::vector<procesor> procesory;
	std::vector< std::pair<int,int> > wiadomosci;
	int zegar;
};

#endif
