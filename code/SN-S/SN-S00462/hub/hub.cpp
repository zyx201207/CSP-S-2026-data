// SN-00462 µ­³þÜ² ¸¨ÂÖÖÐÑ§ 
#include <bits/stdc++.h>
#define il inline
#define int long long
#define vc vector
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

const int N = 1e6 + 5, inf = 1e9;
int TTT = 1, c, n, m, k, id, ans = inf, d[N], vis[N], f[N];
vc<int> e[N];

int find(int x) {return (f[x] == x ? x : f[x] = find(f[x]));}

void dfs(int x, int t)
{
	if(x > n)
	{
		queue <int> q;
		for(int i = 1; i <= n; i++) d[i] = inf;
		for(int i = 1; i <= n; i++) if(vis[i]) q.push(i), d[i] = 0;
		for(int i = 1; i <= n; i++) f[i] = i;
		for(int i = 1; i <= n; i++)
		{
			for(int j : e[i])
			{
				if(vis[i] && vis[j])
				{
					int x = find(i), y = find(j);
					f[x] = y;
				}
			}
		}
		int nw = 0;
		for(int i = 1; i <= n; i++) if(vis[i] && find(i) == i) nw++;
		if(nw != 2) return;
		
		int mx = 0;
		while(!q.empty())
		{
			int u = q.front(); q.pop(); mx = max(mx, d[u]);
			for(int v : e[u]) if(d[v] == inf) d[v] = d[u] + 1, q.push(v);
		}
//		if(mx == 1)
//		{
//			for(int i = 1; i <= n; i++) cout << d[i] << " ";
//			cout << "\n";
//		}
		ans = min(ans, mx);
		return;
	}
	
	if(t < m) vis[x] = 1, dfs(x + 1, t + 1), vis[x] = 0;
	if(n - x + t >= m) dfs(x + 1, t);
}



void mian()
{
	cin >> n >> m;  id = 0; ans = inf;
	for(int i = 1; i <= n; i++) e[i].clear();
	for(int i = 1, u, v; i < n; i++) cin >> u >> v, e[u].pb(v), e[v].pb(u);
	dfs(1, 0); cout << ans << "\n";
}

/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/

signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> c >> TTT;
	while(TTT--) mian();
	return 0;
}
