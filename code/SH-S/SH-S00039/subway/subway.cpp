#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int> 
const int N = 555;
const int M = 5e5 + 10;
struct Node{
	int x, t;
}e[2 *M];
int c, n, m, d, q1, w[M], ans;
priority_queue<pii, vector<pii>, greater<pii> >q;
vector<int >g[N];

void dfs(int s)
{
	
}
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >>q1;
	for(int i = 1; i <= m; ++i)
	{
		cin >> w[i];
	}
	for(int i = 1; i <= n; ++i)
	{
		int k;
		cin >> k;
		for(int j = 1; j <= k; ++j)
		{
			cin >> e[j].x >> e[j].t;
		}
		for(int j = 1; j <= k; ++j)
		{
			for(int t = 1; t <= k; t++)
			{
				g[e[j].x].push_back(e[t].x);
				g[e[t].x].push_back(e[j].x);
				g[j][t] = e[j].t + e[t].t;
			}
		}
	}
	for(int i = 1; i <= q1; ++i)
	{
		int u, v;
		cin >> u >> v;
		ans = w[u] + w[v];
	}
	
	return 0;
}
