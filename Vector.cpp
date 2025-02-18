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

Vector::Vector(Vector&& other) noexcept
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

double Vector::operator*(const Vector& other)
{
	double result = 0;
	for (int i = 0; i < other.n; i++)
	{
		result += other.array[i] * array[i];
	}
	return result;
}

int Vector::operator[](int index)
{
	return array[index];
}

std::ostream& operator<<(std::ostream& os, Vector& other)
{
	os << "(";
	for (int i = 0; i < other.n - 1; i++)
	{
		os << other.array[i] << ", ";
	} 
	os << other.array[other.n - 1] << ")";
	return os;
}

std::istream& operator>>(std::istream& is, Vector& other)
{
	unsigned int n;
	is >> n;
	other.n = n;
	other.array = new int[n];
	for (int i = 0; i < n; i++)
	{
		is >> other.array[i];
	}
	return is;
}
