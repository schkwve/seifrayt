#include <vect.h>
#include <ray.h>

Ray::Ray()
{
	origin = Vect(0,0,0);
	direction = Vect(1,0,0);
}

Ray::Ray(Vect _origin, Vect _direction)
{
	origin = _origin;
	direction = _direction;
}
