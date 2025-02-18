#include "Vector.hpp"

Vector::Vector()
{
	this->n = 0;
	this->array = nullptr;
}

Vector::Vector(unsigned int n, const int* array)
{
	this->n = n;
	this->array = new int[n];
	for (int i = 0; i < n; i++)
	{
		this->array[i] = array[i];
	}
}

Vector::Vector(const Vector& other)
{
	this->n = other.n;
	this->array = new int[this->n];
	for (int i = 0; i < this->n; i++)
	{
		this->array[i] = other.array[i];
	}
}

Vector::Vector(Vector&& other) noexcept
{
	this->array = other.array;
	this->n = other.n;
	other.array = nullptr;
	other.n = 0;
}

Vector& Vector::operator=(const Vector& other)
{
	if (this == &other) return *this;
	delete[] this->array;
	this->n = other.n;
	this->array = new int[this->n];
	for (int i = 0; i < this->n; i++)
	{
		this->array[i] = other.array[i];
	}
	return *this;
}

Vector& Vector::operator=(Vector&& other) noexcept
{
	if (this == &other) return *this;
	delete[] this->array;
	this->array = other.array;
	this->n = other.n;
	other.array = nullptr;
	other.n = 0;
	return *this;
}

int& Vector::operator[](unsigned int index)
{
	return array[index];
}

std::ostream& operator<<(std::ostream& os, const Vector& vec)
{
	os << "(";
	for (int i = 0; i < vec.n - 1; i++)
	{
		os << vec.array[i] << ", ";
	}
	os << vec.array[vec.n - 1] << ")";
	return os;
}

std::istream& operator>>(std::istream& is, Vector& vec)
{
	is >> vec.n;
	delete[] vec.array;
	vec.array = new int[vec.n];
	for (int i = 0; i < vec.n; i++)
	{
		is >> vec.array[i];
	}
	return is;
}