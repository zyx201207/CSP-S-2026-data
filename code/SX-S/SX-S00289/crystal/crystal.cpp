#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long a[N], n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		m += a[i];
	}
	sort(a, a + n);
	for (int i = n; i >= 1; i--) {
		long long w = m / i;
		if (w >= a[i - 1]) {
			cout << i;
			return 0;
		}
		m -= a[i];
	}
	return 0;
}