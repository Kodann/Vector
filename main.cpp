#include "stdio.h"
#include "stdlib.h"
#include "vector.h"
#include <iostream>
#include <locale>
#include <vector>
#include <fstream>

std::ostream& operator<<(std::ostream &out, const Point &o) {
	out << "x=" << o.x  << " y=" << o.y << " z=" << o.z << ";";
	return out;
}

std::istream& operator>>(std::istream &in, Point &o) {
	cout << "Введите x, y, z через ввод" << endl;
	in >> o.x;
	in >> o.y;
	in >> o.z;
	return in;
}

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	size_t N = 3;
	int gg = 3;
	char txt = 'a';
	Point p;
	Point p1;
	cin >> p;
	cin >> p1;
	Vector<int> a(N, 23);
	Vector<int> a1(a);
	//a1.print(cout);
	Vector<char> c(N, 'd');
	Vector<float> f(N, 1.01);
	Vector<double> d(N, 5.0001);
	Vector<Point> tchk(2, p);
	ofstream pl;
	///////////////////////////////////////////////
	pl.open("C:\\laba\\note.txt");
	cout << "Работа с char" << endl;
	c.print(cout);//работа с char
	cout << "insert(1, a)" << endl;
	try {
		c.insert(1, txt);
	}
	catch (exception &ex) {
		cout << "Индекс" << ex.what() << endl;
	}
	c.print(pl);
	cout << "erase(1)" << endl;
	c.erase(1);
	c.print(cout);
	////////////////////////////////////////////////


	cout << endl << "Работа с int" << endl;
	a.print(cout);//работа с int
	cout << "insert" << endl;
	for (int i = 0; i < 11; i++) {
		try {
			a.insert(i, i);
		}
		catch (exception &ex) {
			cout << "Индекс" << ex.what() << endl;
		}
	}
	int o = 0;
	try {
		o = a.at(10);
	}
	catch (exception &ex) {
		cout << "Индекс" << ex.what() << endl;
	}
	a.print(cout);
	cout << "at(10)" << endl;
	cout << o << endl;
	cout << "erase(5)" << endl;
	a.erase(5);
	a.print(cout);

	//////////////////////////////////////////////////

	cout << endl << "Работа с float" << endl;
	f.print(cout);//работа с float
	float k = 2.02;
	for (int i = 0; i < 11; i++) {
		try {
			f.insert(i, k);
		}
		catch (exception &ex) {
			cout << "Индекс" << ex.what() << endl;
		}
		k++;
	}
	try {
		k = f.at(11);
	}
	catch (exception &ex) {
		cout << "Индекс" << ex.what() << endl;
	}
	cout << "insert" << endl;
	f.print(cout);
	cout << "at(11)" << endl;
	cout << k << endl;
	f.erase(5);
	cout << "erase(5)" << endl;
	f.print(cout);
	///////////////////////////////////////////

	

	cout  << endl << "Работа с double" << endl;
	d.print(cout);//работа с double
	double k1 = 1.02;
	for (int i = 0; i < 11; i++) {
		try {
			d.insert(i, k1);
		}
		catch (exception &ex) {
			cout << "Индекс" << ex.what() << endl;
		}
		k1++;
	}
	cout << "at(15)" << endl;
	try {
		k1 = d.at(15);
	}
	catch (exception &ex) {
		cout << "Индекс" << ex.what() << endl;
	}
	cout << "insert" << endl;
	d.print(cout);
	
	//cout << k1 << endl;
	cout << "erase(5)" << endl;
	d.erase(5);
	d.print(cout);

	////////////////////////////////////////

	cout  << endl << "Работа с Point" << endl;

	tchk.print(cout);
	try {
		tchk.insert(1, p1);
	}
	catch (exception &ex) {
		cout << "Индекс" << ex.what() << endl;
	}
	cout << "insert" << endl;
	tchk.print(cout);
	try {
		tchk.erase(1);
	}
	catch (exception &ex) {
		cout << "Индекс" << ex.what() << endl;
	}
	cout << "erase(1)" << endl;
	tchk.print(cout);
	/////////////////////////////////////////////
	getchar();
	getchar();
	return 0;
}