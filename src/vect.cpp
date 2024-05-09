#include <vect.h>

Vect::Vect()
{
	x = 0;
	y = 0;
	z = 0;
}

Vect::Vect(double _x, double _y, double _z)
{
	x = _x;
	y = _y;
	z = _z;
}

double Vect::magnitude()
{
	return sqrt((x*x)+(y*y)+(z*z));
}

Vect Vect::normalize()
{
	double m = magnitude();
	return Vect(x/m,y/m,z/m);
}

Vect Vect::negative()
{
	return Vect(-x,-y,-z);
}

double Vect::dot(Vect v)
{
	return x*v.getVectX() + y*v.getVectY() + y*v.getVectZ();
}

Vect Vect::cross(Vect v)
{
	return Vect(y*v.getVectZ() - z*v.getVectY(), z*v.getVectX() - x*v.getVectZ(), x*v.getVectY() - y*v.getVectX());
}

Vect Vect::vectAdd(Vect v)
{
	return Vect(x + v.getVectX(), y + v.getVectY(), z + v.getVectZ());
}

Vect Vect::vectMult(double s)
{
	return Vect(x*s, y*s, z*s);
}
