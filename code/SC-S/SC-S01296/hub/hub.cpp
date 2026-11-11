#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int MAXN = 1e6 + 5;
int c;
struct Solution2
{
	void dfs(vector<vector<int> >& g,vector<int>& dp,int& ans,int u,int fa)
	{
		for(auto v : g[u])
		{
			if(v == fa)
				continue;
			dfs(g,dp,ans,v,u);
			ans = max(ans,dp[u] + dp[v] + 1);
			dp[u] = max(dp[u],dp[v] + 1);
		}
	}
	void Solve()
	{
		int n,k;
		cin >> n >> k;
		vector<vector<int> > g(n + 1);
		vector<int> dp(n + 1,0);
		for(int i = 1,u,v;i < n;i++)
		{
			cin >> u >> v;
			g[u].emplace_back(v),g[v].emplace_back(u);
		}
		int ans = 0;
		dfs(g,dp,ans,1,0);
		cout << (ans - 1) / (k + 1) + 1 << '\n';
	}
	Solution2()
	{
		int T;
		cin >> T;
		while(T--)
			Solve();
	}
};
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
	cin >> c;
	Solution2();
}