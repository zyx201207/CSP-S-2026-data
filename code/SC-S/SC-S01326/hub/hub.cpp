#include <bits/stdc++.h>
using namespace std;

queue<int> q; 
vector<int> g[4005];
int n, k;
int dis[4005];
bool used[4005];
int p[4005];
bool vis[4005];
bool vis2[4005];
int ans = 1e9;

void bfs(int st)
{
	for(int i = 1;i <= n;i++)
		vis[i] = 0;
	q.push(st);
	vis[st] = 1;
	while(q.size())
	{
		int u = q.front();
		q.pop();
		for(auto v : g[u])
		{
			if(used[v] && !vis[v])
			{
				vis[v] = 1;
				q.push(v);
			}
		}
	}
}

void bfs2()
{
	for(int i = 1;i <= n;i++)
	{
		dis[i] = 1e9;
		vis2[i] = 0;
	}
	for(int i = 1;i <= k;i++)
	{
		dis[p[i]] = 0;
		q.push(p[i]);
	}
	
	while(q.size())
	{
		int u = q.front();
		q.pop();
		for(auto v : g[u])
		{
			if(!vis2[v] && dis[u] + 1 < dis[v])
			{
				vis2[v] = 1;
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		} 
	}
	
	int now = -1e9;
	for(int i = 1;i <= n;i++)
		now = max(now, dis[i]);
	ans = min(ans, now);
}

void check()
{
	bfs(p[1]);
	for(int i = 1;i <= k;i++)
		if(!vis[p[i]])
		{
			bfs(p[i]);
			break;
		}
	for(int i = 1;i <= k;i++)
		if(!vis[p[i]])
			return ;
	
	bfs2();
}

void dfs(int now)
{
	if(now == k + 1)
	{
		check();
		return ;
	}
	
	for(int i = 1;i <= n;i++)
		if(!used[i])
		{
			used[i] = 1;
			p[now] = i;
			dfs(now + 1);
			used[i] = 0;
		}
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int C, t;
	scanf("%d %d", &C, &t);
	while(t--)
	{
		scanf("%d %d", &n, &k);
		for(int i = 1;i < n;i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1);
		printf("%d\n", ans);
	} 
	return 0;
}
