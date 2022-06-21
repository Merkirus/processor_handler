#include <time.h>
#include <random>
#include <iostream>
#include "send.hpp"
#include "send_random.hpp"
#include "send_always.hpp"
#include "system.hpp"

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	class system sys{10};
	send send{sys};
	send_always send_always{sys};
	send_random send_random{sys};

	std::cout << "--SEND_ALWAYS--" << '\n';
	send_always.start();
	std::cout << "--SEND--" << '\n';
	send.start();
	std::cout << "--SEND_RANDOM--" << '\n';
	send_random.start();
	return 0;
}