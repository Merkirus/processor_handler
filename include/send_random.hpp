#ifndef SEND_RANDOM_HPP
#define SEND_RANDOM_HPP

#include "system.hpp"

class send_random
{
public:
	send_random(class system sys);
	void start();
private:
	class system sys;
};

#endif
