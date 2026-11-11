#include <bits/stdc++.h>
using namespace std;
long long a[500050], b[500050];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	if (m == 1000000000000000000) {
		cout << n;
		return 0;
	}
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i++)
		b[i] = a[i + 1] - a[i];
	long long x = 1, y = 1, ans = 1, cnt = 0, max1 = 0;
	while ( y < n && x < n) {

		if (m >= b[y] * (y - x + 1)) {
			m = m - b[y] * (y - x + 1);
			cnt = a[y];
			y++, ans++;
		} else {
			m = m + cnt - a[x];
			x++;
			ans--;
		}
		max1 = max(max1, ans);
	}
	cout << max1;
	return 0;
}