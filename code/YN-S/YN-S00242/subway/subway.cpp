#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;
int c, n, m, d, q;
int w[MAXN], t[505][MAXN];
int len[505];
vector <int> adj[MAXN];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> c >> n >> m >> d >> q;

	for (int i = 1; i <= m; i++) {

		cin >> w[i];
	}

	int ans;

	for (int i = 1; i <= n; i++) {

		cin >> len[i];

		for (int j = 1, k; j <= len[i]; j++) {

			cin >> k >> t[i][k];
		}
	}

	while (q--) {
		int x, y;
		cin >> x >> y;
		ans = w[x] + w[y];
		cout << 2 * ans;
	}

	return 0;
}
