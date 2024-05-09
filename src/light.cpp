#include <vect.h>
#include <light.h>

Light::Light()
{
	position = Vect(0,0,0);
	color = Color(1,1,1,0);
}

Light::Light(Vect _position, Color _color)
{
	position = _position;
	color = _color;
}
