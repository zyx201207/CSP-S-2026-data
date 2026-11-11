#include <bits/stdc++.h>
using namespace std;

int d, n;
long long x[2000009];

bool is_sjdyd(int u, int v) {
	int len = 0;
	long long cnt = 0;
	for (int i = 1; i != n; ) {
		++len;
		long long int* tmp = upper_bound(x + len, x + n + 1, x[i] + d);
		cnt *= tmp - lower_bound(x + len, tmp, x[i] + d);
		i = tmp - x + 1;
	}

	return cnt == 2;
}

void solve() {
	cin >> n >> d;

	for (int i = 1; i <= n; ++i)
		cin >> x[i];

	int cnt = 0;
	for (int u = 1; u < n; ++u)
		for (int v = u + 1; v <= n; ++v)
			cnt += is_sjdyd(u, v);

	cout << cnt << '\n';
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int c, t;
	cin >> c >> t;

	while (t--)
		solve();
}
