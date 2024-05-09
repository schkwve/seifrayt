#ifndef __CAMERA_H
#define __CAMERA_H

#include "vect.h"

class Camera {
	Vect campos;
	Vect camdir;
	Vect camright;
	Vect camdown;

public:
	Camera();
	Camera(Vect, Vect, Vect, Vect);

	Vect getCameraPosition() { return campos; }
	Vect getCameraDirection() { return camdir; }
	Vect getCameraRight() { return camright; }
	Vect getCameraDown() { return camdown; }
};

#endif /* __CAMERA_H */
