#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long b[1001], d = 0, e = 0;
	int a;
	char c[1001];
	cin >> a;

	for (int i = 1; i <= a; i++) {

		cin >> b[i] >> c[i];
		d += b[i];

		for (int j = 1; j <= i; j++) {

			if (int(c[j]) != int(c[i])) {
				e++;
			}
		}
	}

	if (d % 2 != 0 && e != 0) {
		cout << d / e + 1;
	}

	if (d % 2 == 0 && e != 0) {
		cout << d / e;
	}

	if (e == 0) {
		cout << 0;
	}


	return 0;
}