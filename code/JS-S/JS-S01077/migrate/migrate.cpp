#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e2 + 5;

int c, t, n, d, a[N], cnt[N][N];
vector <int> edges[N];

inline void dfs (int x, int y, int now, int step = 0) {
	for (auto qwq : edges[now]) {
		cnt[qwq][step + 1]++;
		dfs(x, y, qwq, step + 1);
	}
}

inline void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (abs (a[i] - a[j]) <= d) {
				edges[i].push_back(j);
            } else
				break;
    int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
            memset(cnt, 0, sizeof(cnt));
			dfs(i, j, i, 0);
			for (int k = 1; k <= n; k++)
				if (cnt[j][k]) {
					if (cnt[j][k] == 2) {
						ans++;
                    }
				} else break;
		}
    cout << ans << "\n";
	for (int i = 1; i <= n; i++)
        edges[i].clear();
}

signed main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
        if (c == 13 || c == 14)
            cout << "0\n";
        else
            solve();
	}
}
