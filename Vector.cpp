#include "Vector.hpp"

Vector::Vector()
{
	n = 0;
	array = nullptr;
}

Vector::Vector(const Vector& other)
{
	n = other.n;
	array = new int[n];
	for (int i = 0; i < n; i++)
	{
		array[i] = other.array[i];
	}
}

Vector::Vector(Vector&& other)
{
	n = other.n;
	array = other.array;
	other.array = nullptr;
	other.n = 0;
}

Vector::~Vector()
{
	delete[] array;
}