#include<bits/stdc++.h>
using namespace std;
struct node
{
	int u, dis;
};
int c, t;
int n, k;
int u, v;
int ans;
//int dp[105][105][105];
bool vis[105];
bool f[105];
vector<int> e[105];
int bfs(int s)
{
	queue<node> q;
	q.push(node{s, 0});
	memset(vis, 0, sizeof(vis));
	vis[s] = true;
	while(!q.empty())
	{
		node now = q.front();
		vis[now.u] = true;
		if(f[now.u]) return now.dis;
		q.pop();
		for(int i = 0; i < (int)(e[now.u].size()); i ++)
		{
			int v = e[u][i];
			if(vis[v]) continue;
			q.push(node{v, now.dis + 1});
		}
	}
	return 0;
}
void dfs(int step, int cnt)
{
	if(cnt > k) return;
	if(step > n)
	{
		if(cnt == k)
		{
			int maxn = 0;
			for(int i = 1; i <= n; i ++)
			{
				maxn = max(maxn, bfs(i));
			}
			ans = min(ans, maxn);
		}
		return;
	}
	f[step] = true;
	dfs(step + 1, cnt + 1);
	f[step] = false;
	dfs(step + 1, cnt);
	return;
}
//void dfs(int u, int fa)
//{
//	for(int i = 0; i < (int)(e[i].size()); i ++)
//	{
//		int v = e[u][i];
//		if(v == fa) continue;
//		for(int j = 1; j <= k; j ++)
//		{
//			
//		}
//		dfs(v, u);
//	}
//	return;
//}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t --)
	{
		memset(f, 0, sizeof(f));
		ans = 1e9;
		cin >> n >> k;
		for(int i = 1; i < n; i ++)
		{
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1, 0);
		cout << ans << endl;
	}
	return 0;
}
