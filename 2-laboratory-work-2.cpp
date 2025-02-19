#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Vector.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	
	string input_file_name = argv[1];
	string output_file_name = argv[2];
	/*
	vector<Vector> result;
	ifstream file(input_file_name);
	unsigned int n;
	file >> n;
	for (int i = 0; i < n; i++)
	{
		Vector ob;
		file >> ob;
		result.push_back(ob);
	}
	for (int i = 0; i < n; i++)
	{
		cout << result[i] << endl;
	}
	*/
	//Конструктор по умолчанию
	Vector default_ob{};

	//Конструктор с параметрами
	unsigned int size = 3;
	int* test_arr_1 = new int[size];
	test_arr_1[0] = -5; test_arr_1[1] = 4; test_arr_1[2] = 12;
	int* test_arr_2 = new int[size];
	test_arr_2[0] = 3; test_arr_2[1] = 1; test_arr_2[2] = 0;
	Vector param_ob_1{ size, test_arr_1 };
	Vector param_ob_2{ size, test_arr_2 };

	//Обращение по индексу
	cout << param_ob_1[1] << endl;
	
	//Скалярное произведение
	cout << param_ob_1 * param_ob_2 << endl;

	//Конструктор копирования
	Vector v1 = param_ob_1;
	cout << v1 << endl << param_ob_1 << endl;

	//Оператор копирования
	Vector v2;
	v2 = param_ob_2,v2;
	cout << v2 << endl << param_ob_2 << endl;

	//Конструктор перемещения
	Vector v3 = move(param_ob_1);
	cout << v3 << param_ob_1 << endl;

	//Оператор перемещения
	Vector v4;
	v4 = move(param_ob_2);
	cout << v4 << param_ob_2 << endl;

	delete[] test_arr_1; delete[] test_arr_2;
}