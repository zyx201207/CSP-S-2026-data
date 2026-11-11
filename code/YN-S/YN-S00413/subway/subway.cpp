#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 2e5 + 7;
LL c, n, m, d, q;
LL w[N], k[N], a[1001][1001], t[1001][1001];
LL x[N], y[N];

struct node {
	int frm, to, wth;
} edge[N];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 2; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			int x1, y1;
			cin >> x1 >> y1;
			a[i][x1] = 1;
			t[i][x1] = y1;
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> x[i] >> y[i];
	}

	return 0;
}
