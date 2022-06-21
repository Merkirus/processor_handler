#include "send_random.hpp"

#define TIME_LIMIT 1000
#define UPPER_THRESHOLD 70
#define LOWER_THRESHOLD 40

send_random::send_random(class system sys) : sys{sys} {}

void send_random::start()
{
	while (sys.getZegar() != TIME_LIMIT) {
		
		sys.generujProcesy();

		/*WYSYLANIE WIADOMOSCI*/
		for (int i = 0; i < sys.getProcesory().size(); ++i) {
            for (int j = 0; j < sys.getProcesory().size() && sys.getProcesory().at(i).getObciazenie() <= LOWER_THRESHOLD; ++j) {
                if (j == i)
                    continue;
                int size = sys.getProcesory().at(j).getProcesy().size();
                for (int k = 0; k < size; ++k) {
                    if (sys.getProcesory().at(i).getObciazenie() > LOWER_THRESHOLD)
                        break;
                    if (sys.getProcesory().at(j).getObciazenie() >= UPPER_THRESHOLD) {
                        sys.wyslijWiadomosc(j, i);
                        sys.przekazProcesy(j);
                        sys.zerujWiadomosci();
                        size = sys.getProcesory().at(j).getProcesy().size();
                        --k;
                    } else {
                        sys.wyslijWiadomosc(i, i);
                        break;
                    }
                }
            }
		}

		sys.tick();
	}

	sys.pokazStatystyki();
}