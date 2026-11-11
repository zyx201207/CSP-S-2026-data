#include <bits/stdc++.h>
using namespace std;
long long n, m, sum = 0, ans = 1;
long long a[500005], b[500005];

void solvea() {
	for (int i = 2; i <= n; i++) {
		if (i * a[i] - sum <= m)
			ans++;
		else
			break;
	}
	cout << ans;
	return;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a + 1, a + 1 + n);
	bool b = 0;
	for (int i = 1; i <= n; i++) {
		if (i > n && i > 1 && a[i] - a[i - 1] != a[i + 1] - a[i])
			b = 1;
	}
	if (b == 0) {
		solvea();
		return;
	} else
		solvea();
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	solve();
	return 0;
}