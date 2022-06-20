#ifndef PROCES_HPP
#define PROCES_HPP

#include "random.hpp"

class proces
{
public:
	proces();
	int getWaga();
	int getCzas();
	void zmniejszCzas();
private:
	int waga;
	int czas;
};

#endif
