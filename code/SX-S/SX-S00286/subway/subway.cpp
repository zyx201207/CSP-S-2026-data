#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[500010];

struct RD {
	int k;
	vector<int> a, t;
} rd[510];

struct WG {
	int be, en;
} wg[100010];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;

	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}

	for (int i = 1; i <= n; i++) {
		cin >> rd[i].k;
		for (int j = 1; j <= rd[i].k; j++) {
			int x;
			cin >> x;
			if (j % 2) {
				rd[i].a.push_back(x);
			} else {
				rd[i].t.push_back(x);
			}
		}
	}

	for (int i = 1; i <= q; i++) {
		cin >> wg[i].be >> wg[i].en;
		cout << w[wg[i].be] + w[wg[i].en] << '\n';
	}
	return 0;
}