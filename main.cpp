#include <time.h>
#include <random>
#include "send.hpp"
#include "send_random.hpp"
#include "send_always.hpp"
#include "system.hpp"

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	class system sys{5};
	send send{sys};
	send_always send_always{sys};
	send_random send_random{sys};

	send_always.start();

	return 0;
}