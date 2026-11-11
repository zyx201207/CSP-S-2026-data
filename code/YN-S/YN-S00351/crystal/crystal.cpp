#include <bits/stdc++.h>
using namespace std;
long long pre[500050], a[500050];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		pre[i] = pre[i - 1] + (a[i] - a[i - 1]) * (i - 1);
	}
	long long l, r;
	l = 1;
	r = n;
	while (r >= l) {
		long long zj = (l + r) / 2;
		if (pre[zj] <= m) {
			l = zj + 1;
		} else {
			r = zj - 1;
		}

	}
	cout << r;
	return 0;
}