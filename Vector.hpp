#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <fstream>

class Vector
{
private:
	unsigned int n;
	int* array;
public:
	Vector();
	Vector(unsigned int, const int*);
	Vector(const Vector&);
	Vector(Vector&&) noexcept;
	~Vector();
	Vector& operator=(const Vector&);
	Vector& operator=(Vector&&) noexcept;
	int& operator[](unsigned int);
	double operator*(const Vector&);
	friend std::ostream& operator<<(std::ostream&, const Vector&);
	friend std::istream& operator>>(std::istream&, Vector&);
};
#endif