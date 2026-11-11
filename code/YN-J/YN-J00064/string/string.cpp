#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
	int n;
	double k, length, r;
	int num;
	char let;
	cin >> n;
	string S;
	k = 0;
	length = 0;
	r = 0;
	ifstream fin;
	fin.open("string.in");
	for (int i = 0; i < n; i++) {
		fin >> num >> let;
		for (int j = 0; j < num; j++) {
			S[k] = let;
			k++;
		}
		length += num;
	}
	fin.close();
	/*for (int i = 0; i < length; i++)
		cout << S[i];
	cout << endl;*/
	for (int i = 0; i < length; i++) {
		if (length - floor(length / 2) == 0 && i + 1 == length - i - 1)
			break;
		if (length - floor(length / 2) != 0 && i == length - i - 1)
			break;
		if (S[i] != S[length - i - 1])
			r += 1;
	}
	ofstream fout;
	fout.open("string.out");
	fout << r;
	fout.close();
	return 0;
}