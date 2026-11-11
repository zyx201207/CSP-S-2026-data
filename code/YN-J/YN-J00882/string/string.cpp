#include <bits/stdc++.h>
using namespace std;
char m[1000000000];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, d = 1, a, cnt = 0, cmp = 0;
	char c;
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> a >> c;

		for (int j = d; j <= d + a - 1; j++) {

			m[j] = c;
			cmp++;
		}

		d = d + a ;
	}

	for (int i = 1; i <= cmp / 2 + 1; i++) {

		if (m[i] != m[cmp - i + 1]) {
			cnt++;
		}

	}

	cout << cnt;
	return 0;
}