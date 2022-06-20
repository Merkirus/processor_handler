#ifndef PROCESOR_HPP
#define PROCESOR_HPP

#include <vector>
#include "proces.hpp"
#include "random.hpp"

class procesor
{
public:
	procesor();
	void wyslijWiadomosc();
	bool odbierzWiadomosc();
	void generujProcesy();
	void dodajProces(proces proces);
	std::vector<proces> getProcesy();
	proces getOneAndDestroy();
	void update();
	void updatePlus();
	/* DO STATYSTYK */
	std::vector<int> getHistoriaObciazen();
	int getObciazenie();
	int getOverloading();
	bool isOverloaded();
	int getMigracje();
	int getZapytania();
private:
	std::vector<proces> procesy;
	int obciazenie;
	std::vector<int> historia_obciazen;
	int overloading;
	bool overloaded;
	int migracje;
	int zapytania;
};

#endif
