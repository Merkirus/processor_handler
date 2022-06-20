#include "send.hpp"

#define TIME_LIMIT 1000
#define UPPER_THRESHOLD 70

send::send(class system sys) : sys{sys} {}

void send::start()
{
	while (sys.getZegar() != TIME_LIMIT) {
		/*GENEROWANIE*/
		for (int i = 0; i < sys.getProcesory().size(); ++i)
			sys.getProcesory().at(i).generujProcesy();

		/*WYSYLANIE WIADOMOSCI*/
		for (int i = 0; i < sys.getProcesory().size(); ++i) {
			int size = sys.getProcesory().at(i).getProcesy().size();
			for (int k = 0; k < size; ++k) {
				if (sys.getProcesory().at(i).getObciazenie() >= UPPER_THRESHOLD) {
					for (int j = 0; j < sys.getProcesory().size(); ++j) {
						if (j != i) {
							if (sys.getProcesory().at(j).getObciazenie() < UPPER_THRESHOLD) {
								sys.wyslijWiadomosc(i, j);
								sys.przekazProcesy(i);
								break;
							} else {
								sys.wyslijWiadomosc(i, i);
							}
						}
					}
				}
			}
		}

		sys.zerujWiadomosci();

		sys.tick();
	}
}