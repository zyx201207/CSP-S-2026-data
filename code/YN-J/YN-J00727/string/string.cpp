#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	int n;
	cin >> n;
	int a[200002];
	char c[200002];

	a[0] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> c[i];
		a[i] += a[i - 1];
	}

	int cnt = 0;
	int m = a[n] / 2;
	int an1 = 1, an2 = n;
	for (int i = 1; i <= m; ++i) {
		if (i >= a[an1])
			++an1;
		if (a[n] - i + 1 <= a[an2 - 1])
			--an2;
		if (c[an1] != c[an2])
			++cnt;
	}
	cout << cnt;
	return 0;
}