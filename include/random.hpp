#ifndef RANDOM_HPP
#define RANDOM_HPP

#define randnum(min, max) \
	((rand() % (int)(((max) + 1) - (min))) + (min))

#endif
