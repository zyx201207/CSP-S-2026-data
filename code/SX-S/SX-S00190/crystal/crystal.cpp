#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], d;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	d = a[2] - a[1];

	for (int i = 1; i <= n; i++) {
		if (i * (i + 1) * d / 2 > m)
			cout << i - 1;
	}
	if (n * (n + 1) * d / 2 <= m)
		cout << n;
	return 0;
}
