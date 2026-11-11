#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 5e5 + 5, N = 5e2 + 5;
int c, n, m, d, q, w[M];
vector<pair<int, int>> v;
vector<int> e[M];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}

	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			v.push_back({a, t});
		}
	}
	sort(v.begin(), v.end());
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << w[x] + w[y] << '\n';
	}
	return 0;
}