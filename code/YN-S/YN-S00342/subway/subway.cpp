#include <bits/stdc++.h>
using namespace std;
long long w[500005];
long long k[505];
long long at[505][1010];
long long x[100005], y[100005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c, m, n, d, q;
	cin >> c >> m >> n >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= 2 * k[i]; j++) {
			cin >> at[i][j];
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> x[i] >> y[i];
		cout << w[x[i]] + w[y[i]] + at[x[i]][y[i]] + at[y[i]][x[i]] << " ";
	}



	return 0;
}
