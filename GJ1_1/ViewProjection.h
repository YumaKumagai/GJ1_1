#pragma once
#include "GraphDeta.h"

class ViewProjection
{
public:
	Vector2 pos;
	Vector2 upl;
	Vector2 lor;

	ViewProjection(const Vector2& pos, const Vector2& upl, const Vector2& lor);
	void DrawGraph(const GraphDeta& graph);

};

