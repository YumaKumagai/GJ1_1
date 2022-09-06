#include "GraphDeta.h"
#include "DxLib.h"

Vector2 GraphDeta::GetGraphSize()const
{
	int xBuf, yBuf;
	DxLib::GetGraphSize(grHandle, &xBuf, &yBuf);
	return Vector2((float)xBuf, (float)yBuf);
}