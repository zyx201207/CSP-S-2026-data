#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e6 + 10;

int n, k;
int dis[N];
bool st[N];
vector<int> vec[N];

void dfs(int u, int fa, int s)
{
	st[u] = 1;
	for (auto v : vec[u] )
	{
		if ( v == fa ) continue;
		if ( ((s >> (v - 1)) & 1)) dfs(v, u, s);
	}
}

int bfs(int s, int t)
{
	for (int i = 1; i <= n; i ++ ) dis[i] = 1e9;
	for (int i = 1; i <= n; i ++ ) st[i] = 0;
	dis[s] = 0;
	queue<int> q;
	q.push(s);
	while ( !q.empty() )
	{
		int u = q.front();
		q.pop();
		
		if ( st[u]) continue;
		st[u] = true;
		
		for (auto v : vec[u] )
			if ( dis[v] > dis[u] + 1 ) 
			{
				dis[v] = dis[u] + 1;
				q.push(v);
			}
	}
	return dis[t];
}

void solve()
{
	cin >> n >> k;
	
	for (int i = 1; i <= n; i ++ ) vec[i].clear();
	
	for (int i = 1; i < n; i ++ )
	{
		int u, v;
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	int ans = 1e9;
	for (int s = 0; s < (1 << n); s ++ )
	{
		int o = __builtin_popcount(s);
		if ( o != k ) continue;
		int cnt = 0;
		for (int i = 1; i <= n; i ++ )
			if ( ((s >> (i - 1)) & 1) && !st[i])
			{
				cnt ++;
				dfs(i, 0, s);
			}
		if ( cnt > 2 ) continue;

		int d = 0;
		for (int j = 1; j <= n; j ++ )
		{
			if ( ((s >> (j - 1)) & 1) == 0 ) continue;
			for (int i = 1; i <= n; i ++ )
			{
				if ( ((s >> (i - 1)) & 1) ) continue;
				else d = max(d, bfs(i, j));
			}
			ans = min(ans, d);
			d = 0;
		}
	}
	
	cout << ans << "\n";
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);

	int c, t;
	cin >> c >> t;
	while (t -- ) solve();
	
	return 0;
}
