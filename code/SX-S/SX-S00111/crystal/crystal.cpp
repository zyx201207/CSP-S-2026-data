#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long n, m, a[N], cz, ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	long long ct = ceil(n * 1.0 / 2);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	cz = a[n] - a[n - 1];
	for (int i = 1; i <= n; i++) {
		m -= cz;
		if (m >= 0)
			ans++;
		else {
			break;
		}
	}
	cout << ans;
	return 0;
}
