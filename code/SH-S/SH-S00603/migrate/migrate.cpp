#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
int c, t;
int n, d;
int a[N];
int minn, cnt;
void dfs1(int u, int v, int s)
{
	if(u > v) return ;
	if(u == v)
	{
		minn = min(s, minn);
		return ;
	}
	for(int i = u + 1; i <= v; i ++)
	{
		if(a[i] - a[u] <= d)
		{
			dfs1(i, v, s + 1);
		}
	}
}
void dfs2(int u, int v, int s)
{
	if(u > v) return ;
	if(u == v)
	{
		cnt += (s == minn);
		return ;
	}
	for(int i = u + 1; i <= v; i ++)
	{
		if(a[i] - a[u] <= d)
		{
			dfs2(i, v, s + 1);
		}
	}
}
void solve()
{
	cin >> n >> d;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	int ans = 0;
	if(n <= 9)
	{
		for(int i = 1; i <= n; i ++)
		{
			for(int j = i; j <= n; j ++)
			{
				minn = 1e18;
				dfs1(i, j, 0);
				cnt = 0;
				dfs2(i, j, 0);
				if(cnt == 2) ans ++;
			}
		}
		cout << ans << "\n";
		return ;
	}
	cout << 0 << "\n";
}
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while(t --) solve();
	return 0;
}
