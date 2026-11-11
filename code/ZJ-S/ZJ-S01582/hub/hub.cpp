#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, M = 2 * N;
int c, t;
int n, k;
int h[N], e[M], ne[M], idx;
void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
int dist[N];
bool st[N];
void dfs(int u, int father)
{
	dist[u] = 1;
	for(int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if(st[j]) continue;
		st[j] = true;
		if(j == father) continue;
		if(dist[i] < dist[j] + 1)
		{
			dist[i] = dist[j] + 1
			dfs(j, i)
		}
	}
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t --)
	{
		cin >> n >> k;
		memset(h, -1, sizeof h);
		for(int i = 1; i < n; i ++)
		{
			int a, b;
			add(a, b), add(b, a);
		}
		if(k == 1)
		{
			int ans = 0;
			for(int i = 1; i <= n; i ++)
				dfs(i, 0)
			for(int i = 1; i <= n; i ++)
				ans = max(ans, dist[i]);
			cout << ans << endl;
		}
	}
	return 0;
}
