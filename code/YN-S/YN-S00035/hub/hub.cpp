// File Memory Longlong Calm

#include <bits/stdc++.h>

const int N = 1e6 + 10;

using namespace std;

vector<int> G[N];
int n, k, ans;
int vis[N], flg[N], dis[N];
int u[N], v[N];

void solve(int u)
{
	flg[u] = 1;
	for(int v : G[u]) if(!flg[v]) solve(v);
}

void solve2(int u, int pre = 0)
{
	if(dis[pre] + 1 < dis[u])
	{
		dis[u] = dis[pre] + 1;
		for(int v : G[u]) solve2(v, u);
	}
}

bool check()
{
	int ans = 0;
	for(int i = 1; i <= n; i++) G[i].clear(), flg[i] = 0;
	for(int i = 1; i < n; i++) if(vis[u[i]] && vis[v[i]])
	{
		G[u[i]].push_back(v[i]);
		G[v[i]].push_back(u[i]);
	}
	for(int i = 1; i <= n; i++) if(vis[i] && !flg[i]) ans++, solve(i);
	return ans <= 2;
}

int calc()
{
	dis[0] = -1;
	for(int i = 1; i <= n; i++) G[i].clear(), dis[i] = 1e9;
	for(int i = 1; i < n; i++)
	{
		G[u[i]].push_back(v[i]);
		G[v[i]].push_back(u[i]);
	}
	for(int i = 1; i <= n; i++) if(vis[i]) solve2(i);
	int ans = 0;
	for(int i = 1; i <= n; i++) ans = max(ans, dis[i]);
	return ans;
}

void baoli(int step, int cnt = 0)
{
	if(step == n + 1)
	{
		if(cnt == k && check()) ans = min(ans, calc());
		return;
	}
	vis[step] = 1;
	if(cnt + 1 <= k) baoli(step + 1, cnt + 1);
	vis[step] = 0;
	baoli(step + 1, cnt);
}

int Maxid, Max;
int pre[N];
void dfs(int u, int fa, int dep = 0)
{
	pre[u] = fa;
	if(dep >= Max) Max = dep, Maxid = u;
	for(int v : G[u]) 
	{
		if(v != fa) dfs(v, u, dep + 1);
	}
}

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int c, T;
	scanf("%d %d", &c, &T);
	while(T--)
	{
		ans = 1e9;
		for(int i = 1; i <= n; i++) G[i].clear();
		scanf("%d %d", &n, &k);
		for(int i = 1; i < n; i++)
		{
			scanf("%d %d", &u[i], &v[i]);
			G[u[i]].push_back(v[i]);
			G[v[i]].push_back(u[i]);
		}
		if(k != 2) baoli(1);
		else
		{
			Max = 0; dfs(1, 0);
			Max = 0; dfs(Maxid, 0);
			vector<int> res;
			while(Maxid != 0)
			{
				res.push_back(Maxid);
				Maxid = pre[Maxid];
			}
			int len = res.size();
			int p1 = len / 4, p2 = len / 4 * 3;
			if(len <= 3) p1 = 0, p2 = len-1;
			for(int dx = -1; dx <= 1; dx++) for(int dy = -1; dy <= 1; dy++)
			{
				if(p1 + dx >= 0 && p1 + dx < len && p2 + dy >= 0 && p2 + dy < len)
				{
					for(int i = 1; i <= n; i++) vis[i] = 0;
					vis[res[p1 + dx]] = 1;
					vis[res[p2 + dy]] = 1;
//					printf("%d %d %d\n", res[p1 + dx], res[p2 + dy], calc());
					ans = min(ans, calc());
				}
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
