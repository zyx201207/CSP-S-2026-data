#include <bits/stdc++.h>
using namespace std;
#define int long long
#define oo 1000000000000000000
#define _i128 __int128
#define pii pair<int, int>
#define fi first
#define se second
#define for1(i, a, b) for (int i = (a); i <= (b); i++)
#define for2(i, a, b) for (int i = (a); i >= (b); i--)
const int N = 500 + 5, M = 5e5 + 5;
int TT = 1;
int f[N][N], w[M];
vector<pii> G[M];

void solve()
{
	int c, n, m, d, q; cin >> c >> n >> m >> d >> q;
	for1(i, 1, m) cin >> w[i];
	for1(i, 1, n){
		int k; cin >> k;
		for1(j, 1, k){
			int a, t; cin >> a >> t;
			G[a].push_back({i, t});
		}
	}
	for1(i, 1, n) for1(j, 1, n) f[i][j] = oo;
	for1(i, 1, n) f[i][i] = 0;
	for1(i, 1, m)
		for1(j, 0, (int)G[i].size() - 1)
			for1(k, 0, (int)G[i].size() - 1) if (j != k)
				f[G[i][j].fi][G[i][k].fi] = min(f[G[i][j].fi][G[i][k].fi], G[i][j].se + G[i][k].se);
	for1(k, 1, n)
		for1(i, 1, n)
			for1(j, 1, n)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	while (q--){
		int s, t; cin >> s >> t;
		int ans = oo;
		for1(i, 0, (int)G[s].size() - 1)
			for1(j, 0, (int)G[t].size() - 1)
				ans = min(ans, f[G[s][i].fi][G[t][j].fi] + G[s][i].se + G[t][j].se);
		cout << ans + w[s] + w[t] << "\n";
	}	
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	//cin >> TT;
	while (TT--)
		solve();

	return 0;
}
