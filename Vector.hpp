#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <fstream>

class Vector
{
private:
	int* array;
	unsigned int n;
public:
	Vector();
	Vector(const Vector&);
	Vector(Vector&&);
	~Vector();
	double operator*(const Vector&);
	int operator[](int);
	friend std::ostream& operator<<(std::ostream&, Vector&);
	friend std::istream& operator>>(std::istream&, Vector&);
};
#endif