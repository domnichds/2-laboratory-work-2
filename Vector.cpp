#include "Vector.hpp"
#include <iostream>

Vector::Vector()
{
	this->n = 0;
	this->array = nullptr;
	std::cout << "Default constructor called!" << std::endl;
}

Vector::Vector(unsigned int n, const int* array)
{
	this->n = n;
	this->array = new int[n];
	for (int i = 0; i < n; i++)
	{
		this->array[i] = array[i];
	}
	std::cout << "Parameterized constructor called" << std::endl;
}

Vector::Vector(const Vector& other)
{
	this->n = other.n;
	this->array = new int[this->n];
	for (int i = 0; i < this->n; i++)
	{
		this->array[i] = other.array[i];
	}
	std::cout << "Copy constructor called" << std::endl;

}

Vector::Vector(Vector&& other) noexcept
{
	this->array = other.array;
	this->n = other.n;
	other.array = nullptr;
	other.n = 0;
	std::cout << "Move constructor called" << std::endl;
}

Vector::~Vector()
{
	delete[] this->array;
	std::cout << "Destructor called" << std::endl;
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
	std::cout << "Copy assignment operator called" << std::endl;
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
	std::cout << "Move assignment operator called" << std::endl;
	return *this;
}

int& Vector::operator[](unsigned int index)
{
	std::cout << "[] operator called" << std::endl;
	return array[index];
}

double Vector::operator*(const Vector& other)
{
	if (this->n != other.n) return 0.0;
	double result = 0.0;
	for (int i = 0; i < other.n; i++)
	{
		result += this->array[i] * other.array[i];
	}
	std::cout << "* operator called" << std::endl;
	return result;
}

std::ostream& operator<<(std::ostream& os, const Vector& vec)
{
	if (vec.n == 0 || vec.array == nullptr)
	{
		os << "()";
		return os;
	}
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