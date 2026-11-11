#include <bits/stdc++.h>
using namespace std;

int n, m, d, q, c;
long long w[500005];
int a[501][50001], t[501][50001], k;
long long x[500005], y[500005];
int main() {
	freopen("subway1.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++)
			cin >> a[i][j] >> t[i][j];
	}
	for (int i = 1; i <= q; i++) {
		cin >> x[i] >> y[i];
	}
	while (q--) {
		long long sum = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = x[i]; j <= y[i]; j++) {
				sum += w[j] + t[i][j];
			}
		}

		cout << sum << endl;
	}
	return 0;
}