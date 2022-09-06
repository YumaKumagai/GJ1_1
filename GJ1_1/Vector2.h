#pragma once

class Vector2
{
public:
	float x;
	float y;

	Vector2();
	Vector2(float x, float y);

#pragma region 単項演算子・代入演算子オーバーロード

	Vector2 operator+()const;
	Vector2 operator-()const;

	Vector2& operator+=(const Vector2& v);
	Vector2& operator-=(const Vector2& v);
	Vector2& operator*=(float f);
	Vector2& operator*=(const Vector2& v);
	Vector2& operator/=(float f);
	Vector2& operator/=(const Vector2& v);

#pragma endregion

	// 長さ
	float Length()const;
	// 正規化ベクトル
	Vector2 Normalize()const;
	// 角度(弧度法)
	float Angle()const;

	// 内積
	float Dot(const Vector2& v)const;
	float Cross(const Vector2& v)const;

};

#pragma region 二項演算子オーバーロード

Vector2 operator+(const Vector2& va, const Vector2& vb);
Vector2 operator-(const Vector2& va, const Vector2& vb);
Vector2 operator*(const Vector2& v, float f);
Vector2 operator*(float f, const Vector2& v);
Vector2 operator*(const Vector2& va, const Vector2& vb);
Vector2 operator/(const Vector2& v, float f);
Vector2 operator/(float f, const Vector2& v);
Vector2 operator/(const Vector2& va, const Vector2& vb);

#pragma endregion