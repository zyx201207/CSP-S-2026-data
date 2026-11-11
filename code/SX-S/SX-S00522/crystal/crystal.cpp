#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	long long ans = 1;
	int a[500100];
	cin >> n >> m;
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (long long i = 1; i < n; i++) {
		if (m == 0 && a[i] != a[i - 1]) {
			break;
		}
		if ((a[i] - a[i - 1]) * i <= m) {
			m -= (a[i] - a[i - 1]) * i;
			ans++;
		}
	}
	cout << ans;
}