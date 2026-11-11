#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int c , t , n , k , step[105] , minn;
vector <int> G[N];
bool f[105] , f1[105];
int popcount(int x)
{
	int res = 0;
	while (x)
	{
		if  (x & 1) ++ res;
		x >>= 1;
	}
	return res;
}
void dfs(int u , int f)
{
	f1[u] = 1;
	for (int i = 0;i < int(G[u].size());i ++)
	{
		int v = G[u][i];
		if  (v == f) continue;
		dfs(v , u);
	}
}
queue <int> q;
void bfs()
{
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0;i < int(G[u].size());i ++)
		{
			int v = G[u][i];
			if (f[v])
			{
				minn = min(minn , step[u] + 1);
				return;
			}
			else if (!step[v])
			{
				step[v] = step[u] + 1;
				q.push(v);
			}
		}
	}
}
void solve()
{
	cin >> n >> k;
	for (int i = 1;i <= n;i ++) G[i].clear();
	for (int u , v , i = 1;i < n;i ++)
	{
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if  (n == k)
	{
		cout << 0 << "\n";
		return;
	}
	/*
	if  (c == 13 || c == 14)
	{
		int m = (n - 1) / 2;
		cout << 
	}
	*/
	if  (c <= 3)
	{
		for (int i = 1;i < (1 << n);i ++)
		{
			memset(f , 0 , sizeof(f));
			memset(f1 , 0 , sizeof(f1));
			if  (popcount(i) == k)
			{
				for (int j = 0;j < n;j ++)
				{
					if  ((i >> j) & 1) 
						f[j] = 1;
				}
			}
			int cnt = 0;
			for (int i = 1;i <= n;i ++)
				if  (f[i] && !f1[i])
					dfs(i , 0), ++ cnt;
			if  (cnt > 2)
				continue;
			minn = 1e5;
			for (int i = 1;i <= n;i ++)
				if  (!f[i])
				{
					memset(step , 0 , sizeof(step));
					q.push(i);
					bfs();
					while (!q.empty()) q.pop();
				}
		}
		cout << minn << "\n";
		return;
	}
}
int main()
{
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t;
	while (t --) solve();
	return 0;
}
