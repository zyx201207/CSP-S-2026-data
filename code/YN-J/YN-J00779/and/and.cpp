#include <bits/stdc++.h>
using namespace std;

bool cmp(long long x, long long y) {
	return x > y;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n, m, a[200001] = {};
	cin >> n >> m;
	long long b[200001] = {}, t = 1, c[200001] = {};
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
		int z = 0;
		while (pow(2, z) <= (a[i] * 1.0)) {
			z++;
		}
		if (pow(2, z) == ((a[i] + 1) * 1.0)) {
			b[t] = a[i];
			t++;
		}
	}
	sort(a + 1, a + n + 1, cmp);
	sort(b + 1, b + t, cmp);
	long long x = b[1], f = m;
	bool fl = 0;
	for (int i = 1; i <= f ; i++) {
		if (a[i] > x) {
			f++;
			continue;
		}
		c[i] = a[i];
	}
	sort(c + 1, c + n + 1, cmp);
	int s = c[1];
	for (int i = 1; i <= m; i++) {
		s = s & c[i];
	}
	cout << s;
	return 0;
}