#include <bits/stdc++.h>
using namespace std;

unsigned long long n, a, m, t;
char c;
string c1;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	for (unsigned long long i = 1; i <= n; i++) {

		string c2;
		cin >> a >> c2;

		for (unsigned long long j = 0; j < a; j++) {

			c1 = c1 + c2;
			t++;
		}
	}

	for (unsigned long long i = 0; i <= t; i++, t--) {

		if (c1[i] != c1[t]) {
			m++;
		}
	}

	cout << m;
	return 0;
}
