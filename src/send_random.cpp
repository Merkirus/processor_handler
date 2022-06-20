#include "send_random.hpp"

#define TIME_LIMIT 1000
#define UPPER_THRESHOLD 70
#define LOWER_THRESHOLD 20

send_random::send_random(class system sys) : sys{sys} {}

void send_random::start()
{
	while (sys.getZegar() != TIME_LIMIT) {
		/*GENEROWANIE*/
		for (int i = 0; i < sys.getProcesory().size(); ++i)
			sys.getProcesory().at(i).generujProcesy();

		/*WYSYLANIE WIADOMOSCI*/
		for (int i = 0; i < sys.getProcesory().size(); ++i) {
			int size = sys.getProcesory().at(i).getProcesy().size();
			for (int k = 0; k < size; ++k) {
				for (int j = 0; j < sys.getProcesory().size() && sys.getProcesory().at(i).getObciazenie() <= LOWER_THRESHOLD; ++j) {
					if (j != i) {
						if (sys.getProcesory().at(j).getObciazenie() >= UPPER_THRESHOLD) {
								sys.wyslijWiadomosc(j, i);
								sys.przekazProcesy(j);
								break;
						} else {
							sys.wyslijWiadomosc(i, i);
						}
					}
				}
			}
		}

		sys.zerujWiadomosci();

		sys.tick();
	}
}