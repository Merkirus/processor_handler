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
	++zegar;
	for (int i = 0; i < procesory.size(); ++i) {
		for (int j = 0; j < procesory.at(i).getProcesy().size(); ++j) {
			procesory.at(i).getProcesy().at(j).zmniejszCzas();
		}
	}
	for (int i = 0; i < procesory.size(); ++i) {
		auto match = find_if(procesory.at(i).getProcesy().begin(), procesory.at(i).getProcesy().end(), [&](proces& proc) {
			return proc.getCzas() == 0;
		});
		procesory.at(i).getProcesy().erase(match, procesory.at(i).getProcesy().end());
	}
	for (int i = 0; i < procesory.size(); ++i) {
		procesory.at(i).updatePlus();
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
}

int system::getZegar()
{
	return zegar;
}

std::vector<procesor> system::getProcesory()
{
	return procesory;
}
