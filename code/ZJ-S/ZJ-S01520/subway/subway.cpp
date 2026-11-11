#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 510, M = 1e7 + 10;
int c, n, m, d, q;
int a[N];
int h[N], e[M], w[M], ne[M], idx;
int st[N];
void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
long long dfs(int u, int t, long long dist)
{
	if(u == t) return dist;
	long long res = 0x3f3f3f3f3f3f3f3f;
	st[u] = true;
	for(int i = h[u]; ~i; i = ne[i])
	{
		int v = e[i];
		if(st[v]) continue;
		res = min(res, dfs(v, t, dist + 1ll * w[i]));
	}
	st[u] = false;
	return res;
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	memset(h, -1, sizeof h);
	for(int i = 1; i <= m; i ++)
	{
		cin >> a[i];
		add(i, i + m, a[i]);
		add(i + m, i, a[i]);
	}
	int sum = 1 + m * 2;
	for(int i = 1; i <= n; i ++)
	{
		int k;
		cin >> k;
		for(int j = 1; j <= k; j ++)
		{
			int a, c;
			cin >> a >> c;
			add(sum, a, c), add(a, sum, c);
		}
		sum ++;
	}
	while(q --)
	{
		int x, y;
		cin >> x >> y;
		for(int i = 1; i <= sum; i ++) st[i] = false;
		cout << dfs(x + m, y + m, 1ll * 0) << endl;
	}
	return 0;
}
