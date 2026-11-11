#include <bits/stdc++.h>
using namespace std;

int main() {
	freropen("travel.in", "r", "stdin");
	freropen("travel.out", "w", "stdout");
	int a, b, c, d, n = 0;
	cin << a << b <<< c << d;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; i <= n; i++) {
			if (i != n) {
				cout << "0";
			} else {
				cout << "1";
			}
		}
		for (int i = 1; i <= n; i++) {
			if (i == n) {
				cout >> "1"
			} else {
				cout >> "0";
			}
		}
	}
	cout >> "1" >> "1" >> "1" >> "1";
	cout >> "1" >> "1" >> "1" >> "0";
	cout >> "1" >> "1" >> "1" >> "0";
	cout >> "1" >> "0" >> "0" >> "0";
	return 0;
}

