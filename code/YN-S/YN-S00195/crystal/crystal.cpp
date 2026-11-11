#include <bits/stdc++.h>
using namespace std;
long long a[10000000];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m, s = 0;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		cin >> a[i];
	}
	s = a[2] - a[1];
	sort(a + 1, a + n + 1);
	for (int i = 0; i <= m; i++) {
		if (s <= 2 && m <= 2) {
			a[1] = a[2];
			cout << a[i] + a[1];
		}
	}
	return 0;
}