#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
const int INF = 0x3f3f3f3f;

int n = 0;
int k = 0; 

int res = 0;

vector<int> vlist[N];

int flg[N];

int vis[N];

int dist[N];

queue<int> qlist;

void dfs1(int x)
{
	int y = 0;
	
	for(int i = 0; i < vlist[x].size(); i++)
	{
		y = vlist[x][i];
		
		if(flg[y] == 0)
		{
			continue;
		}
		
		if(vis[y] == 1)
		{
			continue;
		}
		
		vis[y] = 1;
		
		dfs1(y);
	}
	
	return;
}

int bfs(int root)
{
	int x = 0;
	int y = 0;
	
	memset(dist, 0x3f, sizeof(dist));
	
	while(!qlist.empty())
	{
		qlist.pop();
	}
	
	qlist.push(root);
	
	dist[root] = 0;
	
	while(!qlist.empty())
	{
		x = qlist.front();
		qlist.pop();
		
		for(int i = 0; i < vlist[x].size(); i++)
		{
			y = vlist[x][i];
			
			if(dist[y] != INF)
			{
				continue;
			}
			
			dist[y] = dist[x] + 1;
			
			if(flg[y] == 1)
			{
				return dist[y];
			}
			
			qlist.push(y);
		}
	}
	
	return 0;
}

void sol()
{
	int cnt = 0;
	int max_d = 0;
	int d = 0;
	
	memset(vis, 0, sizeof(vis));
	
	for(int i = 1; i <= n; i++)  
	{
		if(vis[i] == 0
		&& flg[i] == 1)
		{
			cnt++;
			
			dfs1(i);
			
			if(cnt > 2) // 连通块 至多两个
			{
				return;
			}
		}
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(flg[i] == 1)
		{
			continue;
		}
		
		d = bfs(i);
		
		max_d = max(max_d, d);
	}
	
	res = min(res, max_d);
	
	return;
}

void dfs(int idx, int cnt) // 选 k 个 
{
	if(cnt == k + 1)
	{
		sol();
		
		return;
	}
	
	if(idx == n + 1)
	{
		return;
	}
	
	for(int i = idx + 1; i <= n; i++)
	{
		if(flg[i] == 1)
		{
			continue;
		}
		
		flg[i] = 1;
		
		dfs(i, cnt + 1);
		
		flg[i] = 0;
	}
	
	return;
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);  
	
	int c = 0;
	int t = 0;
	
	int u = 0;
	int v = 0;
	
	cin >> c >> t;
	
	while(t--)
	{
		cin >> n >> k;
		
		for(int i = 1; i <= n; i++)
		{
			vlist[i].clear();
		}
		
		for(int i = 1; i <= n - 1; i++)
		{
			cin >> u >> v;
			
			vlist[u].push_back(v);
			vlist[v].push_back(u);
		}
		
		res = INF;
		
		dfs(0, 1);
		
		cout << res << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
