#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 4e18;
const int N = 2e6 + 10;
int n, d, x[N];
int f[305][305], cnt[305][305];
void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) cin >> x[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) f[i][j] = INF;
	for (int i = 1; i < n; i++) {
		int op = upper_bound(x + 1, x + 1 + n, x[i] + d) - x - 1;
		for (int j = i + 1; j <= op; j++) f[i][j] = 1;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (f[i][k] == INF || f[k][j] == INF) continue;
				else if (f[i][k] + f[k][j] < f[i][j]) f[i][j] = f[i][k] + f[k][j], cnt[i][j] = 1;
				else if(f[i][k] + f[k][j] == f[i][j]) cnt[i][j]++;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (f[i][j] == INF) continue;
			ans += (cnt[i][j] == 2);
		}
	}
	cout << ans << '\n';
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int C, T;cin >> C >> T;
	while (T--) solve();
	return 0;
}