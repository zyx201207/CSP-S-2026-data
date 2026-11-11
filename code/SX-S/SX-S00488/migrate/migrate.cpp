#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
int n, d, x[N], dis[5010][5010], vis[N], res, num[5010][5010];
inline void solve() {
	memset(dis, 0x3f, sizeof(dis));
	memset(num, 0, sizeof(num));
	res = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> x[i], dis[i][i] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; x[j] - x[i] <= d && j <= n; j++) dis[i][j] = 1;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			for (int k = i + 1; k <= j - 1; k++)
				if (dis[i][j] == dis[i][k] + dis[k][j]) num[i][j]++;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (num[i][j] == 2) res++;
	cout << res << '\n';
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int C, T; cin >> C >> T;
	while (T--) {
		solve();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/