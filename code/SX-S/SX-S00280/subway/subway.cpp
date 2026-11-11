#include <bits/stdc++.h>

#define int long long

using namespace std;
const int N = 5e5+10;

int c, n, m, d, q;

int w[N];

int x[N], y[N];

int k;

int sum = 0;

signed main() {

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> c >> n >> m >> d >> q;

	for (int i = 1; i <= m; i++) {

		cin >> w[i];

	}
	for (int i = 1; i <= n; i++) {

		cin >> k;

		int a[N];

		for (int i = 1; i <= k; i++) {

			cin >> a[i];

		}

		sort(a + 1, a + 1 + k);

		sum += a[1];

	}

	for (int i = 1; i <= q; i++) {

		cin >> x[i] >> y[i];

	}

	cout << sum;

	return 0;
}