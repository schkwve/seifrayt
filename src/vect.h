#ifndef __VECT_H
#define __VECT_H

#include "math.h"

class Vect {
	double x;
	double y;
	double z;

public:
	Vect();
	Vect(double, double, double);

	double getVectX() { return x; }
	double getVectY() { return y; }
	double getVectZ() { return z; }

	double magnitude();
	Vect normalize();
	Vect negative();
	double dot(Vect v);
	Vect cross(Vect v);

	Vect vectAdd(Vect v);
	Vect vectMult(double s);
};

#endif /* __VECT_H */
