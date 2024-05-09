#ifndef __COLOR_H
#define __COLOR_H

class Color {
	double r;
	double g;
	double b;
	double s;

public:
	Color();
	Color(double, double, double, double);

	double getColorRed() { return r; }
	double getColorGreen() { return g; }
	double getColorBlue() { return b; }
	double getColorSpecial() { return s; }

	void setColorRed(double _r) { r = _r; }
	void setColorGreen(double _g) { g = _g; }
	void setColorBlue(double _b) { b = _b; }
	void setColorSpecial(double _s) { s = _s; }
};

#endif /* __COLOR_H */
