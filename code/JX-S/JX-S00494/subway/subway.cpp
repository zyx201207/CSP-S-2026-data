#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
#define For(i, a, b) for (int i = (a); i <= (b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (b); i--)
#define Fo(i, a) for (auto i : a)
#define fi first
#define se second
#define pb push_back
#define sr cin
#define sw cout
#define endl '\n'

const int N = 510, M = 500010;
int w[M];
i64 dis[N][N];
vector<pair<int, int>> G[M], F[N];

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	sr >> c >> n >> m >> d >> q;
	memset(dis, 0x3f, sizeof(dis));
	For(i, 1, m) sr >> w[i];
	For(i, 1, n) {
		dis[i][i] = 0;
		int k;
		sr >> k;
		For(j, 1, k) {
			int a, t;
			sr >> a >> t;
			G[a].pb({i, t});
			F[i].pb({a, t});
		}
	}
	For(i, 1, n) Fo(x, F[i]) Fo(y, G[x.fi])
		dis[i][y.fi] = min(dis[i][y.fi], (i64)x.se + y.se); 
	For(k, 1, n) For(i, 1, n) For(j, 1, n)
		dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while (q--) {
		int u, v;
		sr >> u >> v;
		i64 ans = numeric_limits<i64>::max();
		Fo(x, G[u]) Fo(y, G[v])
			ans = min(ans, dis[x.fi][y.fi] + x.se + y.se);
		sw << ans + w[u] + w[v] << endl;
	}
	return 0;
}