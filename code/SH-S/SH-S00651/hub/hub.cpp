#include<bits/stdc++.h>
using namespace std;

int c, t;
int n, k; 
const int N = 1e6 + 5;
vector<int> g[N];
int sz[N];
int dp[N];
int depth[N];

void dfs1(int u, int fa)
{
	dp[u] = 1;
	sz[u] = 1;
	depth[u] = depth[fa] + 1;
	for(int i = 0; i < g[u].size(); i++)
	{
		int v = g[u][i];
		if(v == fa) continue;
		dfs1(v, u);
		dp[u] = max(dp[u], dp[v] + 1);
		sz[u] += sz[v];
	}
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i = 1; i < n; i++)
		{
			int u, v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs1(1, 0);
		int tmp = 0;
		for(int i = 1; i <= n; i++)
		{
			if(depth[i] > depth[tmp]) tmp = i;
		}
		memset(depth, 0, sizeof depth);
		dfs1(tmp, 0);
		tmp = 0;
		for(int i = 1; i <= n; i++)
		{
			if(depth[i] > depth[tmp]) tmp = i;
		}
		int deep = depth[tmp];
		cout<<(deep - (k - 1) + 1) / 2 - 1<<endl;
	}
	return 0;
}

