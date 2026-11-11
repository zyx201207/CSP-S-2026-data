#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	long long n, m;
	cin >> n >> m;
	vector<long long> a(n + 1);
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];

	}
	sort(a.begin(), a.end());
	if (n == 1) {
		cout << 1;
		return 0;
	}
	for (long long i = 2; i <= n; i++) {
		long long ans = (a[i] - a[i - 1]) * (i - 1);
		if (ans > m) {
			cout << i - 1;
			return 0;
		} else if (ans == m) {
			cout << i;
			return 0;
		} else if (ans < m && i == n) {
			cout << i;
			return 0;
		}
		m -= ans;
	}
	return 0;
}
