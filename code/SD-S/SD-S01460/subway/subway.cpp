#include <bits/stdc++.h>
#define int long long
typedef unsigned long long ull;

using namespace std;

const int N = 1e5 + 5;
int C, n, m, d, q, w[N], arr[505][N], t[505][N], k[505];
set<int> S[505];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> C >> n >> m >> d >> q;

	for (int i = 1; i <= m; ++i) {
		cin >> w[i];
	}

	memset(t, 0x3f, sizeof t);

	for (int i = 1; i <= n; ++i) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; ++j) {
			cin >> arr[k[i]][j] >> t[i][arr[k[i]][j]];
			S[i].insert(k[i]);
		}
	}

	for (int i = 1; i <= q; ++i) {
		int a, b;
		cin >> a >> b;

		int ans = w[a] + w[b], _A = 0;
		for (int k = 1; k <= n; ++k) {
			if (S[k].find(a) != S[k].end() && S[k].find(b) != S[k].end()) {
				_A = min(_A, t[k][a] + t[k][b]);
			}
		}
		ans += _A;
		cout << ans << '\n';
	}

	return 0;
}
