#include <vect.h>
#include <camera.h>

Camera::Camera()
{
	campos = Vect(0,0,0);
	camdir = Vect(0,0,1);
	camright = Vect(0,0,0);
	camdown = Vect(0,0,0);
}

Camera::Camera(Vect _campos, Vect _camdir, Vect _camright, Vect _camdown)
{
	campos = _campos;
	camdir = _camdir;
	camright = _camright;
	camdown = _camdown;
}
