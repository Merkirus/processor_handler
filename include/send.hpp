#ifndef SEND_HPP
#define SEND_HPP

#include "system.hpp"

class send
{
public:
	send(class system sys);
	void start();
private:
	class system sys;
};

#endif
