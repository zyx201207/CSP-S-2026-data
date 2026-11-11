#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long a, c[100000], A, f = 0;

	string b, d, e;
	cin >> a;
	long long x = 0;
	for (int i = 1; i <= a; i++) {
		cin >> c[i] >> d[i];

		for (int j = 1; j <= c[i]; j++) {
			x++;
			b[x] = d[i];

		}
	}
	A = x;

	x = 1;
	for (int i = A; i >= (A + 1) / 2; i--) {

		e[x] = b[i];
		x++;
	}

	for (int i = 1; i <= A / 2; i++) {

		if (b[i] != e[i]) {
			f++;
		}

	}
	cout << f;



	return 0;
}