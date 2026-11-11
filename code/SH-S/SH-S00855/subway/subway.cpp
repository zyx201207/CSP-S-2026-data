#include <bits/stdc++.h>
using namespace std;
#define intl long long
const intl INF = 1e17;
intl q, c, n, m, d, w[510], k[510], snext[100010][510], sprev[100010][510], t[100010][510], ans;
bool vis[100010];
intl dfs(int cur, int l, int des)
{
	if(vis[cur]) return INF;
	if(cur == des) return t[des][l];
	vis[cur] = true;
	intl res = INF, back;
	for(int i = 1; i <= n; ++i)
	{
		back = dfs(sprev[cur][i], i, des);
		if(l != i) back += t[cur][l] + t[cur][i];
		res = min(res, back);
		back = dfs(snext[cur][i], i, des);
		if(l != i) back += t[cur][l] + t[cur][i];
		res = min(res, back);
	}
	vis[cur] = false;
	return res;
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++i) cin >> w[i];
	for(int i = 1; i <= n; ++i)
	{
		cin >> k[i];
		int a = 0, p = 0;
		for(int j = 1; j <= k[i]; ++j)
		{
			p = a;
			cin >> a;
			sprev[a][i] = p;
			snext[p][i] = a;
			cin >> t[a][i];
		}
	}
	vis[0] = true;
	int x, y;
	while(q--)
	{
		cin >> x >> y;
		cout << (w[x] + w[y] + dfs(x, 0, y)) << '\n';
	}
	return 0;
}
