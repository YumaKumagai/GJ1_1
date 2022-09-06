#pragma once
#include "Vector2.h"

class GraphDeta
{
public:
	Vector2 pos;
	Vector2 extRate;
	double angle;
	int grHandle;
	int blendMode;
	int blendPal;
	unsigned bright;

	Vector2 GetGraphSize()const;

};

