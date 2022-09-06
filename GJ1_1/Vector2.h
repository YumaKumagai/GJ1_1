#pragma once

class Vector2
{
public:
	float x;
	float y;

	Vector2();
	Vector2(float x, float y);

#pragma region �P�����Z�q�E������Z�q�I�[�o�[���[�h

	Vector2 operator+()const;
	Vector2 operator-()const;

	Vector2& operator+=(const Vector2& v);
	Vector2& operator-=(const Vector2& v);
	Vector2& operator*=(float f);
	Vector2& operator*=(const Vector2& v);
	Vector2& operator/=(float f);
	Vector2& operator/=(const Vector2& v);

#pragma endregion

	// ����
	float Length()const;
	// ���K���x�N�g��
	Vector2 Normalize()const;
	// �p�x(�ʓx�@)
	float Angle()const;

	// ����
	float Dot(const Vector2& v)const;
	float Cross(const Vector2& v)const;

};

#pragma region �񍀉��Z�q�I�[�o�[���[�h

Vector2 operator+(const Vector2& va, const Vector2& vb);
Vector2 operator-(const Vector2& va, const Vector2& vb);
Vector2 operator*(const Vector2& v, float f);
Vector2 operator*(float f, const Vector2& v);
Vector2 operator*(const Vector2& va, const Vector2& vb);
Vector2 operator/(const Vector2& v, float f);
Vector2 operator/(float f, const Vector2& v);
Vector2 operator/(const Vector2& va, const Vector2& vb);

#pragma endregion