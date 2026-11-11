#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
int a[1005][1005], t[1005][1005]; 
int w[10000005], k[1000005];
bool vis[1000005];
int xr, yr, ans = 0;
int stcur[1000005];
struct st
{
	int l[1005];
}li[1005];
int check(int z,int l)
{
	for (int i = 1; i <= k[l]; ++i)
	{
		if (a[l][i] == z) return i;
	}
}
void dfs(int z, int ls, int time)
{
	if (z == yr)
	{
		ans = min(ans, time + t[ls][check(z, ls)] + w[z]);
		return;
	}
	int ttime = time;
	if (ls == 0)
	{
		ttime += w[z];
	}
	if (vis[z]) return;
	bool shifoufanhui = 1;
	for (int i = 1; i <= stcur[z]; ++i)
	{
		int temp = check(z,li[z].l[i]);
		int t2 = check(z, ls);
		if (li[z].l[i] != ls) 
		{
			ttime += (ls == 0 ? t[li[z].l[i]][temp] : t[ls][t2]) + t[li[z].l[i]][temp];
		}
		vis[z] = 1;
		if (temp > 1)
		{
			dfs(a[li[z].l[i]][check(z,li[z].l[i]) - 1], li[z].l[i], ttime);
			shifoufanhui = 0;
		}
		if (temp < k[li[z].l[i]]) 
		{
			dfs(a[li[z].l[i]][check(z,li[z].l[i]) + 1], li[z].l[i], ttime);
			shifoufanhui = 0;
		}
		vis[z] = 0;
	}
	if (shifoufanhui)
	{
		return; 
	}
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; ++j)
		{
			cin >> a[i][j] >> t[i][j];
			li[a[i][j]].l[++stcur[a[i][j]]] = i;
		}
	}
	while (q--)
	{
		cin >> xr >> yr;
		dfs(xr, 0, 0);
		cout << ans << "\n";
		ans = 0;
	}
	return 0;
}
