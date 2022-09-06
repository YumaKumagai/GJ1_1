#include "Vector2.h"
#define _USE_MATH_DEFINES
#include <math.h>

Vector2::Vector2()
	:x(0.f), y(0.f)
{
}

Vector2::Vector2(float x, float y)
	:x(x), y(y)
{
}

#pragma region 単項演算子・代入演算子オーバーロード

Vector2 Vector2::operator+()const
{
	return *this;
}

Vector2 Vector2::operator-()const
{
	return { -x,-y };
}

Vector2& Vector2::operator+=(const Vector2& v)
{
	return *this += v;
}

Vector2& Vector2::operator-=(const Vector2& v)
{
	return *this += -v;
}

Vector2& Vector2::operator*=(float f)
{
	*this = *this * f;
	return *this;
}

Vector2& Vector2::operator*=(const Vector2& v)
{
	*this = *this * v;
	return *this;
}

Vector2& Vector2::operator/=(float f)
{
	*this = *this / f;
	return *this;
}

Vector2& Vector2::operator/=(const Vector2& v)
{
	*this = *this / v;
	return *this;
}

#pragma endregion

float Vector2::Length() const
{
	return sqrtf(powf(x, 2) + powf(y, 2));
}

Vector2 Vector2::Normalize() const
{
	return *this / Length();
}

float Vector2::Angle() const
{
	float angle;
	float sin = y / Length();
	float arcsin = asinf(sin);

	if (x >= 0)
	{
		angle = arcsin;
	}
	else
	{
		if (arcsin >= 0)
		{
			angle = M_PI - arcsin;
		}
		else
		{
			angle = -M_PI - arcsin;
		}
	}

	return angle;
}

float Vector2::Dot(const Vector2& v) const
{
	return x * v.x + y * v.y;
}

float Vector2::Cross(const Vector2& v) const
{
	return x * v.y - y * v.x;
}

#pragma region 二項演算子オーバーロード

Vector2 operator+(const Vector2& va, const Vector2& vb)
{
	return { va.x + vb.x,va.y + vb.y };
}

Vector2 operator-(const Vector2& va, const Vector2& vb)
{
	return va + (-vb);
}

Vector2 operator*(const Vector2& v, float f)
{
	return { v.x * f,v.y * f };
}

Vector2 operator*(float f, const Vector2& v)
{
	return v * f;
}

Vector2 operator*(const Vector2& va, const Vector2& vb)
{
	return { va.x * vb.x,va.y * vb.y };
}

Vector2 operator/(const Vector2& v, float f)
{
	return { v.x / f,v.y / f };
}

Vector2 operator/(float f, const Vector2& v)
{
	return { f / v.x,f / v.y };
}

Vector2 operator/(const Vector2& va, const Vector2& vb)
{
	return { va.x / vb.x,va.y / vb.y };
}

#pragma endregion