#pragma once
#include <stdlib.h>
class Traffic_light
{
private:
	float size;
	float position_x;
	float position_y;
	int red_time;
	int yellow_time;
	int green_time;
	int state;
	int count;
public:
	void initialize();
	void setsize(float a);
	void set_position(float x, float y);
	void set_time(int red, int yellow, int green);
	void show(CDC* pDC);
	void counter(CDC* pDC);
};


