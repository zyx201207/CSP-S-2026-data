#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2000010, M = 25;

int c, T, n, d;
int a[N], f[N], g[N], h[N];
int f1[N][M], f2[N][M];
int dis[3010], cnt[3010];

void dfs(int u)
{
	if (u == n) return;
	for (int i = u + 1; i <= n; i ++ )
	{
		if (a[i] - a[u] > d) break;
		if (dis[i] > dis[u] + 1)
		{
			dis[i] = dis[u] + 1;
			cnt[i] = cnt[u];
			dfs(i);
		}
		else if (dis[i] == dis[u] + 1)
		{
			cnt[i] += cnt[u];
			dfs(i);
		}
	}
}

void solve1()
{
	while (T -- )
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i ++ ) cin >> a[i];
		
		int ans = 0;
		for (int i = 1; i <= n; i ++ )
		{
			memset(cnt, 0, sizeof cnt);
			memset(dis, 0x3f, sizeof dis);
			dis[i] = 0, cnt[i] = 1;
			dfs(i);
			for (int j = i + 1; j <= n; j ++ )
				if (cnt[j] == 2) ans ++ ;
		}
		
		cout << ans << '\n';
	}
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	memset(f2, 0x3f, sizeof f2);
	cin >> c >> T;
	if (c <= 6) solve1(), exit(0);
	while (T -- )
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i ++ ) cin >> a[i];
		
		for (int i = 1; i <= n; i ++ )
		{
			int l = 0, r = i - 1, p = 0;
			while (l <= r)
			{
				int mid = l + r >> 1;
				if (a[i] - a[mid] <= d) p = mid, r = mid - 1;
				else l = mid + 1;
			}
			f1[i][0] = p;
		}
		for (int i = 1; i <= n; i ++ )
		{
			int l = i + 1, r = n + 1, p = n + 1;
			while (l <= r)
			{
				int mid = l + r >> 1;
				if (a[mid] - a[i] <= d) p = mid, l = mid + 1;
				else r = mid - 1;
			}
			f2[i][0] = p;
		}
		f1[n + 1][0] = f1[n][0], f2[0][0] = f2[1][0];
		f1[0][0] = f1[1][0], f2[n + 1][0] = f2[n][0];
		int m = log2(n) + 1;
		for (int j = 1; j <= m; j ++ )
		{
			for (int i = n + 1; f1[i][j - 1] > 0; i -- )
				f1[i][j] = f1[f1[i][j - 1]][j - 1];
			for (int i = 0; f2[i][j - 1] <= n; i ++ )
				f2[i][j] = f2[f2[i][j - 1]][j - 1];
		}
		for (int i = 1, j = 1; i <= n; i ++ )
		{
			while (j <= n)
			{
				int u = i, v = j, cnt = 0, flg = 0;
				for (int k = m; ~k; k -- )
					if (f2[u][k] < j)
					{
						u = f2[u][k];
						v = f1[v][k];
						cnt += (1 << k);
					}
				u = f2[u][0], v = f1[v][0];
				u = i;
				int ff = 0;
				if (!v) ff = 1;
				for (int k = m; ~k; k -- )
					if (f2[u][k] < j)
					{
						u = f2[u][k];
						if (v <= n) v = f2[v][k];
						if (v < u) flg = 1;
					}
				u = f2[u][0];
				if (v <= n) v = f2[v][0];
				if (v < u) flg = 1;
				if (flg) break;
				j ++ ;
			}
			f[i] = j;
		}
		for (int i = n; i; i -- )
		{
			int j = i;
			while (j && f[j] == f[i]) j -- ;
			j ++ ;
			g[j] = i - j + 1;
		}
		int res = 0;
		for (int i = 1; i <= n; i ++ )
		{
			int j = i;
			while (j <= n && f[j] == f[i]) j ++ ;
			j -- ;
			if (f[i] <= n) res += (j - i + 1) * (g[f[i] + 1] + 1);
		}
		
		cout << res << '\n';
	}
	
	return 0;
}
