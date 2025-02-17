#ifndef VECTOR_HPP
#define VECTOR_HPP
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
};
#endif