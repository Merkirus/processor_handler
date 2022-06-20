#ifndef SEND_ALWAYS_HPP
#define SEND_ALWAYS_HPP

#include "system.hpp"

class send_always
{
public:
	send_always(class system sys);
	void start();
private:
	class system sys;
};

#endif
