#include "system.hpp"

system::system(int n)
: procesory{std::vector<procesor>{}},
wiadomosci{std::vector<std::pair<int,int>>{}},
zegar{0}
{
	int i = 0;
	while (i < n) {
        procesory.push_back(procesor{});
        ++i;
    }
}

bool system::wyslijWiadomosc(int from, int to)
{
	if (from == to) {
		procesory.at(from).wyslijWiadomosc();
		return false;
	}

	procesory.at(from).wyslijWiadomosc();

	if (procesory.at(to).odbierzWiadomosc()) {
		wiadomosci.push_back(std::pair{from,to});
		return true;
	}

	return false;
}

void system::zerujWiadomosci()
{
	wiadomosci.clear();
}

void system::przekazProcesy(int from)
{
	int index = 0;
	for (int i = 0; i < wiadomosci.size(); ++i) {
		if (wiadomosci.at(i).first == from) {
			index = i;
			break;
		}
	}
	procesory.at(wiadomosci.at(index).second).dodajProces(procesory.at(from).getOneAndDestroy());
	procesory.at(wiadomosci.at(index).second).update();
	procesory.at(from).update();
}

void system::tick()
{
	for (int i = 0; i < procesory.size(); ++i) {
		procesory.at(i).updatePlus();
	}
	++zegar;
	for (int i = 0; i < procesory.size(); ++i) {
		procesory.at(i).zmniejszCzas();
	}
	for (int i = 0; i < procesory.size(); ++i) {
		procesory.at(i).usuwanieZer();
	}
	for (int i = 0; i < procesory.size(); ++i) {
		procesory.at(i).update();
	}
}

void system::pokazStatystyki()
{
	std::cout << "Obecne obciążenia: " << '\n';
	int index = 0;
	for (auto procesor : procesory) {
		std::cout << "Numer : " << index << " - " << procesor.getObciazenie() << '\n';
		++index;
	}
	std::cout << "Średnie obciążenia: " << '\n';
	index = 0;
	for (auto procesor : procesory) {
		int sum = 0;
		for (int i : procesor.getHistoriaObciazen()) {
			sum += i;
		}
		int wynik = sum / zegar;
		std::cout << "Numer : " << index << " - " << wynik << '\n';
		++index;
	}
	std::cout << "Migracje: " << '\n';
	index = 0;
	for (auto procesor : procesory) {
		std::cout << "Numer : " << index << " - " << procesor.getMigracje() << '\n';
		++index;
	}
	std::cout << "Zapytania: " << '\n';
	index = 0;
	for (auto procesor : procesory) {
		std::cout << "Numer : " << index << " - " << procesor.getZapytania() << '\n';
		++index;
	}
	std::cout << "Overloadingi: " << '\n';
	index = 0;
	for (auto procesor : procesory) {
		std::cout << "Numer : " << index << " - " << procesor.getOverloading() << '\n';
		++index;
	}
	
}

int system::getZegar()
{
	return zegar;
}

std::vector<procesor> system::getProcesory()
{
	return procesory;
}

void system::generujProcesy()
{
	for (int i = 0; i < procesory.size(); ++i)
		procesory.at(i).generujProcesy();
}
