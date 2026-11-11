#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	string c1, s1, c2, s2;
	bool a, b, c, d;
	ifstream fin;
	fin.open("travel.in");
	fin >> c1 >> s1 >> c2 >> s2;
	fin.close();
	if (c1 == c2)
		a = 1;
	else
		a = 0;

	if (a == 1 && s1[0] == s2[0] && s1[1] == s2[1])
		b = 1;
	else
		b = 0;

	if (b == 1 && (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'))
		c = 1;
	else if (b == 1 && (s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F'))
		c = 1;
	else
		c = 0;

	if (c == 1 && ((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'A')))
		d = 1;
	else if (c == 1 && ((s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'B')))
		d = 1;
	else if (c == 1 && ((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')))
		d = 1;
	else
		d = 0;
	ofstream fout;
	fout.open("travel.out");
	fout << a << b << c << d;
	fout.close();
	return 0;
}