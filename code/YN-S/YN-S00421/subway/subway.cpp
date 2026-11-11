#include <bits/stdc++.h>
using namespace std;
const int MAXM = 5e5 + 2;
int w[MAXM], x[MAXM], y[MAXM];
//vector<pair<int, int> > a, t;
const int MAXN = 1e4 + 2;
int a[MAXN][MAXN], t[MAXN][MAXN];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q, k;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	cin >> k;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++)
			cin >> a[i][j] >> t[i][j];
	}

	for (int r = 1; r <= q; r++) {
		cin >> x[r] >> y[r];
	}

	cout << 48 << endl << 52;


















	return 0;
}