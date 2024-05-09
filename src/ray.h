#ifndef __RAY_H
#define __RAY_H

#include "vect.h"

class Ray {
	Vect origin;
	Vect direction;

public:
	Ray();
	Ray(Vect, Vect);

	Vect getRayOrigin() { return origin; }
	Vect getRayDirection() { return direction; }
};

#endif /* __RAY_H */
