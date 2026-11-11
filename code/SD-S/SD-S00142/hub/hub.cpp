#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;
const int MAXN = 4e3 + 5;
int c, T, n, k;
bool vis[MAXN], r[MAXN];
vector <int> adj[MAXN];
int solve(int x)
{
	int res = 0;
	while(x)
	{
		if(x & 1)
		{
			res++;
		}
		x >>= 1;
	}
	return res;
}
void bfs1(int s)
{
	priority_queue <int> q;
	q.push(s);
	vis[s] = true;
	while(!q.empty())
	{
		int u = q.top();
		q.pop();
		for(int v : adj[u])
		{
			if(vis[v] || !r[v])
			{
				continue;
			}
			q.push(v);
			vis[v] = true;
		}
	}
	return ;
}
bool check(int x)
{
	for(int i = 1; i <= n; i++)
	{
		r[i] = false;
		vis[i] = false;
		if((x >> (i - 1)) & 1)
		{
			r[i] = true;
		}
	}
	int res = 0;
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i] && r[i])
		{
			bfs1(i);
			res++;
		}
	}
	return (res <= 2 && res);
}
int bfs2(int s)
{
	priority_queue <pair <int, int> > q;
	q.push({s, 0});
	vis[s] = true;
	while(!q.empty())
	{
		int u = q.top().first;
		int step = q.top().second;
		q.pop();
		for(int v : adj[u])
		{
			if(vis[v])
			{
				continue;
			}
			if(r[v])
			{
				return (step + 1);
			}
			q.push({v, step + 1});
			vis[v] = true;
		}
	}
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	scanf("%d%d", &c, &T);
	while(T--)
	{
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i++)
		{
			adj[i].clear();
		}
		for(int i = 1, u, v; i < n; i++)
		{
			scanf("%d%d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int ans = n;
		for(int i = 0; i <= (1 << n); i++)
		{
			int kk = solve(i);
			if(kk != k)
			{
				continue;
			}
			if(!check(i))
			{
				continue;
			}
			int ls = 0;
			for(int j = 1; j <= n; j++)
			{
				if(!((i >> (j - 1)) & 1))
				{
					for(int i = 1; i <= n; i++)
					{
						vis[i] = false;
					}
					ls = max(ls, bfs2(j));
				}
			}
			ans = min(ans, ls);
		}
		printf("%d\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
// 18:11 12pts 做法出了（其实可能会更高），不打了真累死了
// 18:12 最终总分（最少，实际最大可能会向上浮动 20？）：100 + 40 + 8 + 12 = 160.（极限卡 1=）
// rp+++++++++++++++++++++++++++++++++++++++++++++; 
