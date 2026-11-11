#include <bits/stdc++.h>
using namespace std;



long long  m, n, a[500001], b[500001], ma = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		b[i] = a[i + 1] - a[i];
		if (b[i] > ma)
			ma = b[i];
	}
	cout << (m + ma - 1) / ma + 1;
	return 0;
}
