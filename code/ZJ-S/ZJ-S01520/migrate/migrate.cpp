#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 1e4 + 10, M = 1e7 + 10;
int n, d;
int a[N];
int h[N], e[N], ne[N], idx;
bool st[N];
void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
PII dfs(int u, int t, int dist)
{
	if(u == t) return {1, dist};
	int s = 0;
	int len = 0x3f3f3f3f;//
	st[u] = true;
	for(int i = h[u]; ~i; i = ne[i])
	{
		int v = e[i];
		if(v > t || st[v]) continue;
		PII x = dfs(v, t, dist + 1);
		if(x.second < len) len = x.second, s = x.first;
		else if(x.second == len) s += x.first;
	}
	st[u] = false;
	return {s, len};
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t --)
	{
		memset(h, -1, sizeof h);
		memset(e, 0, sizeof e);
		memset(ne, 0, sizeof ne);
		memset(st, 0, sizeof st);
		idx = 0;
		int n, d;
		cin >> n >> d;
		int x = 1;
		cin >> a[1];
		for(int i = 2; i <= n; i ++)
		{
			cin >> a[i];
			while(a[i] - a[x] > d) x ++;
			if(i != x)
			{
				for(int j = x; j < i; j ++) add(j, i);
			}
		}
		long long ans = 0;
		for(int i = 1; i <= n; i ++)
			for(int j = i + 1; j <= n; j ++)
			{
				memset(st, 0, sizeof st);
				PII x = dfs(i, j, 0);
				if(x.first == 2) ans ++;
			}
		cout << ans << endl;
	}
	return 0;
}
