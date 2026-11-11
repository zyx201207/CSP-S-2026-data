#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	long long n, ai;
	char si;
	long long a = 0, b = 0, c = 0, d = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ai;
		cin >> si;
		for (long long j = 0; j < ai; j++) {
			S[b] = si;
			b++;
		}
	}

	c = b - 1;
	//for (long long g = 0; g < b; g++) {
	//	cout << S[g];
	//}

	//cout << endl;


	long long b1;
	if (b % 2 == 0)
		b1 = 0.5 * b;
	else
		b1 = 0.5 * b + 0.5;
	//cout << "b1" << ' ' << b1 << endl << 'c' << c << ' ' << 'd' << d << endl;
	for (long long e = 0; e < b1; e++) {
		c--;
		d++;
		if (c == d) {}
		else if (S[c] != S[d])
			a += 1;
	}
	//cout << 'c' << c << ' ' << 'd' << d << endl;
	cout << a;
	return 0;
}