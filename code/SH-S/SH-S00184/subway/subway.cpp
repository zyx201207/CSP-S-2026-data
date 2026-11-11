#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 501, M = 5e5 + 1;
int cid, n, m, d, q, dis[N][N], w[M], sub[M][21], siz[M], tot, a[M], t[M];

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> cid >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) cin >> w[i];
	for (int i = 1; i <= n; ++i)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; ++j)
		{
			++tot;
			cin >> a[tot] >> t[tot];
			++siz[a[tot]];
			sub[a[tot]][siz[a[tot]]] = tot;
			a[tot] = i;
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= n; ++i) dis[i][i] = 0;
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= siz[i]; ++j)
		{
			int cx = a[sub[i][j]], tx = t[sub[i][j]];
			for (int k = j + 1; k <= siz[i]; ++k)
			{
				int cy = a[sub[i][k]], ty = t[sub[i][k]];
				dis[cx][cy] = dis[cy][cx] = min(dis[cx][cy], tx + ty);
			}
		}
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		int ans = 1e18;
		int xsiz = siz[x], ysiz = siz[y];
		for (int i = 1; i <= xsiz; ++i)
		{
			int cx = a[sub[x][i]], tx = t[sub[x][i]];
			for (int j = 1; j <= ysiz; ++j)
			{
				int cy = a[sub[y][j]], ty = t[sub[y][j]];
				ans = min(ans, dis[cx][cy] + tx + ty);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
