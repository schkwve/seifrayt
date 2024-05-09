#ifndef __LIGHT_H
#define __LIGHT_H

#include "vect.h"
#include "color.h"

class Light {
	Vect position;
	Color color;

public:
	Light();
	Light(Vect, Color);

	Vect getLightPosition() { return position; }
	Color getLightColor() { return color; }
};

#endif /* __LIGHT_H */
