#ifndef adl_color_h__
#define adl_color_h__

#include "engine/adl_math/adlMath.h"

class adlColor
{
public:
	adlColor();
	adlColor(float r, float g, float b);
	~adlColor();

	adlVec3 to_vec3();

	static const adlColor WHITE;
	static const adlColor RED;
	static const adlColor GREEN;
	static const adlColor BLUE;
	static const adlColor MAGENTA;
	static const adlColor CYAN;
	static const adlColor YELLOW;

private:
	float r_;
	float g_;
	float b_;
};

#endif // adl_color_h__