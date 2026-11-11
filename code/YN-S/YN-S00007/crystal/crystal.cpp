#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], c[500005], p;
bool is = 0;

bool cmp(long long a, long long b) {
	return a < b;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	sort(a + 1, a + n + 1, cmp);

	for (int i = 1; i <= n; i++) {

		c[i] = c[i - 1] + (a[i] - a[i - 1]) * (i - 1);
	}

	for (int i = 1; i <= n; i++) {

		if (c[i] > m) {
			p = i - 1;
			is = 1;
			break;
		}
	}

	if (is == 0) {
		p = n;
	}

	cout << p << endl;
	return 0;
}
