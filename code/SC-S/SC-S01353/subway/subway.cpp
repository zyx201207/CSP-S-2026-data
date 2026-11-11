#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define x first
#define y second
#define V vector
#define pb push_back
#define INF (int)1e18
using namespace std;

const int maxn = 500;
const int maxm = 5e5;

int c, n, m, d, q;
int w[maxm+5];
int dis[maxn+5][maxn+5];
V<pii> ps[maxn+5];
V<pii> to[maxm+5];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++i) cin >> w[i];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			dis[i][j] = (i==j ? 0 : INF);
	for(int i = 1; i <= n; ++i)
	{
		int k; cin >> k;
		ps[i].resize(k);
		for(auto _ : ps[i])
		{
			int x, len; cin >> x >> len;
			_ = {x, len};
			for(auto __ : to[x])
				dis[i][__.x] = dis[__.x][i] = min(dis[i][__.x], len + __.y);
			to[x].pb({i, len});
		}
	}
	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while(~--q)
	{
		int x, y;
		cin >> x >> y;
		int ans = INF;
		for(auto i : to[x])
			for(auto j : to[y])
				ans = min(ans, dis[i.x][j.x] + i.y + j.y + w[x] + w[y]);
		cout << ans << '\n';
	}

	return 0;
}
/*
subway.exe < subway1.in > subway1.out
subway.exe < subway2.in > subway2.out
subway.exe < subway3.in > subway3.out
subway.exe < subway4.in > subway4.out
subway.exe < subway5.in > subway5.out
subway.exe < subway6.in > subway6.out
subway.exe < subway7.in > subway7.out

fc subway1.out subway1.ans
fc subway2.out subway2.ans
fc subway3.out subway3.ans
fc subway4.out subway4.ans
fc subway5.out subway5.ans
fc subway6.out subway6.ans
fc subway7.out subway7.ans
*/